#pragma once
#include "Matricula.h"
#include"Curso.h"
#include "Estudiantes.h"
#include "Profesor.h"

class Contenedor_Matrícula
{
private:
	vector< Matricula> matriculas;
	const vector<Curso*>& listaCursos;
	const vector<Profesor*>&lista;
	const vector<Estudiantes*>& ListaEstudiante;

	
public:
	
	// constructor que recibe por parametros la referencia del vector de cursos,profesores y estudiantes y los asigna a los vectores de referencia
	Contenedor_Matrícula(const vector<Curso*>& _listaCursos, const vector<Profesor*>& _lista, const vector<Estudiantes*>& _ListaEstudiante) : listaCursos(_listaCursos), lista(_lista),ListaEstudiante(_ListaEstudiante){}



	void mostrarBarraDeCarga()
	{
		const int longitudBarra = 30; // Ajusta la longitud de la barra de carga
		cout << "Procesando: " << endl;

		for (int i = 0; i <= 100; ++i)
		{
			int pos = longitudBarra * i / 100;

			// Rellena la barra de progreso
			for (int j = 0; j < longitudBarra; ++j)
			{
				if (j < pos)
					cout << "_""-";
				else if (j == pos)
					cout << " ";
				else
					cout << " ";
			}

			cout << i << " %\r";
			cout.flush();

			// Simula un tiempo de espera
			this_thread::sleep_for(chrono::milliseconds(15)); // Ajusta la velocidad de la barra de carga aquí
		}


	}

	void AgregarMatricula()
	{
		
			
		if (lista.empty() || listaCursos.empty() || ListaEstudiante.empty())
		{
			cout << "\nNo hay Suficientes Datos para Generar una Matrícula...\n";
		}

		else
		{

			string id_Est; long long _est;
			string id_Prof; long long _profe;
			string fecha;
			bool estudiante = false;
			bool matriculaEncontrada = false;
			while (true)
			{
				cout << "\nIngrese Número de Cédula del Estudiante: ";
				cin >> _est;
				if (cin.fail() || _est <= 0)
				{
					cin.clear();; //limpia el cin
					cout << "\nNúmero de Cédula Inválido...";
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); //verifica que no se puedan poner saltos de linea y evita que se caiga el programa cuando ingresan algo que no sea un numero
				}
				else
				{
					id_Est = to_string(_est);
					if (id_Est.length() > 15)
					{
						cin.clear(); //limpia el cin
						cout << "\nNúmero de Cédula Inválido...";
					}
					else
					{
						break;
					}
				}
			}
			// verificacion cedula del estudiante

			for (int i = 0; i < ListaEstudiante.size(); i++)
			{
				if (ListaEstudiante[i]->getCedula() == id_Est)
				{
					estudiante = true;
				}
			}
			// final for verificar que las cedulas coincidan

			if (!estudiante)
			{
				cout << "\nEstudiante no Existente...\n";
			}
			// si el estudiante existe continua pidiendo datos...
			else
			{
				again:
				bool profesor = false;
				while (true)
				{
					cout << "\nIngrese Número de Cédula del Profesor: ";
					cin >> _profe;
					if (cin.fail() || _profe <= 0)
					{
						cin.clear(); //limpia todo lo ingresado en el cin
						cout << "\nNúmero de Cédula Inválido...";
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); //en caso que quieran poner un salto de linea y evita que se caiga el programa cuando ingresan algo que no sea un numero
					}
					else
					{
						id_Prof = to_string(_profe);
						if (id_Prof.length() > 10) //para que no se pase de 10 digitos
						{
							cin.clear(); //limpia el cin
							cout << "\nNúmero de Cédula Inválido...";
						}
						else
						{
							break;
						}
					}
				}
				//fin del while

				bool find = false;

				for (int i = 0; i < lista.size(); i++)
				{
					if (lista[i]->getCedula() == id_Prof) //verifica que el profesor exista
					{
						for (int j = 0; j < matriculas.size(); j++)
						{
							for (int k = 0; k < ListaEstudiante.size(); k++)
							{
								if (ListaEstudiante[k]->getCedula() == id_Est && matriculas[j].getId_Prof() == id_Prof) //verifica que no se matricule el mismo curso
								{
									cout << "\nCurso ya Matriculado Previamente....\n";
									system("pause");
									goto again;
								}

								else if (ListaEstudiante[k]->getCedula() == id_Est && matriculas[j].getId_Prof() == id_Prof && matriculas[j].getEstado() == false) //en caso de que quiera volver a matricular el curso despues de cancelada la matricula
								{
									otro:
										bool encuentra = false;
										string validar;
										cout << "El curso has sido cancelado anteriormente desea matricularlo de nuevo? \n";
										cout << "Escriba si o no: ";
										cin.ignore(); getline(cin, validar);
										for (char& c : validar) { c = tolower(c); } //convierte todo a minusculas
										if (validar == "si")
										{
											encuentra = true;
											matriculas[j].setEstadoDeNuevo();
											matriculas[j].setFechaC(" ");
											for (int q = 0; q < listaCursos.size(); q++) 
											{ 
												if (listaCursos[q]->getCodigo() == lista[i]->getcodigoCurso() && lista[i]->getCedula() == id_Prof) 
												{
													listaCursos[q]->setDisminuirCupo(); // Quita un cupo 

												} 

											}
											goto listo;
										}
										else if(validar == "no")
										{
											goto again;
											cin.clear(); //limpia el cin
										}
										else
										{
											cout << "Ingrese una opcion valida\n";
											cin.clear();
											cin.ignore(numeric_limits<streamsize>::max(), '\n');  //evita que se caiga el programa cuando ingresan algo que no sea un numero
											goto otro;
										}
								}

								
							} // for lista estudiante

						}// for matricula
						
						for (int o = 0; o < listaCursos.size(); o++)
						{
							if (listaCursos[o]->getCupo() == 0) //verifica si el curso esta lleno
							{
								cout << "\nCurso lleno...\n";
								system("pause");
								goto again;
								
							}
						}//for lista cursos
						find = true;
						string confirmación;
						system("cls");
						cout << "Está seguro de realizar la matricula ?\n";
						cout << "Si es asi confirme con si\n";
						cout << "Sino presione cualquier letra\n";
						cin >> confirmación;
						for (char& c : confirmación) { c = tolower(c); } //convierte todo a minusculas
						if (confirmación == "si")
						{
							// Obtener la hora actual
							auto currentTime = chrono::system_clock::now();

							// Convertir la hora actual a un formato de tiempo desde el epoch (1 de enero de 1970)
							time_t currentTimeT = chrono::system_clock::to_time_t(currentTime);

							// Crear una estructura tm para almacenar la fecha y hora local
							tm timeInfo;

							// Obtener fecha y hora local de forma segura
							localtime_s(&timeInfo, &currentTimeT);

							// Crear un flujo de salida de string
							ostringstream oss;

							// Formatear y mostrar la fecha y hora actual
							oss << put_time(&timeInfo, "%Y-%m-%d %H:%M:%S");

							// Convertir el flujo de salida a un string
							fecha = oss.str();

							Matricula NuevaMatricula(id_Est, id_Prof, fecha, true, "");
							matriculas.push_back(NuevaMatricula);
							for (int q = 0; q < listaCursos.size(); q++)
							{
								if (listaCursos[q]->getCodigo() == lista[i]->getcodigoCurso() && lista[i]->getCedula() == id_Prof)
								{
									listaCursos[q]->setDisminuirCupo(); // Quita un cupo
								}
								
							}
							mostrarBarraDeCarga();
							cout << "\n\033[1;32mMatricula agregada correctamente\n\033[0m";
							
							system("pause");
							
							
						} // fin confirmacion de matricula

					} // final if lista

				} // for profesores
				if (!find)
				{
					cout << "\nNo se Pudo encontrar el profesor...\n";
					
				}
				
				
			}// final else
			
		listo:
			system("cls");
			MostrarMatricula();
		
		}
		// final else en caso de que exista algo en todos los vectores

		
	}
	void consultarMatricula()
	{
		if (matriculas.empty())
		{
			cout << "No se han registrado matriculas\n";
		}
		else
		{
			string id;
			bool find = false;

			cout << "Ingrese la cedula del estudiante: ";
			cin >> id;
			system("cls");
			for (int i = 0; i < matriculas.size(); i++)
			{
				if (matriculas[i].getId_est() == id)
				{
					find = true;
					matriculas[i].getMatricula();
					
				}
				
			}
			if (!find)
			{
				cout << "Lo sentimos\n";
				cout << "No existe un estudiante registrado en el sistema con esa cédula\n";
			}
		}
	}
	void MostrarMatricula()
	{
		if (matriculas.empty())
		{
			cout << "No se han registrado matriculas\n";
		}
		else
		{
			system("cls");
			cout << "____LISTA__DE__MATRICULAS_____\n";
			cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
			for (int i = 0; i < matriculas.size(); i++)
			{
				cout << "Matricula #" << i + 1<< endl;
				matriculas[i].getMatricula();
				cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
			}
			
			cout << "Cantidad de matriculas: " << matriculas.size() << endl;
			cout << "_____FIN_DE_LA_LISTA_____\n";
		}
	}
	void CancelarMatricula()
	{
		if (matriculas.empty())
		{
			cout << "No se han registrado matriculas\n";
		}
		else
		{
			int code;
			bool find1 = false;
			string fechaCancelacion;

			cout << "Ingrese el codigo de la matricula que desea cancelar: ";
			cin >> code;

			for (int i=0; i<matriculas.size(); i++)
			{
				if (matriculas[i].getCodigo() == code && matriculas[i].getEstado() == true)
				{
					find1 = true;
					string confirmación;
					system("cls");
					cout << "Está seguro de cancelar la matricula ?\n";
					cout << "Si es asi confirme con si\n";
					cout << "Sino presione cualquier letra\n";
					cin >> confirmación;
					for (char& c : confirmación) { c = tolower(c); } //convierte todo a minusculas
					if (confirmación == "si")
					{
						// Obtener la hora actual
						auto currentTime = chrono::system_clock::now();

						// Convertir la hora actual a un formato de tiempo desde el epoch (1 de enero de 1970)
						time_t currentTimeT = chrono::system_clock::to_time_t(currentTime);

						// Crear una estructura tm para almacenar la fecha y hora local
						tm timeInfo;

						// Obtener fecha y hora local de forma segura
						localtime_s(&timeInfo, &currentTimeT);

						// Crear un flujo de salida de string
						ostringstream oss;

						// Formatear y mostrar la fecha y hora actual
						oss << put_time(&timeInfo, "%Y-%m-%d %H:%M:%S");

						// Convertir el flujo de salida a un string
						fechaCancelacion = oss.str();
						
						matriculas[i].setEstado(); //cambia el estado de matriculada a pendiente
						for (int k = 0; k < lista.size(); k++)
						{
							for (int j = 0; j < listaCursos.size(); j++) {

								if (matriculas[i].getCodigo() == code && lista[k]->getCedula() == matriculas[i].getId_Prof() && listaCursos[j]->getCodigo() == lista[k]->getcodigoCurso())
								{
									listaCursos[j]->setAumentarCupo(); //libera el cupo
								}
							}
						}
						
						mostrarBarraDeCarga();
						matriculas[i].setFechaC(fechaCancelacion); //agrega la fecha de cancelacion
						cout << "\n\033[1;32mMatricula cancelada correctamente\n\033[0m";
						system("pause");
						system("cls");
						MostrarMatricula();
						
					}
				
				
				}
				
			}
			if (!find1)
			{
				cout << "Lo sentimos\n";
				cout << "No se encontró una matricula con ese codigo\n";
				cout << "O No hay matriculas disponibles para cancelar\n";
			}
		}
	}

	
	void menuMatricula()
	{
		
		
		setlocale(LC_CTYPE, "Spanish");
		int opc;
		do
		{
			
			system("cls");
			cout << "Bienvenido a la seccion de matricula, seleccione una opcion" << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << "1) Para matricular Cursos             \n";
			cout << "2) Para cancelar Matrícula            \n";
			cout << "3) Para consultar Matrículas          \n";
			cout << "4) Para ver Todas las Matrículas      \n";
			cout << "5) Para regresar al Menú Principal    \n"; 
			cout << "--------------------------------------------------------------" << endl; 
			cout << "Seleccione una opción: ";
			cin >> opc;

			switch (opc)
			{
			case 1:
			{
				AgregarMatricula();
		
				system("pause");
				break;
			}
			case 2:
			{
				CancelarMatricula();
				system("pause");
				break;
			}
			case 3:
			{
				consultarMatricula();
				system("pause");
				break;
			}
			case 4:
			{
				MostrarMatricula();
				system("pause");
				break;
			}
			case 5:
			{
				cout << "\nVolviendo al Menú Principal...\n";
				system("pause");
				break;
			}
			default:
			{
				cout << "Ingrese una opción valida.....\n";
				if (cin.fail()) 
				{
					cout << "Solo se permiten numeros\n"; 
					cin.clear(); //limpia el buffer    
				}
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  //evita que se caiga el programa cuando ingresan algo que no sea un numero
				cin.clear(); //limpia el buffer   
				system("pause");
				break;
			}

			}

		} while (opc != 5);


	}

};


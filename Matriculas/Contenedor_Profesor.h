#pragma once
#include "Profesor.h"
#include "Curso.h"

class Contenedor_Profesor {
	private:
		 vector<Profesor*> lista;
		const vector<Curso*>& listaCurso; //vector creado para obtener la información del vector de cursos y asignarla a este
	public:

		// constructor que recibe por parametros la referencia del vector de cursos y lo asigna al vector ya creado
		Contenedor_Profesor(const vector<Curso*>& _listaCurso) : listaCurso(_listaCurso) 
		{}

		const vector<Profesor*>& getVector()const //metodo que retorna el vector de profesores
		{
			return lista;
		}
		
		void agregarProfesor() {

			if (listaCurso.empty())
			{
				cout << "\nNo hay un Cursos para un Profesor...\n";
			}
			else
			{
				bool agregar = false;
	
				long long _cedula;
				int telefono;
				string  cedula, nombre, correo, codigoCurso;

				while (true)
				{
					cout << "\nIngrese Cédula: ";
					cin >> _cedula;

					if (cin.fail() || _cedula <= 0)
					{
						cin.clear(); //limpia el cin
						cout << "\nCédula Inválida...\n";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  //evita que se caiga el programa cuando ingresan algo que no sea un numero
					}
					else
					{
						cedula = to_string(_cedula);
						if (cedula.length() > 10)
						{
							cin.clear(); //limpia el cin
							cout << "\nCédula Inválida...\n";
						}
						else
						{
							break;
							
						}
					}
				} // verificar cedula


				for (int i = 0; i < lista.size(); i++)
				{
					if (lista[i]->getCedula() == cedula)
					{
						agregar = true;
						cout << "Lo sentimos\n";
						cout << " No se permite guardar dos profesores con el mismo código.\n";
					}
				}//comprobacion para que no hayan cedulas repetidos

				if (!agregar)
				{
					while (true)
					{
						cout << "\nIngrese Nombre: ";
						cin.ignore(); getline(cin, nombre);

						if (nombre.empty() || nombre[0] == ' ')
						{
							cout << "\nNombre Inválido...";
							cin.clear(); //limpia el cin
						}

						else
						{
							break;
						}
					}
					// comprobar nombre

					while (true)
					{
						cout << "\nIngrese Número Telefónico: ";
						cin >> telefono;

						if (cin.fail() || telefono <= 0)
						{
							cout << "\nNúmero Inválido...";
							cin.clear(); //limpia el cin
							cin.ignore(numeric_limits<streamsize>::max(), '\n');  //evita que se caiga el programa cuando ingresan algo que no sea un numero
						}
						else
						{
							break;
						}
					}
					// comprobar telefono

					while (true)
					{
						cout << "\nIngrese Correo Electrónico: ";
						cin.ignore(); getline(cin, correo);

						if (correo.empty() || correo[0] == ' ')
						{
							cout << "\nCorreo Inválido...";
							cin.clear(); //limpia el cin
						}
						else
						{
							break;
						}
					}
					// comprobar correo

					bool exito = false;
					
					for (int i = 0; i < listaCurso.size(); i++)
					{
						listaCurso[i]->getDatos(); 
					}
					system("pause");

					while (true)
					{
						cout << "\nIngrese Código del Curso: ";
						getline(cin, codigoCurso);
						for (char c : codigoCurso) { c = toupper(c); } // convierte todo a mayuscula

						if (codigoCurso.empty() || codigoCurso[0] == ' ')
						{
							cout << "\nCódigo Inválido...";
							cin.clear(); //limpia el cin
						}
						else
						{
							break;
						}
					}
					//comprobar codigo curso

					for (int i = 0; i < listaCurso.size(); i++)
					{
						if (listaCurso[i]->getCodigo() == codigoCurso)
						{
							exito = true;
						}
					}
					// verificar que el curso exista

					if (!exito)
					{
						cout << "\nCurso no Existente...\n";
					}
					else
					{

						Profesor* NuevoProfesor = new Profesor(cedula, nombre, telefono, correo, codigoCurso);
						lista.push_back(NuevoProfesor);
						cout << "Profesor agregado correctamente\n";
						system("pause");
						system("cls");
						consultarLista();
						
					} // agrega el curso si existe

				} // ! encontrado final
			}
			// final else
		}

		void actualizarProfesor()
		{
			if (lista.empty())
			{
				cout << "No hay profesores para actualizar" << endl;
			}

			else
			{
				bool encontrado = false;
				string cedula; bool exito = false;
				long long _cedula;

				consultarLista();
				while (true)
				{
					cout << "\nIngrese Cédula: ";
					cin >> _cedula;

					if (cin.fail() || _cedula <= 0)
					{
						cin.clear(); //limpia el cin
						cout << "\nCédula Inválida...\n";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');  //evita que se caiga el programa cuando ingresan algo que no sea un numero
					}
					else
					{
						cedula = to_string(_cedula);
						if (cedula.length() > 15)
						{
							cin.clear(); //limpia el cin
							cout << "\nCédula Inválida...\n";
						}
						else
						{
							break;
						}
					}
				}
				// verificar cedula

				for (int i = 0; i < lista.size(); i++)
				{
					if (cedula == lista[i]->getCedula())
					{
						encontrado = true;
						string nombre, correo, codigoCurso;
						int telefono;

						while (true)
						{
							cout << "\nIngrese Nombre: ";
							cin.ignore(); getline(cin, nombre);

							if (nombre.empty() || nombre[0] == ' ')
							{
								cout << "\nNombre Inválido...";
								cin.clear(); //limpia el cin
							}

							else
							{
								break;
							}
						}
						// comprobar nombre

						while (true)
						{
							cout << "\nIngrese Número Telefónico: ";
							cin >> telefono;

							if (cin.fail() || telefono <= 0)
							{
								cout << "\nNúmero Inválido...";
								cin.clear(); //limpia el cin
								cin.ignore(numeric_limits<streamsize>::max(), '\n');  //evita que se caiga el programa cuando ingresan algo que no sea un numero
							}
							else
							{
								break;
							}
						}
						// comprobar telefono

						while (true)
						{
							cout << "\nIngrese Correo Electrónico: ";
							cin.ignore(); getline(cin, correo);

							if (correo.empty() || correo[0] == ' ')
							{
								cout << "\nCorreo Inválido...";
								cin.clear(); //limpia el cin
							}
							else
							{
								break;
							}
						}
						// comprobar correo

						for (int i = 0; i < listaCurso.size(); i++) 
						{
							listaCurso[i]->getDatos(); 
						}
						system("pause");


						while (true)
						{
							cout << "\nIngrese Código del Curso: ";
							getline(cin, codigoCurso);
							for (char c : codigoCurso) { c = toupper(c); } // convierte todo a mayuscula

							if (codigoCurso.empty() || codigoCurso[0] == ' ')
							{
								cout << "\nCódigo Inválido...";
								cin.clear(); //limpia el cin
							}
							else
							{
								break;
							}
						}
						//comprobar codigo curso

						for (int i = 0; i < listaCurso.size(); i++)
						{
							if (codigoCurso == listaCurso[i]->getCodigo())
							{
								exito = true;
							}
						} // verifica que el curso exista

						if (!exito)
						{
							cout << "\nNo se encontró Ningún Curso...\n";
						}
						else
						{
							lista[i]->actualizarDatos(nombre, telefono, correo, codigoCurso);
							cout << "\nDatos Almacenados con Éxito...\n";
							system("pause");
							system("cls");
							consultarLista();

						}
						// actualiza todos los datos
					} // final if si encuentra cedula
				}
				// verifica que las cedulas coincidan con las del profesor
				if (!encontrado)
				{
					cout << "\nNo se Encontró  ningun profesor...\n";
				}
			} // final else
		}

		void consultarLista() {
			if (lista.empty()) {
				cout << "No hay profesores para mostrar" << endl;
			}
			else {
				system("cls");
				cout << "Lista de profesores" << endl;
				cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
				for (int i = 0; i < lista.size(); i++) {
					cout << "Profesor #" << i + 1 << endl;
					lista[i]->mostrarDatos();
					cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
				}
				
				cout << "Cantidad de porfesores: " << lista.size() << endl;
				cout << "_____FIN_DE_LA_LISTA_____\n";
			}
			
		}

		void guardar(const string& carpeta) {
			ofstream archivo(carpeta.c_str());
			if (archivo.is_open())
			{
				for (int i = 0; i < lista.size(); i++)		//guarda informacion en el archivo txt
				{
					archivo << lista[i]->getCedula() << "-" << lista[i]->getNombre() << "-" << lista[i]->getTelefono() << "-" << lista[i]->getCorreo() << "-" << lista[i]->getcodigoCurso() << endl;
				}
			}
			else
			{
				cout << "No se encontró un archivo para su lectura... \n";
			}
		}

		void cargar(const string& carpeta)
		{
			lista.clear();
			ifstream archivo(carpeta.c_str());
			if (archivo.is_open()) 
			{
				string linea;
				while (getline(archivo, linea))
				{
					stringstream ss(linea);
					string nombre, correo, codigoCurso, codigo, telefono;
					//carga la informacion desde el archivo txt

					 getline(ss,codigo,'-');
			
	
					getline(ss, nombre, '-');

					getline(ss,telefono,'-');
					int _telefono = stoi(telefono);
					
					getline(ss, correo, '-');

					getline(ss,codigoCurso);


					Profesor* datos = new Profesor(codigo, nombre, _telefono, correo, codigoCurso);
					lista.push_back(datos);
				}
				archivo.close();
				cout << "Datos cargados correctamente desde el archivo." << endl;
			}
			else {
				cout << "No se encontró un archivo para su lectura." << endl;
			}
		}

		
		void Menu_Profesor()
		{
			
			setlocale(LC_CTYPE, "Spanish");
			
			string carpeta = "Profesores.txt";
			int opcion;

			do {
				system("cls");
				cout << "Bienvenido a la seccion de profesores, seleccione una opcion" << endl;
				cout << "--------------------------------------------------------------" << endl;
				cout << "1) Para registrar profesores" << endl;
				cout << "2) Para modificar profesores" << endl;
				cout << "3) Para consultar todos los profesores " << endl;
				cout << "4) Para guardar los datos en un archivo" << endl;
				cout << "5) Para recuperar los datos del archivo" << endl;
				cout << "6) Para regresar al Menú Principal     " << endl;
				cout << "--------------------------------------------------------------" << endl; 
				cout << endl << "Ingrese una opción: ";
				cin >> opcion;

				switch (opcion) {
				case 1:
				{
					system("cls");
					cargar(carpeta); //carga los profeosres del archivo txt

					agregarProfesor();
					system("pause");
					break;
				}
				case 2:
				{
					system("cls");
					actualizarProfesor();
					system("pause");
					break;
				}
				case 3:
				{
					system("cls");
					consultarLista();
					system("pause");
					break;
				}
				case 4:
				{
					system("cls");
					guardar(carpeta);
					system("pause");
					break;
				}
				case 5:
				{
					system("cls");
					cargar(carpeta);
					system("pause");
					break;
				}
				case 6:
				{
					system("cls");
					cout << "\nVolviendo al Menú Principal...\n";
					system("pause");
					break;
				}
				default:
				{
					system("cls");
					cout << "Digite una opcion valida" << endl;
					if (cin.fail()) 
					{
						cout << "Solo se permiten numeros\n"; 
						cin.clear(); //limpia el buffer   
					}
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
					cin.clear(); //limpia el buffer   
					system("pause");
					break;
				}
				}
			} while (opcion != 6);
		}
	
};


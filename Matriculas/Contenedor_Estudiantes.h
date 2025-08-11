#pragma once
#pragma once
#include "Librerias.h"
#include "Estudiantes.h"

class Contenedor_Estudiantes {
private:
	vector<Estudiantes*> ListaEstudiante; //vecto de tipo puntero de la clase estudiantes
public:

	
	const vector<Estudiantes*>& getvector()const
	{
		return ListaEstudiante; //retorna el vector
	}

	void AgregarEstudiante()
	{
		string nombre, correo, direccion, cedula;
		int telefono;
		long long _cedula;
		bool encontrado = false;
		while (true)
		{
			cout << "\nIngrese C�dula: ";
			cin >> _cedula;

			if (cin.fail() || _cedula <= 0)
			{
				cin.clear(); //limpia el cin
				cout << "\nC�dula Inv�lida...\n";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  //evita que se caiga el programa cuando ingresan algo que no sea un numero
			}
			else
			{
				cedula = to_string(_cedula);
				if (cedula.length() > 15)
				{
					cin.clear(); //limpia el cin
					cout << "\nC�dula Inv�lida...\n";
				}
				else
				{
					break;
				}
			}
		}
		// verificar cedula

		for (int i = 0; i < ListaEstudiante.size(); i++)
		{
			if (ListaEstudiante[i]->getCedula() == cedula)
			{
				cout << "\nN�mero de C�dula ya Existente...\n";
				encontrado = true;
			}
		}
		// se verifica que las cedula no coincidan

		if (!encontrado)
		{
			while (true)
			{
				cout << "\nIngrese Nombre: ";
				cin.ignore(); getline(cin, nombre);

				if (nombre.empty() || nombre[0] == ' ')
				{
					cout << "\nNombre Inv�lido...\n";
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
				cout << "\nIngrese N�mero de Tel�fono: ";
				cin >> telefono;

				if (cin.fail() || telefono <= 0)
				{
					cin.clear(); //limpia el cin
					cout << "\nN�mero Inv�lido...";
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
				cout << "\nIngrese Correo Electr�nico: ";
				cin.ignore(); getline(cin, correo);

				if (correo.empty() || correo[0] == ' ')
				{
					cout << "\nCorreo Inv�lido...";
					cin.clear(); //limpia el cin
				}
				else
				{
					break;
				}
			}
			// verificar correo

			while (true)
			{
				cout << "\nIngrese Dirreci�n de Domicilio: ";
				cin.ignore(); getline(cin, direccion);

				if (direccion.empty() || direccion[0] == ' ')
				{
					cin.clear(); //limpia el cin
					cout << "\nDirecci�n Inv�lida...";
				}
				else
				{
					break;
				}
			}
			// verificacion direccion

			Estudiantes* Estudiante = new Estudiantes(cedula, nombre, telefono, correo, direccion);
			ListaEstudiante.push_back(Estudiante);
			cout << "\nDatos Almacenados con �xito...\n";

			system("pause");
			system("cls");
			MostrarEstudiantes();
		}
		// final !encontrado
	}

	void ActualizarEstudiante()
	{
		string ced, nombre, correo, direccion;
		long long cedula;
		int telefono;
		bool encontrado = false;

		while (true)
		{
			cout << "\nIngrese N�mero de C�dula: ";
			cin >> cedula;

			if (cin.fail() || cedula <= 0)
			{
				cin.clear(); //limpia el cin
				cout << "\nC�dula Inv�lida...\n";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');  //evita que se caiga el programa cuando ingresan algo que no sea un numero
			}
			else
			{
				ced = to_string(cedula);
				if (ced.length() > 15)
				{
					cout << "\nC�dula Inv�lida...";
					cin.clear(); //limpia el cin
				}
				else
				{
					break;
				}
			}
		}
		// verificar cedula

		for (int i = 0; i < ListaEstudiante.size(); i++)
		{
			if (ced == ListaEstudiante[i]->getCedula())
			{
				encontrado = true;
				while (true)
				{
					cout << "\nIngrese Nombre: ";
					cin.ignore(); getline(cin, nombre);

					if (nombre.empty() || nombre[0] == ' ')
					{
						cout << "\nNombre Inv�lido...";
						cin.clear(); //limpia el cin
					}
					else
					{
						break;
					}
				}
				// verificar nombre

				while (true)
				{
					cout << "\nIngrese Tel�fono: ";
					cin >> telefono;

					if (cin.fail() || telefono <= 0)
					{
						cin.clear(); //limpia el cin
						cout << "\nN�mero Inv�lido...";
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); //evita que se caiga el programa cuando ingresan algo que no sea un numero
					}
					else
					{
						break;
					}
				}
				// verificar telefono

				while (true)
				{
					cout << "\nIngrese Correo Electr�nico: ";
					cin.ignore(); getline(cin, correo);

					if (correo.empty() || correo[0] == ' ')
					{
						cin.clear(); //limpia el cin
						cout << "\nCorreo Inv�lido...";
					}
					else
					{
						break;
					}
				}
				// verificar correo

				while (true)
				{
					cout << "\nIngrese Direcci�n Domiciliar: ";
					cin.ignore(); getline(cin, direccion);

					if (direccion.empty() || direccion[0] == ' ')
					{
						cin.clear(); //limpia el cin
						cout << "\nDirecci�n Inv�lida...";
					}
					else
					{
						break;
					}
				}
				// final verificar dirrecion

				ListaEstudiante[i]->setNombre(nombre);
				ListaEstudiante[i]->setCorreo(correo);
				ListaEstudiante[i]->setTelefono(telefono);
				ListaEstudiante[i]->setDireccion(direccion);
				cout << "\nDatos Actualizados con �xito...";
				system("pause");
				system("cls");
				MostrarEstudiantes();
			}
			// final if
		}
		// final for
		if (!encontrado)
		{
			cout << "\nN�meros de C�dula no coinciden...\n";
		}

	}
	// final actualizar

	void MostrarEstudiantes() { //Muestra la lista de trabajadores
		if (this->ListaEstudiante.empty()) {
			cout << "No se han encontrado estudiantes..." << endl;
		}
		else {
			
			system("cls"); 
			cout << "-----Lista de Estudiantes-----" << endl;
			cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
			for (int i = 0; i < this->ListaEstudiante.size(); i++) {
				cout << "Estudiante #" << i + 1<< endl;
				this->ListaEstudiante[i]->getEstudiantes();
				cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
			
			}
			
			cout << "Estudiantes registrados: " << ListaEstudiante.size() << endl;
			cout << "_____FIN_DE_LA_LISTA_____\n";
		}
	}

	void GuardarEnArchivo(const string& nombreArchivo) const {
		ofstream archivo(nombreArchivo);
		if (archivo.is_open()) {
			for (int i = 0; i < this->ListaEstudiante.size(); i++) {
				archivo << ListaEstudiante[i]->getCedula() << "-" << ListaEstudiante[i]->getNombre() << "-" << ListaEstudiante[i]->getTelefono() <<
					"-" << ListaEstudiante[i]->getCorreo() << "-" << ListaEstudiante[i]->getDireccion() << endl;
			}
			archivo.close();
			cout << "Datos de los estudiantes almacenados en el archivo correctamente..." << endl;
		}
	}

	void CargarEnArchivo(const string& nombreArchivo) {
		ListaEstudiante.clear();
		ifstream archivo(nombreArchivo);
		if (archivo.is_open()) {
			string linea;
			while (getline(archivo, linea)) {
				stringstream ss(linea);
				string nombre, cedula, telefono, correo, direccion;

				// Leer los campos separados por guiones
				getline(ss, cedula, '-');

				getline(ss, nombre, '-');

				getline(ss, telefono, '-');
				int _telefono = stoi(telefono);

				getline(ss, correo, '-');

				getline(ss, direccion);

				Estudiantes* estudiante = new Estudiantes(cedula, nombre, _telefono, correo, direccion); //crea un objeto de la clase estudiante de tipo puntero y se crea un nuevo estudiante
				ListaEstudiante.push_back(estudiante); //guarda el estudiante en el vector
			}
			archivo.close();
			cout << "Datos de los estudiantes cargados correctamente..." << endl;
		}
	}

	void MenuEstudiante() { //contiene el menu de la seccion de los estudiantes
		int Opcion;
		setlocale(LC_CTYPE, "Spanish");
		string nombreArchivo = "Estudiantes.txt";
		do
		{
			

			system("cls");
			cout << "Bienvenido a la seccion de estudiantes, seleccione una opcion" << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << "1) para registrar estudiantes" << endl;
			cout << "2) para modificar estudiantes" << endl;
			cout << "3) para consultar todos los estudiantes" << endl;
			cout << "4) para guardar los datos en un archivo" << endl;
			cout << "5) para recuperar los datos del archivo" << endl;
			cout << "6) Para regresar al Men� Principal     " << endl; 
			cout << "--------------------------------------------------------------" << endl;
			cout << "Ingrese una opci�n: ";
			cin >> Opcion;

			switch (Opcion) {
			case 1: {
				CargarEnArchivo(nombreArchivo); //carga los estudiantes del txt
				AgregarEstudiante();
			
				system("pause");
				break;
			}
			case 2: {
				ActualizarEstudiante();
				system("pause");
				break;
			}
			case 3: {
				MostrarEstudiantes();
				system("pause");
				break;
			}
			case 4: {
				GuardarEnArchivo(nombreArchivo);
				system("pause");
				break;
			}
			case 5: {
				CargarEnArchivo(nombreArchivo);
				system("pause");
				break;
			}
			case 6: {
			
				cout << "\nVolviendo al Men� Principal...\n";
				system("pause");
				break;
			}
			default: {
				cout << "por favor ingrese una opcion valida " << endl;
				if (cin.fail()) 
				{
					cout << "Solo se permiten numeros\n"; 
					cin.clear(); //limpia el buffer   
				} 
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //evita que se caiga el programa cuando ingresan algo que no sea un numero
				cin.clear(); //limpia el buffer   
				system("pause");
				break;
			}
			}
		} while (Opcion!=6); 
	}

};

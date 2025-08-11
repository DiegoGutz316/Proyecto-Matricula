#pragma once
//
//  Contenedor_Cursos.hpp
//  Proyecto Programación l
//
//  Created by Frander Carrillo Torres on 28/10/23.
//

#include "Curso.h"
#include "Librerias.h"

class Contenedor_Cursos {

private:
   vector<Curso*> listaCursos;

public:
  

    const vector<Curso*>& getVector() const {
        return listaCursos; // Devuelve la lista de cursos del profesor
    }


    void agregarCurso()
    {

        bool encontrado = false;
        string _codigo, nombre, horario;   int cupo, creditos;
        Curso curso = Curso("", "", 0, "", 0);

        while (true)
        {
            cout << "\nIngrese Código del Curso: ";
            cin >> _codigo;

            if (cin.fail() || _codigo.empty() || _codigo[0] == '-' || _codigo[0] == ' ')
            {
                cout << "\nIngrese un Código Válido...\n";
                cin.clear(); //limpia el cin
                system("pause");
            }
            else
            {
                curso.setCodigo(_codigo);
                break;
            }
        }
        // verificar codigo

        for (int i = 0; i < listaCursos.size(); i++)
        {
            if (listaCursos[i]->getCodigo() == curso.getCodigo())
            {
                encontrado = true;
                cout << "\nNúmero de Curso ya Existente...\n";
                system("pause");
            }
        }

        if (!encontrado)
        {
            while (true)
            {
                cout << "\nIngrese Nombre del Curso: ";
                cin.ignore(); getline(cin, nombre);

                if (nombre.empty() || nombre[0] == ' ')
                {
                    cin.clear(); //limpia el cin
                    cout << "\nNombre Inválido...";
                    system("pause");
                }
                else
                {
                    break;
                }
            }
            // comprobar nombre

            while (true)
            {
                cout << "\nIngrese Número de Créditos: ";
                cin >> creditos;

                if (cin.fail() || creditos <= 0)
                {
                    cin.clear(); //limpia el cin
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  //evita que se caiga el programa cuando ingresan algo que no sea un numero
                    cout << "\nNúmero de Créditos Inválidos...\n";
                    system("pause");
                }
                else
                {
                    break;
                }
            }
            // comprobar creditos

            while (true)
            {
                cout << "\nIngrese Horario del Curso: ";
                cin.ignore(); getline(cin, horario);

                if (horario.empty() || horario[0] == ' ')
                {
                    cout << "\nHorario Inválido...";
                    cin.clear(); //limpia el cin
                    system("pause");
                }

                else
                {
                    break;
                }
            }
            //comprobar horario

            while (true)
            {
                cout << "\nIngrese Cupo del Curso: ";
                cin >> cupo;

                if (cin.fail() || cupo <= 0)
                {
                    cin.clear(); //limpia el cin
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  //evita que se caiga el programa cuando ingresan algo que no sea un numero
                    cout << "Número de Cupo Inválido...";
                    system("pause");
                }
                else
                {
                    break;
                }
            }
            //comprobrar cupo

            Curso* add = new Curso(_codigo, nombre, creditos, horario, cupo);

            listaCursos.push_back(add);
            cout << "\nCurso Almacenado Correctamente...\n";
            system("pause");
            system("cls");
            mostrarCurso();
        }
        // ! encontrado
    }
    void mostrarCurso()
    {
        int creditos=0,cupos=0;
        if (listaCursos.empty())
        {
            cout << "\nNo hay Cursos Registrados...\n";
        }

        else
        {
            system("cls");
            cout << "Lista de Cursos\n";
            cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
            for (int i=0; i<listaCursos.size();i++)
            {
                creditos += listaCursos[i]->getCreditos();
                cupos += listaCursos[i]->getCupo();
                cout << "  Curso #" << i + 1 << endl;
                listaCursos[i]->getDatos();
                cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
            }
            cout << "Cantidad de cursos registrados: " << listaCursos.size() << endl;
            cout << "Cantidad total de creditos: " << creditos << endl;
            cout << "Cantidad total de cupos: " << cupos << endl;
            cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
            cout << "_____FIN DE LA LISTA_____\n";
        }
    }
    //final mostrar cursos
    void actualizarCurso()
    {
        if (listaCursos.empty()) //si el vector esta vacio
        {
            cout << "\nNo hay Cursos Registrados...\n";
        }

        else
        {
            bool encontrado = false;
            string _codigo, nombre, horario;   int cupo, creditos;
            Curso curso = Curso("", "", 0, "", 0);

            while (true)
            {
                cout << "\nIngrese Código del Curso a modificar: ";
                cin >> _codigo;

                if (cin.fail() || _codigo.empty() || _codigo[0] == '-' || _codigo[0] == ' ')
                {
                    cout << "\nIngrese un Código Válido...\n";
                    cin.clear(); //limpia el cin
                }
                else
                {
                    curso.setCodigo(_codigo);
                    break;
                }
            }
            // verificar codigo

            for (int i = 0; i < listaCursos.size(); i++)
            {
                if (listaCursos[i]->getCodigo() == curso.getCodigo())
                {
                    encontrado = true;
                    while (true)
                    {
                        cout << "\nIngrese Nombre de Curso: ";
                        cin.ignore(); getline(cin, nombre);

                        if (nombre.empty())
                        {
                            cin.clear(); //limpia el cin
                            cout << "\nIngrese un Nombre";
                        }
                        else
                        {
                            break;
                        }
                    }
                    // comprobacion nombre
                    while (true)
                    {
                        cout << "\nIngrese Número de Créditos: ";
                        cin >> creditos;
                        if (cin.fail() || creditos <= 0)
                        {
                            cin.clear(); //limpia el cin
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');  //evita que se caiga el programa cuando ingresan algo que no sea un numero
                            cout << "\nCréditos Inválidos...\n";
                        }
                        else
                        {
                            break;
                        }
                    }
                    // comprobacion creditos
                    while (true)
                    {
                        cout << "\nIngrese Horario del Curso: ";
                        cin.ignore(); getline(cin, horario);

                        if (horario.empty())
                        {
                            cout << "\nHorario Inválido...";
                            cin.clear(); //limpia el cin
                        }
                        else
                        {
                            break;
                        }
                    }
                    // comprobacion horario
                    while (true)
                    {
                        cout << "\nIngrese Cupo del Curso: ";
                        cin >> cupo;

                        if (cin.fail() || cupo <= 0)
                        {
                            cin.clear(); //limpia el cin
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');  //evita que se caiga el programa cuando ingresan algo que no sea un numero
                            cout << "\nCupo Inválido...\n";
                        }
                        else
                        {
                            break;
                        }
                    }
                    // comprobacion cupo
                    listaCursos[i]->setAcutalizar(nombre, creditos, horario, cupo);
                    cout << "\nCurso Actualizado con Éxito...\n";
                    system("pause");
                    system("cls");
                    mostrarCurso();
                }
                // final if
            }
            // final del bucle for
            if (!encontrado)
            {
                cout << "\nCódigo de Curso no Existente...\n";
            }
            // !encontrado
        }
    }
    // final actualizar cursos
    void buscarCurso()
    {
        if (listaCursos.empty())
        {
            cout << "\nNo hay cursos Registrados...\n";
        }
        else
        {
            bool encontrado = false;
            string codigo;
            Curso curso = Curso("", "", 0, "", 0);

            while (true)
            {
                cout << "\nIngrese Código del Curso de que Desea Buscar: ";
                cin.ignore(); getline(cin, codigo);

                if (codigo.empty() || codigo[0] == '-' || codigo[0] == ' ')
                {
                    cout << "\nCódigo Inválido...\n";
                }
                else
                {
                    curso.setCodigo(codigo);
                    break;
                }
            }
            //comprobar codigo

            for (int i = 0; i < listaCursos.size(); i++)
            {
                if (curso.getCodigo() == listaCursos[i]->getCodigo())
                {
                    encontrado = true;
                    cout << "\nCurso Encontrado\n";
                    listaCursos[i]->getDatos();
                }
            }
            // final for

            if (!encontrado)
            {
                cout << "\nCurso no Encontrado...\n";
            }
        }
        // final else
    }
    //final buscar cursos

    void guardarEnArchivo(const string& nombreArchivo)
    {
        ofstream archivo(nombreArchivo.c_str());

        if (archivo.is_open())
        {
            for (int i = 0; i < listaCursos.size(); i++)
            {
                archivo << listaCursos[i]->getCodigo() << '~' << listaCursos[i]->getNombre() << '~' << listaCursos[i]->getCreditos() << '~' << listaCursos[i]->getHorario() << '~' << listaCursos[i]->getCupo() << endl;
            }
            archivo.close();
            cout << "\nDatos Guardados Correctamente en el Archivo...\n";
        }
        else
        {
            cout << "\nNo se pudo Abrir el Archivo...\n\n";
        }

    }
    // final guardar en archivo

    void cargarArchivo(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo.c_str());
        listaCursos.clear();

        if (archivo.is_open())
        {
            string linea;
            while (getline(archivo, linea))
            {
                stringstream ss(linea);
                string codigo, nombre, horario, cupo, creditos, estado;

                getline(ss, codigo, '~');

                getline(ss, nombre, '~');

                getline(ss, creditos, '~');
                int _creditos = stoi(creditos);

                getline(ss, horario, '~');

                getline(ss, cupo);
                int _cupo = stoi(cupo);



                Curso* curso = new Curso(codigo, nombre, _creditos, horario, _cupo); 
                listaCursos.push_back(curso);

            }
            // cargar los datos
            archivo.close();
            cout << "\nDatos Cargados Correctamente...\n";
        } //final if

        else
        {
            cout << "\nNo se pudo abrir el archivo...\n\n";
        }

    } //final cargar archivo

    void menu()
    {
        setlocale(LC_CTYPE, "Spanish");
        string nombreArchivo = "Cursos.txt";
        int menu;
        do {
            system("cls");
            cout << "Bienvenido a la seccion de cursos, seleccione una opcion" << endl;
            cout << "--------------------------------------------------------------" << endl;
            cout << "1) Para registrar Cursos\n";
            cout << "2) Para modificar Cursos\n";
            cout << "3) Para consultar todos los Cursos \n";
            cout << "4) Para buscar un Curso específico \n";
            cout << "5) Para guardar cursos en archivo  \n";
            cout << "6) Para recuperar datos del archivo\n";
            cout << "7) Para regresar al Menú Principal \n"; 
            cout << "--------------------------------------------------------------" << endl;
            cout << "Ingrese una opción: ";
            cin >> menu;

            switch (menu) {

            case 1: {
                cargarArchivo(nombreArchivo); //carga los cursos del txt
                agregarCurso();
                system("pause");
                break; }

            case 2: {
                actualizarCurso();
                system("pause");
                break; }

            case 3: {
                mostrarCurso();
                system("pause");
                break; }

            case 4: {
                buscarCurso();
                system("pause");
                break; }

            case 5: {
                guardarEnArchivo(nombreArchivo);
                system("pause");
                break; }

            case 6: {
                cargarArchivo(nombreArchivo);
                system("pause");
                break; }

            case 7: {
                cout << "\nVolviendo al Menú Principal...\n";
                system("pause");
                break; }


            default: {//inicio default
                cout << "Opción inválida...\n";
                if (cin.fail()) 
                {
                    cout << "Solo se permiten numeros\n"; 
                    cin.clear(); //limpia el buffer   
                } 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  //evita que se caiga el programa cuando ingresan algo que no sea un numero
                cin.clear(); //limpia el buffer   
                system("pause");
                break; } //final default
            }//final menu
        } while (menu != 7); //final ciclo while

    }

 

};



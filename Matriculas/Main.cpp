#include "Contendedor_Matriculas.h"
#include "Contenedor_Cursos.h"
#include "Contenedor_Estudiantes.h"
#include "Contenedor_Profesor.h"


int main()
{
	setlocale(LC_CTYPE, "Spanish");
	

	Contenedor_Cursos cursos;
	Contenedor_Estudiantes estudiantes;
	Contenedor_Profesor listaprofesores(cursos.getVector());
	Contenedor_Matrícula matricula(cursos.getVector(), listaprofesores.getVector(), estudiantes.getvector());

	
	int opcmain;
	do
	{
		system("cls");
		cout << "_________BIENVENIDO_________\n";
		cout << "--------------------------- \n";
		cout << "1)Para gestionar cursos     \n";
		cout << "2)Para gestionar estudiantes\n";
		cout << "3)Para gestionar docentes   \n";
		cout << "4)Para gestionar matriculas \n";
		cout << "5)Para salir                \n";
		cout << "----------------------------\n";
		cout << "Ingrese una opción: ";
		cin >> opcmain;

		switch (opcmain)
		{
			case 1:
			{
				cursos.menu();
				
				break;
			}
			case 2:
			{
				estudiantes.MenuEstudiante();
				
				break;
			}
			case 3:
			{
				listaprofesores.Menu_Profesor();
				
				break;
			}
			case 4:
			{
				matricula.menuMatricula();
				
				break;
			}
			case 5:
			{
				char confirmacion;
				cout << "Estas seguro de salir? " << endl;
				cout << "Ingrese s para confirmar o ingrese cualquier otra letra para permanecer. " << endl;
				cin >> confirmacion;

				if (confirmacion == 's' || confirmacion == 'S')
				{
					system("cls");
					cout << "Saliendo del programa.... " << endl;
					system("pause");
					return true;
				}
				cout << "volviendo...\n";
				system("pause");
				break;
			}
			default:
				cout << "Ingrese una opción valida\n";
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

	} while (true); //sentencia de bucle

}
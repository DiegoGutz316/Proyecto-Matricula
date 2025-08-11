#pragma once
#include "Librerias.h"
#include "Persona.h"

class Profesor : public Persona{
	private:
	
		string codigoCurso;
	public:
		Profesor(const string _codigo,const string _nombre, const int _telefono,const string _correo, const string _codigoCurso) : Persona(_codigo,_nombre,_telefono,_correo) {
			cedula = _codigo;
			nombre = _nombre;
			telefono = _telefono;
			correo = _correo;
			codigoCurso = _codigoCurso;
		}
		void setCodigo(const string code)
		{
			cedula = code;
		} 
		void actualizarDatos(const string _nombre,const int _telefono,const string _correo,const  string _codigoCurso) {
			nombre = _nombre;
			telefono = _telefono;
			correo = _correo;
			codigoCurso = _codigoCurso;
		}
		void mostrarDatos() const
		{
			cout << "___________________________________\n";
			cout << "| Cédula: " << cedula << endl;
			cout << "| Nombre: " << nombre << endl;
			cout << "| Correo: " << correo << endl;
			cout << "| Codigo del curso: " << codigoCurso << endl;
			cout << "___________________________________\n";
		}
		const string getcodigoCurso() const
		{
			return codigoCurso;
		}
};


#pragma once
#include "Librerias.h"

class Matricula
	{
	private:
		static int n;
		int codigo;
		string id_est;
		string id_prof;
		bool estado = false;
		string fechaM;
		string fechaC;
	public:
		Matricula(string Id_est, string Id_prof, string _fecha, bool _estado,string _fechac)
		{
			Matricula::n++; 
			this->codigo = Matricula::n;
			this->id_est = Id_est;
			this->id_prof = Id_prof;
			this->fechaM = _fecha;
			this->estado = _estado;
			this->fechaC = _fechac;
		}
		void getMatricula()
		{
			cout << "___________________________________\n";
			cout << "| Codigo de Matricula:  " << this->codigo << endl;
			cout << "| Identificación del estudiante: " << this->id_est << endl;
			cout << "| Identificación del docente matriculado: " << this->id_prof << endl;
			cout << "| Fecha de matricula:   " << this->fechaM << endl;                  
			cout << "| Estado de matricula:  " << (this->estado ? "\033[1;32mMatriculada\033[0m":"\033[1;31mCancelada\033[0m") << endl;
			cout << "| Fecha de cancelación: " << this->fechaC << endl;
			cout << "___________________________________\n";
		}
		const int getCodigo()const
		{
			return this->codigo;
		}
		const string getId_est()const
		{
			return this->id_est;
		}
		const string getId_Prof()const
		{
			return this->id_prof;
		}
		const bool getEstado() const
		{
			return this->estado;
		}
		const string getFecha()const
		{
			return this->fechaM;
		}
		const string getFechaC()const
		{
			return this->fechaC;
		}
		void setEstado()
		{
			this->estado = false;
		}
		void setFechaC(string _fecha)
		{
			this->fechaC = _fecha;
		}
		void setEstadoDeNuevo()
		{
			this->estado = true;
		}
		



};
int Matricula::n = 0; 



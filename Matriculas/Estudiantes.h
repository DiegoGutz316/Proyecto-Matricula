#pragma once
#pragma once

#include "Librerias.h"
#include "Persona.h"


class Estudiantes : public Persona {
private:
    string direccion;
public:
    Estudiantes(const string _cedula, const string _nombre, const int _telefono, const string _correo, const string _direccion) : Persona(_cedula, _nombre, _telefono, _correo)
    {
        this->direccion = _direccion;
    }

    void setDireccion(const string _direccion) 
    {
        this->direccion = _direccion;
    }

    const string getDireccion()const
    {
        return this->direccion;
    }

   const  void getEstudiantes()const
   {
       cout << "___________________________________\n";
        cout << "| Cedula:    " << this->cedula << endl;
        cout << "| Nombre:    " << this->nombre << endl;
        cout << "| Telefono:  " << this->telefono << endl;
        cout << "| Correo:    " << this->correo << endl;
        cout << "| Direccion: " << this->direccion << endl;
        cout << "___________________________________\n";
    }
 
};

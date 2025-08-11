#pragma once

#include "Librerias.h"
class Persona {

protected:
    string nombre;
    int telefono;
    string correo;
    string cedula;
public:

    Persona(const string _cedula, const string _nombre, const int _telefono, const string _correo)
    {
        this->cedula = _cedula;
        this->nombre = _nombre;
        this->telefono = _telefono;
        this->correo = _correo;
    }

    void setCedula(const string _cedula)
    {
        this->cedula = _cedula;
    }

    void setNombre(const string _nombre) 
    {
        this->nombre = _nombre;
    }

    void setTelefono(const int _telefono)
    {
        this->telefono = _telefono; 
    }

    void setCorreo(const string _correo) 
    {
        this->correo = _correo;
    }

    const string getCedula() const 
    {
        return this->cedula;
    }

    const string getNombre() const 
    {
        return this->nombre;
    }

    const int getTelefono() const 
    {
        return this->telefono; 
    }

    const string getCorreo() const 
    {
        return this->correo; 
    }

};


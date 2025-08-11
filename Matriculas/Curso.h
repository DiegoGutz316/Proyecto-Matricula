#pragma once
//
//  Curso.hpp
//  Proyecto Programación l
//
//  Created by Frander Carrillo Torres on 8/10/23.
//

#ifndef Curso_hpp
#define Curso_hpp

#include <stdio.h>
#include "Librerias.h"


class Curso {

private:

    string codigo;
    string nombre;
    int creditos;
    int cupo;
    string horario;

public:

    Curso(const string _codigo, const string _nombre, const int _creditos, const string _horario, int _cupo)
    {
        this->codigo = _codigo;
        this->nombre = _nombre;
        this->creditos = _creditos;
        this->horario = _horario;
        this->cupo = _cupo;
    }

    void setCodigo(const string _codigo) //para comparar el codigo en la parte de agregar un codigo en el contenedor cursos
    {
        this->codigo = _codigo;
    }

    void setAcutalizar(const string _nombre, const int _creditos, const string _horario, const int _cupo)
    {
        this->nombre = _nombre;
        this->creditos = _creditos;
        this->horario = _horario;
        this->cupo = _cupo;
    }

    const string getCodigo() const
    {
        return codigo; 
    }

    const string getNombre() const
    {
        return this->nombre;
    }

    const int getCreditos() const
    {
        return this->creditos;
    }

    const int getCupo() const 
    {
        return this->cupo;
    }

    const string getHorario() const 
    {
        return this->horario; 
    }

   const void getDatos() const
   {
        cout << "___________________________________\n";
        cout << "| Nombre:    " << this->nombre << endl;
        cout << "| Código:    " << this->codigo << endl;
        cout << "| Créditos:  " << this->creditos << endl;
        cout << "| Horario:   " << this->horario << endl;
        cout << "| Cupo:      " << this->cupo << endl;
        cout << "___________________________________\n";
   }
    void setAumentarCupo() //se utiliza en el contenedor matricula para dar de nuevo el cupo en caso de cancelar matricula
    {
         this->cupo ++ ;
    }
    void setDisminuirCupo()  //se utiliza en el contenedor matricula para quitar un cupo
    {
        this->cupo --;
    }

};

#endif /* Curso_hpp */

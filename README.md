# Sistema de Gestión Académica en C++

Este proyecto es una aplicación de consola desarrollada en C++ para la gestión de información académica, incluyendo estudiantes, profesores, cursos y matrículas. El sistema permite registrar, modificar, consultar y almacenar datos de manera persistente en archivos de texto.

## Clases Principales

### 1. `Persona`
Clase base que representa a una persona con los siguientes atributos y métodos:
- **Atributos:** nombre, teléfono, correo, cédula.
- **Métodos:** setters y getters para cada atributo.

### 2. `Estudiantes` (hereda de `Persona`)
Representa a un estudiante, añadiendo el atributo:
- **Atributo adicional:** dirección.
- **Métodos:** setters y getters para dirección, y método para mostrar los datos del estudiante.

### 3. `Profesor` (hereda de `Persona`)
Representa a un profesor, posiblemente con atributos adicionales (según implementación en `Profesor.h`).

### 4. `Curso`
Clase que representa un curso académico.
- **Atributos:** código, nombre, créditos, etc. (según implementación en `Curso.h`).
- **Métodos:** setters y getters para los atributos del curso.

### 5. `Matricula`
Clase que representa la matrícula de un estudiante en un curso.
- **Atributos:** referencias a estudiante, curso, fecha, etc. (según implementación en `Matricula.h`).
- **Métodos:** gestión de la información de matrícula.

### 6. `Contenedor_Estudiantes`
Gestiona una colección de objetos `Estudiantes`.
- **Métodos:** agregar, actualizar, mostrar, guardar y cargar estudiantes desde archivo, menú interactivo.

### 7. `Contenedor_Profesor`
Gestiona una colección de objetos `Profesor`.
- **Métodos:** similares a los de `Contenedor_Estudiantes` pero para profesores.

### 8. `Contenedor_Cursos`
Gestiona una colección de objetos `Curso`.
- **Métodos:** agregar, actualizar, mostrar, guardar y cargar cursos.

### 9. `Contenedor_Matriculas`
Gestiona una colección de objetos `Matricula`.
- **Métodos:** registrar, mostrar y gestionar matrículas.

## Estructura de Archivos

- `Main.cpp`: Punto de entrada del programa y menú principal.
- `Persona.h`, `Estudiantes.h`, `Profesor.h`: Definición de clases de personas.
- `Curso.h`: Definición de la clase de cursos.
- `Matricula.h`: Definición de la clase de matrículas.
- `Contenedor_Estudiantes.h`, `Contenedor_Profesor.h`, `Contenedor_Cursos.h`, `Contenedor_Matriculas.h`: Clases contenedoras para la gestión de cada entidad.
- `Librerias.h`: Inclusión de librerías estándar y utilitarias.

## Uso

1. Compila el proyecto en Visual Studio 2022 o cualquier entorno compatible con C++14.
2. Ejecuta el programa.
3. Utiliza el menú principal para acceder a la gestión de estudiantes, profesores, cursos y matrículas.

## Notas

- Los datos se almacenan en archivos de texto en el mismo directorio del ejecutable.
- El sistema valida la entrada del usuario para evitar errores comunes.
- El uso de `system("cls")` y `system("pause")` requiere Windows.

---

Desarrollado como parte de un sistema académico modular en C++.

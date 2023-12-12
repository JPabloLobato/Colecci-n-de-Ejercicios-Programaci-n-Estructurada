#include <iostream>
#include <cstring> // funciones de cadenas de caracteres
#include <cstdlib> // funciones malloc

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};
int main() {
    // a. Constitución de una estructura
    // b. Instanciación de estructuras
    Estudiante estudiante1;
    std::strcpy(estudiante1.nombre, "Juan");
    estudiante1.edad = 20;
    estudiante1.promedio = 85.5;

    // c. Instanciación con el operador malloc
    Estudiante* estudiante2 = static_cast<Estudiante*>(std::malloc(sizeof(Estudiante)));
    std::strcpy(estudiante2->nombre, "Maria");
    estudiante2->edad = 22;
    estudiante2->promedio = 90.0;

    // d. Punteros y estructuras
    Estudiante* punteroEstudiante;
    punteroEstudiante = &estudiante1;

    // e. Organización de la programación
    const int MAX_ESTUDIANTES = 10;
    Estudiante listaEstudiantes[MAX_ESTUDIANTES];
    int cantidadEstudiantes = 0;

    // Función para agregar un estudiante a la lista
    auto agregarEstudiante = [&cantidadEstudiantes, &listaEstudiantes](const Estudiante& nuevoEstudiante) {
        if (cantidadEstudiantes < MAX_ESTUDIANTES) {
            listaEstudiantes[cantidadEstudiantes] = nuevoEstudiante;
            cantidadEstudiantes++;
            std::cout << "Estudiante agregado." << std::endl;
        } else {
            std::cout << "La lista de estudiantes está llena." << std::endl;
        }
    };

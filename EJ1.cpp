#include <iostream>
#include <cstring> // Para usar funciones de cadenas de caracteres
#include <cstdlib> // Para usar la función malloc

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

    // Función para ver la lista de estudiantes
    auto verEstudiantes = [&cantidadEstudiantes, &listaEstudiantes]() {
        if (cantidadEstudiantes > 0) {
            std::cout << "Lista de Estudiantes:" << std::endl;
            for (int i = 0; i < cantidadEstudiantes; ++i) {
                std::cout << "Nombre: " << listaEstudiantes[i].nombre << ", Edad: " << listaEstudiantes[i].edad
                          << ", Promedio: " << listaEstudiantes[i].promedio << std::endl;
            }
        } else {
            std::cout << "La lista de estudiantes está vacía." << std::endl;
        }
    };

    // Función para eliminar un estudiante de la lista
    auto eliminarEstudiante = [&cantidadEstudiantes, &listaEstudiantes](const char* nombre) {
        for (int i = 0; i < cantidadEstudiantes; ++i) {
            if (std::strcmp(listaEstudiantes[i].nombre, nombre) == 0) {
                // Mover el último estudiante a la posición del estudiante a eliminar
                listaEstudiantes[i] = listaEstudiantes[cantidadEstudiantes - 1];

                // Limpiar la última posición (opcional)
                std::memset(&listaEstudiantes[cantidadEstudiantes - 1], 0, sizeof(Estudiante));

                cantidadEstudiantes--;
                std::cout << "Estudiante eliminado." << std::endl;
                return;
            }
        }
        std::cout << "Estudiante no encontrado." << std::endl;
    };

    // Uso de las funciones
    agregarEstudiante(estudiante1);
    agregarEstudiante(*estudiante2);
    verEstudiantes();
    eliminarEstudiante("Juan");
    verEstudiantes();

    // Liberar memoria asignada con malloc
    std::free(estudiante2);

    return 0;
}

#include <iostream>
#include <cstring>

union DatosUnion {
    int entero;
    float flotante;
    char cadena[50];  // Usamos un array de caracteres para representar la cadena
};

int main() {
    // Crear una variable de la unión
    DatosUnion datos;

    // Asignar diferentes tipos de valores
    datos.entero = 42;
    std::cout << "Valor entero: " << datos.entero << std::endl;

    datos.flotante = 3.14f;
    std::cout << "Valor flotante: " << datos.flotante << std::endl;

    // Asignar una cadena de caracteres
    std::strcpy(datos.cadena, "Hola, mundo!");
    std::cout << "Valor cadena: " << datos.cadena << std::endl;

    // Observar el comportamiento
    std::cout << "Después de asignar la cadena, el valor entero es: " << datos.entero << std::endl;

    return 0;
}

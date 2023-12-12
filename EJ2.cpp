#include <iostream>
#include <string>

union DatosUnion {
    int entero;
    float flotante;
    std::string cadena;  // Usamos std::string para manejar la cadena de manera segura
};

int main() {
    // Crear una variable de la unión
    DatosUnion datos;

    // Asignar diferentes tipos de valores
    datos.entero = 42;
    std::cout << "Valor entero: " << datos.entero << std::endl;

    datos.flotante = 3.14f;
    std::cout << "Valor flotante: " << datos.flotante << std::endl;

    // Asignar una cadena de caracteres usando std::string
    datos.cadena = "Hola, mundo!";
    std::cout << "Valor cadena: " << datos.cadena << std::endl;

    // Observar el comportamiento
    std::cout << "Después de asignar la cadena, el valor entero es: " << datos.entero << std::endl;

    return 0;
}


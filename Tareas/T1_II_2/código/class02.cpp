/* 
 * clase02.cpp: Programa para mostrar el uso de la
 * clase persona.
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 
 * Hector Perez, abril 2020
 * 
 */

#include <cstdlib>
#include <iostream>
#include "persona.hpp"

using namespace std;

/* Programa para mostrar el uso de la clase persona. 
 * Se crean instancia y llaman metodos para experimentar
 * que pasa. */
int main()
{
    persona Fulano;

    Fulano.Decir_Nombre();
    Fulano.Decir_origen();
    Fulano.Decir_edad();

    persona Juan("Juan Perez", 1980, 7, 2, "Capital");
    
    Juan.Decir_Nombre();
    Juan.Decir_origen();
    Juan.Decir_edad();
    Fulano.Asignar_DPI("1980130130101");
    Fulano.Asignar_FechaNacimiento(2002,2,2);
    Fulano.Asignar_Nombre("Pedro");

    persona* Maria = new persona("Maria Gomez", 1990, 12, 3, "Zacapa");


    delete Maria;

    persona::LLamar_Todos();
    Fulano.Decir_edad();
    return 0;
}
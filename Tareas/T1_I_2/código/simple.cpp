/* 
 * simple.cpp: Implementacion de la clase simple
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 

 * 
 */

#include <iostream>

#include "simple.hpp"

/* El atributo de clase debe ser inicializado como si fuera
 * una variable global. */

int simple::Numero = 0;
int simple::Cuenta=0;

/* Constructor sin argumentos (defecto) */
simple::simple( )
{
    /* Cada vez que se llame este constructor se mostrara este mensaje. */
    std::cout<< "Soy el constructor SIN argumentos" << std::endl;
    /* Se asigna un valor por defecto al atributo Frase */
    Frase = "No hay";
    
    ID=Cuenta;
    /* Se incrementa el valor del atributo de clase. */
    Numero++;
    Cuenta= Numero;
}

/* Constructor con argumentos */
simple::simple( std::string La_Frase )
{
    /* Cada vez que se llame este constructor se mostrara este mensaje. */
    std::cout<< "Soy el constructor CON argumento" << std::endl;
    /* Se asigna al atributo Frase el valor del argumento */
    Frase = La_Frase;
    ID=Cuenta;
    /* Se incrementa el valor del atributo de clase. */
    Numero++;
    Cuenta=Numero;
}

/* Destructor */
simple::~simple()
{
    /* Cada vez que se llame este destructor se mostrara este mensaje. */
    std::cout<< "Soy el destructor" << std::endl;
    /* Se decrementa el valor del atributo de clase. */
    Numero--;
}

/* Implementacion del metodo Decir_Frase: Se llama a traves de las 
 * instancias de la clase */
void simple::Decir_Frase()
{
    std::cout << "La frase es: " << Frase << std::endl;
}

/* Metodo de clase: indica cuantas instancias van de la clase */
void simple::Cuantos()
{
    std::cout << "Hay " << Numero << " instancias de simple" << std::endl;
}


void simple::Mostrar_ID()
{
    std::cout << "ID:" << ID << std::endl;
}
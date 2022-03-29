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
#include "VecR3.hpp"

using namespace std;

/* Programa para mostrar el uso de la clase persona. 
 * Se crean instancia y llaman metodos para experimentar
 * que pasa. */
int main()
{
    VecR3 K(1,2,3);
    VecR3 Q(2,3,4);

    Q.Mostar_Esfericas(false);
    
    
    std::cout <<  Q.operator+(K) << std::endl;
    std::cout <<  Q.operator-(K) << std::endl;
    std::cout <<  Q.operator*(K) << std::endl;
    std::cout <<  Q.operator%(K) << std::endl;
    std::cout <<  operator*(2,K) << std::endl;
    std::cout <<  operator/(2,K) << std::endl;
    Q.Mostar_Esfericas(true);
    Q.operator==(K);
    std::cout <<  Q.operator=(K) << std::endl;
    
    return 0;
}
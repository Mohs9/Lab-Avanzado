/* 
 * VecR3.hpp: Definicion de la clase VecR3
 * 
 * Tarea para el curso de laboratorio Avanzado
 * 
 * Rubí Esmeralda Ramírez Milián 
 * 
 */

#ifndef __VECR3_HPP__
#define __VECR3_HPP__

#include <iostream>
#include <string>

/* Clase VecR3: Vectores en R3. Internamente
 * se representa en forma cartesiana. */ 
class VecR3
{
private:
    /* Coordenada x */
    float Xcor;
    /* Coordenada y */
    float Ycor;
    /* Coordenada z*/
    float Zcor;

    /* Atributo de clase: Indica si el despliege del
     * vector seran en coordenas polares. */
    static bool Esfericas;

public:

    /* Constructor sin argumentos */
    VecR3();
    /* Constructor con argumentos */
    VecR3( float valor_x, float valor_y, float valor_z );
    /* Destructor */
    ~VecR3();

    /* Metodos de asignacion (set methods) */

    /* Asigna la coordenada x */
    void Asignar_x( float valor_x );
    /* Asigna la coordenada y */
    void Asignar_y( float valor_y );
     /* Asigna la coordenada y */
    void Asignar_z( float valor_z ); 
    /* Asigna las coordenadas x, y */
    void Asignar_xyz( float valor_x, float valor_y, float valor_z );

    /* Metodos de obtencion (get methods)
     * El calificador const al final del prototipo
     * indica que estos metodos no van a alterar
     * los valores de la instancia que los llama. */

    /* Obtener la coordenada x */
    float Obtener_x( ) const;
    /* Obtener la coordenada y */
    float Obtener_y( ) const;
    /* Obtener la coordenada x */
    float Obtener_z( ) const;



    /* Otros metodos */
    
    /* Devuelve la magnitud del vector */
    float Magnitud() const;

    /* Sobrecarga de operadores
     * El calificador const en el argumento impide 
     * que el argumento del operador pueda ser modificado
     * dentro del metodo. */

    /* Calcula la suma de dos vectores */
    VecR3 operator+( const VecR3 & ) const;
    /* Calcula la suma de dos vectores */
    VecR3 operator-( const VecR3 & ) const;
    /* Calcula el producto punto de dos vectores */
    float operator*( const VecR3 & ) const;
    /* Calcula la multiplicación de un vector por un escalar */
    //VecR3 operator_escalar( const VecR3 & ) const;
  
    /* Calcula el producto cruz de dos vectores */
    VecR3 operator%( const VecR3 & ) ;
    /* Operador de asignacion */
    VecR3 operator=( const VecR3 & );
    /* Operador de comparación de igualdad entre vectores*/
    int operator==( const VecR3 & );


    /* Metodo de clase: Fija el valor del flag para que
     * el despliege del vector sea en polar (true) o
     * cartesiano (false) */
    static void Mostar_Esfericas( bool valor );

    /* Funciones amigas */

    /* Despliega un vector con cout */
    friend std::ostream &operator<<( std::ostream &, const VecR3 & );
    /* Multiplica un flotante por un vector */
    friend VecR3 operator*( const float &, const VecR3 & );
    /* Calcula la división de un vector por un escalar */
    friend VecR3 operator/( const float &,  const VecR3 & );

};

#endif /* __VECR3_HPP__ */
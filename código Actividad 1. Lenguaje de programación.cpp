/******************************************************************************

 Actividad 1: Cálculo de edad en C++

*******************************************************************************/
#include <iostream>
#include <stdio.h>

int main()
{
    int edad;
    std::cout <<"ingrese su edad: ";
    std::cin >> edad;
    
    if (edad >=18) {
        std::cout << "usted es mayor de edad" << std::ends;
    } else {
        std::cout << "usted es menor de edad" << std::ends;
    }
    
    return 0;
}    
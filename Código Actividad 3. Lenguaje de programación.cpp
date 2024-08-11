/******************************************************************************
Actividad 3: Cálculo ulo de rfc.
*******************************************************************************/
#include <iostream>
#include <string>

//función nos permite obtener la primera vocal interna de una cadena de texto
char obtenerPrimeraVocalInterna(const std::string& str) {
    for (size_t i = 1; i < str.length(); ++i) {
        char c = str[i];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return c;
    }
    return 'X'; // si no se encuentra ninguna vocal interna, se usa la X
}

//Función principal para calcular el RFC
std::string calcularRFC(const std::string& nombre, const std::string& apellidoPaterno, const std::string& apellidoMaterno, const std::string& fechaNacimiento){
    std::string rfc;

    //se obtiene la letra inicial y la primera vocal interna del apellido paterno
    char letraInicial = apellidoPaterno[0];
    char PrimeraVocalInterna = obtenerPrimeraVocalInterna(apellidoPaterno);
    
    //se obtiene la inicial del apellido materno o se usa una X si no lo tiene
    char inicialApellidoMaterno = (!apellidoMaterno.empty()) ? apellidoMaterno[0] : 'X';
    
    //se obtiene la inicial del primer nombre o se usa una X si no hay
    char inicialNombre = nombre[0];
    
    //se obtienen los dos últimos digitos del año de nacimiento
    std::string anio = fechaNacimiento.substr(2,2);
    
    //se obtiene el mes y día de nacimiento
    std::string mes = fechaNacimiento.substr(5,2);
    std::string dia = fechaNacimiento.substr(8,2);
    
    //se construye el rfc
    rfc = letraInicial;
    rfc += PrimeraVocalInterna;
    rfc += inicialApellidoMaterno;
    rfc += inicialNombre;
    rfc += anio;
    rfc += mes;
    rfc += dia;
    return rfc;
}
int main() {
    std::string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;
    
    std::cout << "Ingrese el nombre: ";
    std::getline (std::cin, nombre);
    
    std::cout << "Ingrese el apellido paterno: ";
    std::getline (std::cin, apellidoPaterno);
    
    std::cout << "Ingrese el apellido materno: (Si no tienen pulse Enter) ";
    std::getline (std::cin, apellidoMaterno);
    
    std::cout << "Ingrese la fecha de nacimiento (YYYY-MM-DD): ";
    std::getline(std::cin, fechaNacimiento);
    std::string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento);
    
    std::cout << "RFC: " << rfc << std::endl;
    
    return 0;
}
#include <iostream>

#include "Verificador.h"
#include "Conversor.h"
#include "Analizador.h"

using namespace std;

int main()
{
    string expresion = "(-4)/((-2)+2)",
        expresionPosfija = "";
    double resultado = 0.0;

    if (Verificador::esValida(expresion)) {
        expresionPosfija = Conversor::convertirPosfija(expresion);
        cout << expresionPosfija<<endl;
        resultado = Analizador::resolverPosfija(expresionPosfija);
        cout << "Resultado: " << resultado<<endl;
    }
}
#include <iostream>
#include <string>

#include "Verificador.h"
#include "Postfix.h"

using namespace std;

int main()
{
    string expresion = "(-1)/((-2)+2)", resultado = "";
    Postfix posfija(expresion);

    if (Verificador::esValida(expresion)) {
        resultado = posfija.resolve();
        try
        { 
            cout << stod(resultado)<<endl;
        }
        catch (const std::exception&)
        {
            cout << resultado<<endl;
        }
    }
}
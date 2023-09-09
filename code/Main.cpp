#include <iostream>
#include <string>

#include "Verificador.h"
#include "Postfix.h"

using namespace std;

int main()
{
    string resultado = "";
    string resultado2 = "";
    string resultado3 = "";
    string resultado4 = "";
    string resultado5 = "";

    string expresion = "6/2*(1+2)";
    string expresion2 = "1/((-2)+2)";
    string expresion3 = "45+20/72";
    string expresion4 = "0+222*3";
    string expresion5 = "1+2*3/4*(1+2+3+4+5)";

    if (Verificador::esValida(expresion) && Verificador::esValida(expresion2) && Verificador::esValida(expresion3) && Verificador::esValida(expresion4) && Verificador::esValida(expresion5))
    {
        Postfix posfija(expresion);
        Postfix posfija2(expresion2);
        Postfix posfija3(expresion3);
        Postfix posfija4(expresion4);
        Postfix posfija5(expresion5);

        resultado = posfija.resolve();
        resultado2 = posfija2.resolve();
        resultado3 = posfija3.resolve();
        resultado4 = posfija4.resolve();
        resultado5 = posfija5.resolve();
        try
        {
            cout << stod(resultado) << endl;
        }
        catch (const std::exception &)
        {
            cout << resultado << endl;
        }

        try
        {
            cout << stod(resultado2) << endl;
        }
        catch (const std::exception &)
        {
            cout << resultado2 << endl;
        }

        try
        {
            cout << stod(resultado3) << endl;
        }
        catch (const std::exception &)
        {
            cout << resultado3 << endl;
        }

        try
        {
            cout << stod(resultado4) << endl;
        }
        catch (const std::exception &)
        {
            cout << resultado4 << endl;
        }

        try
        {
            cout << stod(resultado5) << endl;
        }
        catch (const std::exception &)
        {
            cout << resultado5 << endl;
        }
    }
}
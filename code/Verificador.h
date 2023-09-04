#pragma once

#define esOperador(c) (c == '+' || c == '-' || c == '*' || c == '/')
#define esParenteris(c) (c=='(' || c==')')

#include <iostream>
using namespace std;

class Verificador
{
private:
    static bool errorLexico(string);
    static bool errorSintax(string);

public:
    static bool esValida(string);
};

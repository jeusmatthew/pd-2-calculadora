#pragma once
#include <iostream>
#include <stack>

#define esOperador(c) (c == '+' || c == '-' || c == '*' || c == '/')
#define esParenteris(c) (c=='(' || c==')')

using namespace std;

class Conversor
{
private:
	static int compararPresedencia(char, char);
	static int verificarJerarquia(char);
public:
	static string convertirPosfija(string);
};


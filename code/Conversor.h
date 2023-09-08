#pragma once
#include <iostream>
#include <stack>
#include <deque>
#include <string>

#define esOperador(c) (c == '+' || c == '-' || c == '*' || c == '/')
#define esParenteris(c) (c=='(' || c==')')

using namespace std;

class Conversor
{
private:
	static int compararPresedencia(char, char);
	static int verificarJerarquia(char);
	static bool esNumero(string);
public:
	static deque<int> convertirPosfija(string);
};


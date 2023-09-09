#include "Conversor.h"

int Conversor::compararPresedencia(char operator1, char operator2)
{
	int prioridadA = 0, prioridadB = 0;

	prioridadA = verificarJerarquia(operator1);
	prioridadB = verificarJerarquia(operator2);

	return prioridadA - prioridadB;
}

int Conversor::verificarJerarquia(char op)
{
	int jerarquia = 0;
	switch (op)
	{
	case '*':
	case '/':
		jerarquia = 2;
		break;
	case '+':
	case '-':
		jerarquia = 1;
		break;
	}
	return jerarquia;
}

//Es suficientemente bueno
bool Conversor::esNumero(string str)
{

	for (char c : str)
	{
		if (!isdigit(c) && c != '-')
		{
			return false;
		}
	}

	return true;
}

deque<string> Conversor::convertirPosfija(string expresion)
{
	//string salida;
	deque<string> salida;
	stack<char> pila;
	string number = "";
	string cToS = "";

	for (int i = 0; expresion[i] != '\0'; i++)
	{
		char c = expresion[i];

		//number detection
		if (isdigit(c) || c == '-')
		{
			number.push_back(c);
		}
		else
		{
			if (!number.empty())
			{
				salida.push_back(number);
				number = "";
			}

			if (c == '(')
				pila.push(c);
			else if (c == ')')
			{
				while (!pila.empty() && pila.top() != '(')
				{
					salida.push_back(string(1, pila.top()));
					pila.pop();
				}
				if (pila.top() == '(')
					pila.pop();
				else
					cout << "Err 2\n";
			}
			else if (esOperador(c))
			{
				while (!pila.empty() && compararPresedencia(pila.top(), c) >= 0)
				{
					salida.push_back(string(1, pila.top()));
					pila.pop();
				}
				pila.push(c);
			}
		}
	}

	if (!number.empty())
	{
		salida.push_back(number);
		number = "";
	}

	while (!pila.empty())
	{
		salida.push_back(string(1, pila.top()));
		pila.pop();
	}

	return salida;
}

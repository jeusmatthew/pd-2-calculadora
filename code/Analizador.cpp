#include "Analizador.h"

string Analizador::resolverPosfija(deque<int> expresion)
{
	double op1 = 0.0, op2 = 0.0, resultado = 0.0;
	stack<double> pila;

	for (int c : expresion)
	{
		if(esOperador(c))
		{
			op2 = pila.top();
			pila.pop();
			op1 = pila.top();
			pila.pop();

			switch (c)
			{
			case '+':
				resultado = op1 + op2;
				break;
			case '-':
				resultado = op1 - op2;
				break;
			case '*':
				resultado = op1 * op2;
				break;
			case '/':
				if (op2 == 0)
				{
					return "Error: Division entre 0!\n";
				}
				resultado = (double)(op1) / op2;
				break;
			}
			pila.push(resultado);
		}
		else
		{
			pila.push(expresion.front());
			expresion.pop_front();
		}
	}

	return to_string(pila.top());
}

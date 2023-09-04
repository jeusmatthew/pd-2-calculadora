#include "Analizador.h"

double Analizador::resolverPosfija(string expresion)
{
	double op1 = 0.0, op2 = 0.0, resultado = 0.0;
	stack<double> pila;

	for (int i = 0; i < expresion.length(); i++)
	{
		char c = expresion[i], nextC = expresion[i + 1];
		// (- '0') convierte a entero 
		if (isdigit(c))
		{
			if (nextC == '-')
			{
				pila.push((c - '0') * -1);
				i++; //Salta el siguiente elemento (operador) para que le siga el operando2
			}
			else
				pila.push(c - '0');
		}
		else
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
					cout << "Error: Division entre 0!" << endl;
					return 0;
				}
				resultado = static_cast<double>(op1) / op2;
				break;
			}
			pila.push(resultado);
		}
	}

	return pila.top();
}

#include "Verificador.h"

bool Verificador::errorLexico(string expresion)
{
	bool error = false;
	for (char c : expresion)
	{
		if (!isdigit(c) && !esOperador(c) && !esParenteris(c))
		{
			cout << "Error lexico en el catacter: " << c << endl;
			error = true;
		}
	}

	return error;
}

bool Verificador::errorSintax(string expresion)
{
	bool error = false;
	int balanceParentesis = 0;

	if (esOperador(expresion[0]) || expresion[0] == ')')
	{
		cout << "Error: no se permite iniciar con el operador " << expresion[0] << endl;
		error = true;
	}
	else if (esOperador(expresion.back()))
	{
		cout << "Error: no se permite finalizar la expresion con el operador: " << expresion.back() << endl;
		error = true;
	}

	for (int i = 0; i < expresion.length(); i++)
	{
		char c = expresion[i], nextC = expresion[i + 1];

		// Manejo de parentesis
		if (c == '(')
		{
			balanceParentesis++;

			if (esOperador(nextC) && nextC!='-')
			{
				cout << "Error: no se permite un operador despues de un parentesis izquierdo (" << nextC << endl;
				error = true;
			}
			if (nextC == ')')
			{
				cout << "Error: no se permiten parentesis vacios ()" << endl;
				error = true;
			}
		}
		else if (c == ')')
		{
			balanceParentesis--;
			if (nextC == '(')
			{
				cout << "Error: se esperaba )" << endl;
				error = true;
			}
			if (balanceParentesis < 0)
			{
				cout << "Error: cierre de parentesis sin correspondiente apertura" << endl;
				error = true;
			}
		}

		// manejo de digitos
		else if (isdigit(c))
		{
			if (isdigit(nextC))
			{
				cout << "Error: no se permiten dos caracteres seguidos " << c << nextC << endl;
				error = true;
			}
			else if (nextC == '(')
			{
				cout << "Error: se esperaba un producto en " << c << " para efectuar la operacion" << endl;
				error = true;
			}
		}

		//manejo de operadores
		else if (esOperador(c))
		{
			if (esOperador(nextC) || nextC == ')')
			{
				if (nextC == ')')
				{
					cout << "Error: se esperaba un digito en " << c << endl;
					error = true;
				}
				else
				{
					cout << "Error: No se permiten dos operadores seguidos " << c << nextC << ", se esperaba un digito." << endl;
					error = true;
				}
			}
			else if (c == '/' && nextC == '0')
			{
				cout << "Error: división entre 0." << endl;
			}
		}
	}
	if (balanceParentesis > 0)
	{
		cout << "Error: apertura de parentesis sin correspondiente cierre." << endl;
		error = true;
	}

	return error;
}


bool Verificador::esValida(string expresion)
{
	return !errorLexico(expresion) && !errorSintax(expresion);
}

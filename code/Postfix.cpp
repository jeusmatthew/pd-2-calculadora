#include "Postfix.h"

Postfix::Postfix(string str)
{
	value = Conversor::convertirPosfija(str);
}

string Postfix::resolve()
{
	return Analizador::resolverPosfija(value);
}

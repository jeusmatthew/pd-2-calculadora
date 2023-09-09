#pragma once
#include "Conversor.h"
#include "Analizador.h"

class Postfix
{
private:
	deque<string> value;
public:
	Postfix(string);
	string resolve();
};


#pragma once
#include "Conversor.h"
#include "Analizador.h"

class Postfix
{
private:
	deque<int> value;
public:
	Postfix(string);
	string resolve();
};


#pragma once

#include <iostream>
#include <string>
#include <deque>
#include <stack>
using namespace std;

#define esOperador(c) (c == '+' || c == '-' || c == '*' || c == '/')


class Analizador
{
private:

public:
	static string resolverPosfija(deque<string>);
};


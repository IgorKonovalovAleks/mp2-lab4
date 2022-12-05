#pragma once
#include "FiniteStateMachineValidator.h"
#include "PrefixFormer.h"


class Expression
{
private:

	const char* source;
	FSMValidator fsmv;
	PFormer pf;

public:

	Expression();
	Expression(const char* s);
	double calculate();
	static double parseNumber(Token number);

};

Expression::Expression() : source(nullptr){}

Expression::Expression(const char* s) : source(s) {}

double Expression::parseNumber(Token number) {}

double Expression::calculate() {}

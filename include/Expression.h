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

Expression::Expression(const char* s) : source(s) {
	std::queue<int> tokens;
	fsmv.validate(s, tokens);
	pf.buildPrefix(s, tokens);
}

double Expression::parseNumber(Token number) {

	double res = 0;
	int dot;
	for (dot = 0; dot < number.len; dot++)
		if (number.val[dot] == '.')
			break;

	double pow = 1;
	for (int i = dot - 1; i >= 0; i--) {
		res += ((unsigned long long)number.val[i] - 48) * pow;
		pow *= 10.0;
	}

	pow = 0.1;
	for (int i = dot + 1; i < number.len; i++) {
		res += ((unsigned long long)number.val[i] - 48) * pow;
		pow /= 10;
	}

	return res;

}

double Expression::calculate() {

	std::stack<double> numbers;
	Token cur;
	double b;
	double a;
	while (!pf.empty()) {
		cur = pf.getNext();
		switch (cur.prio)
		{
		case TokenPrio::NUMBER_:
			numbers.push(parseNumber(cur));
			break;

		case TokenPrio::PLUS_:
			b = numbers.top();
			numbers.pop();
			a = numbers.top();
			numbers.pop();
			if (cur.val[0] == '+')
				numbers.push(a + b);
			else
				numbers.push(a - b);
			break;



		case TokenPrio::MULTIPLY_:
			b = numbers.top();
			numbers.pop();
			a = numbers.top();
			numbers.pop();
			if (cur.val[0] == '*')
				numbers.push(a * b);
			else
				numbers.push(a / b);
			break;

		case TokenPrio::UNARY_MINUS_:
			b = numbers.top();
			numbers.pop();
			numbers.push(-b);
			break;

		}
	}

	return numbers.top();

}

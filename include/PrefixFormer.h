#pragma once
#include "Enums.h"



class PFormer {
private:
	
	std::queue<Token> pForm;
	std::stack<Token> operators;

public:

	PFormer();
	void buildPrefix(const char* str, std::queue<int>& iForm);
	bool empty();
	Token getNext();

};


PFormer::PFormer() {}

bool PFormer::empty() {
	return pForm.empty();
}

Token PFormer::getNext() {
	Token a = pForm.front();
	pForm.pop();
	return a;
}

void PFormer::buildPrefix(const char* str, std::queue<int>& iForm) {

	bool start = true;                                           //tracking unary minus
	if (iForm.empty()) {
		return;
	}
	for (int i = iForm.front(); true; i = iForm.front()) {
		iForm.pop();

		switch (str[i])
		{

		case '(':
			//std::cout << "case (\n";
			operators.push(Token(TokenPrio::OPEN_BRACKET_));
			start = true;
			break;

		case ')':
			//std::cout << "case )\n";
			for (Token j = operators.top(); j.prio != TokenPrio::OPEN_BRACKET_; j = operators.top()) {
				operators.pop();
				pForm.push(j);
			}
			operators.pop();
			break;

		case '+':
			//std::cout << "case +\n";
			if (!operators.empty() && operators.top().prio > TokenPrio::PLUS_) {
				for (Token j = operators.top(); j.prio > TokenPrio::PLUS_; j = operators.top()) {
					operators.pop();
					pForm.push(j);
				}
			}
			operators.push(Token(TokenPrio::PLUS_, str + i));
			break;

		case '-':
			//std::cout << "case -\n";
			if (start) {
				operators.push(Token(TokenPrio::UNARY_MINUS_, str + i));
				start = false;
				break;
			}

			if (operators.top().prio > TokenPrio::MINUS_) {
				for (Token j = operators.top(); j.prio > TokenPrio::MINUS_; j = operators.top()) {
					operators.pop();
					pForm.push(j);
				}
			}

			operators.push(Token(TokenPrio::MINUS_, str + i));
			break;

		case '*':
			//std::cout << "case *\n";
			if (operators.top().prio > TokenPrio::MULTIPLY_) {
				for (Token j = operators.top(); j.prio > TokenPrio::MULTIPLY_; j = operators.top()) {
					operators.pop();
					pForm.push(j);
				}
			}
			operators.push(Token(TokenPrio::MULTIPLY_, str + i));
			break;

		case '/':
			//std::cout << "case /\n";
			if (operators.top().prio > TokenPrio::DIVIDE_) {
				for (Token j = operators.top(); j.prio > TokenPrio::DIVIDE_; j = operators.top()) {
					operators.pop();
					pForm.push(j);
				}
			}
			operators.push(Token(TokenPrio::MULTIPLY_, str + i));
			break;

		default:                                                                  //only decimals
			//std::cout << "case number\n";
			pForm.push(Token(TokenPrio::NUMBER_, str + i, iForm.front() - i + 1));

			start = false;
			iForm.pop();
			break;

		}
		if (iForm.empty())
			break;
	}

	if (!operators.empty())
		for (Token j = Token(1); !operators.empty();) {
			j = operators.top();
			operators.pop();
			pForm.push(j);
		}

}


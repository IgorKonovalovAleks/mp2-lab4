#pragma once
#include "Enums.h"



class FSMValidator {
private:
	int state;
	std::queue<int> res;                             //remember positions of tokens
	                                                 //start and end for numbers, start for brackets and operators

	bool brackets(const char* s);
	void push(int i);
	int findType(const char i);
	int start(const char i, int c);
	int afterOperator(const char i, int c);
	int firstPart(const char i, int c);
	int secondPart(const char i, int c);
	int afterCloseBracket(const char i, int c);
	int end(const char i, int c);

public:

	FSMValidator();
	void validate(const char* str, std::queue<int>& r);

};

FSMValidator::FSMValidator() : state(States::START) {}

bool FSMValidator::brackets(const char* s) {}

void FSMValidator::push(int i) {}

int FSMValidator::findType(const char i) {}

int FSMValidator::start(const char i, int c) {}

int FSMValidator::afterOperator(const char i, int c) {}

int FSMValidator::firstPart(const char i, int c) {}

int FSMValidator::secondPart(const char i, int c) {}

int FSMValidator::afterCloseBracket(const char i, int c) {}

int FSMValidator::end(const char i, int c) {}

void FSMValidator::validate(const char* str, std::queue<int>& r) {}

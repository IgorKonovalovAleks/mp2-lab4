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

bool PFormer::empty() {}

Token PFormer::getNext() {}

void PFormer::buildPrefix(const char* str, std::queue<int>& iForm) {}


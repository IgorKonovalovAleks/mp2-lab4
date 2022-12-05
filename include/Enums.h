#pragma once

#include <stack>
#include <queue>
#include <iostream>

const unsigned int MAX_TOKEN_LENGTH = 256;

enum States {
	START, 
	FIRST_PART,
	SECOND_PART,
	AFTER_OPERATOR,
	AFTER_CLOSE_BRACKET,
	END,
	FAIL
};

const char dec[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
const char ops[4] = { '+', '-', '*', '/' };
const char sps[1] = { ' ' };
const char dot[1] = { '.' };
const char opb[1] = { '(' };
const char clb[1] = { ')' };
const char min[1] = { '-' };

enum Chars {
	DECIMAL,
	OPERATOR,
	SPACE,
	DOT,
	OPEN_BRACKET,
	CLOSE_BRACKET,
	MINUS,
	NOT_VALID
};

enum TokenPrio {       //priorities
	NUMBER_ = -1,
	OPEN_BRACKET_ = 0,
	CLOSE_BRACKET_ = 0,
	PLUS_ = 1,
	MINUS_ = 1,
	DIVIDE_ = 2,
	MULTIPLY_ = 2,
	UNARY_MINUS_ = 3
};

struct Token
{
	int prio;
	const char* val;
	int len;

	Token(int t, const char* v, int l) : prio(t), val(v), len(l) {}
	Token(int t, const char* v) : prio(t), val(v), len(1) {}                               //for operators
	Token(int t) : prio(t) {}                                                              //for brackets
	Token() {}
	Token(const Token& old) : prio(old.prio), val(old.val), len(old.len) {}


};

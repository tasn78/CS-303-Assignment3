#pragma once
// Tom Steinman
// CS303-0001
// Assignment 3
// 7/10/23

#ifndef POSTFIX_H_
#define POSTFIX_H_


#include <stack>
#include <string>
#include "SyntaxError.h"

class Postfix_Evaluator {
public:
	int eval(const std::string& expression);

private:
	static const std::string OPERATORS;
	std::stack<int> operand_stack;
	int eval_op(char op);
	bool is_operator(char ch) const {
		return OPERATORS.find(ch) != std::string::npos;
	}
};

#endif
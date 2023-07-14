#pragma once
// Tom Steinman
// CS303-0001
// Assignment 3
// 7/10/23

#ifndef INFIXTOPOSTFIX_H_
#define INFIXTOPOSTFIX_H_

#include <stack>
#include <string>

class Infix_To_Postfix {
public:
	std::string convert(const std::string& expression);

private:
	// Data Fields
	std::stack<char> operator_stack;
	std::string postfix;
	static const std::string OPERATORS;
	static const int PRECEDENCE[];

	// Functions
	void process_operator(char op);
	int precedence(char op) const {
		return PRECEDENCE[OPERATORS.find(op)];
	}
	bool is_operator(char ch) const {
		return OPERATORS.find(ch) != std::string::npos;
	}
};

#endif
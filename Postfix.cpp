// Tom Steinman
// CS303-0001
// Assignment 3
// 7/10/23

#include "Postfix.h"
#include <sstream>
#include <cctype>
using std::stack;
using std::string;
using std::istringstream;
using std::isdigit;

const std::string Postfix_Evaluator::OPERATORS = "+-*/%";

// Evaluates postfix expression, not used or working
int Postfix_Evaluator::eval(const std::string& expression) { // FIXME
	while (!operand_stack.empty()) {
		operand_stack.pop();

		istringstream tokens(expression);
		char next_char;
		while (tokens >> next_char) {
			if (isdigit(next_char)) {
				tokens.putback(next_char);
				int value;
				tokens >> value;
				operand_stack.push(value);
			}
			else if (is_operator(next_char)) {
				int result = eval_op(next_char);
				operand_stack.push(result);
			}
			else {
				throw SyntaxError("Invalid character");
			}
		}
		if (!operand_stack.empty()) {
			int answer = operand_stack.top();
			operand_stack.pop();
			if (operand_stack.empty()) {
				return answer;
			}
			else {
				throw SyntaxError("Stack should be empty");
			}
		}
		else {
			throw SyntaxError("Stack is empty");
		}
	}
}

// Evaluates FIX ME
int Postfix_Evaluator::eval_op(char op) {
	if (operand_stack.empty())
		throw SyntaxError("Stack is empty");
	int rhs = operand_stack.top();
	operand_stack.pop();
	if (operand_stack.empty())
		throw SyntaxError("Stack is empty");
	int lhs = operand_stack.top();
	operand_stack.pop();
	int result = 0;
	switch (op) {
	case '+': result = lhs + rhs;
		break;
	case '-': result = lhs - rhs;
		break;
	case '*': result = lhs * rhs;
		break;
	case '/': result = lhs / rhs;
		break;
	case '%': result = lhs % rhs;
	}
	return result;
};
// Tom Steinman
// CS303-0001
// Assignment 3
// 7/10/23

#include "InfixToPostfix.h"
#include "SyntaxError.h"
#include <sstream>
#include <cctype>
using std::string;
using std::istringstream;

const string Infix_To_Postfix::OPERATORS = "+-*/%";
const int Infix_To_Postfix::PRECEDENCE[] = { 1, 1, 2, 2, 2 };


// Extracts and processes each token in infix and returns the postfix string.
string Infix_To_Postfix::convert(const string& expression) {
    postfix = "";
    for (char ch : expression) {
        if (ch == ' '){
            continue;
            }
        // If it is an operand
        if (!is_operator(ch) && ch != ')' && ch != '(' &&
                         ch != '}' && ch != '{' && ch != ']' && ch != '[') {
            postfix += ch;
        }
        else if (ch == '(' || ch == '{' || ch == '[') {
            operator_stack.push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']') {
            while (!operator_stack.empty() && operator_stack.top() != '(' &&
                operator_stack.top() != '{' && operator_stack.top() != '[') {
                postfix += operator_stack.top();
                operator_stack.pop();
            }

            if (!operator_stack.empty() && ((ch == ')' && operator_stack.top() == '(') ||
                                            (ch == '}' && operator_stack.top() == '{') ||
                                            (ch == ']' && operator_stack.top() == '['))) {
                operator_stack.pop();
            }
            else {
                throw SyntaxError("Error: Mismatched brackets1");
            }
        }

        else if (is_operator(ch)) {
            while (!operator_stack.empty() && operator_stack.top() != '(' && operator_stack.top() != '{' && operator_stack.top() != '[' && precedence(ch) <= precedence(operator_stack.top())) {
                postfix += operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.push(ch);
        }
    }

    // Pop any remaining operators from the stack and append them to the postfix expression
    while (!operator_stack.empty()) {
        if (operator_stack.top() == '(' || operator_stack.top() == '{' || operator_stack.top() == '[') {
            throw SyntaxError("Error: Mismatched brackets2");
            return "";
        }
        postfix += operator_stack.top();
        operator_stack.pop();
    }

    return postfix;
}

// Processes operators
void Infix_To_Postfix::process_operator(char op) {
	if (operator_stack.empty()) {
		operator_stack.push(op);
	}
	else {
		if (precedence(op) > precedence(operator_stack.top())){
			operator_stack.push(op);
		}
		else {
			while (!operator_stack.empty() 
				   && (precedence(op) <= precedence(operator_stack.top()))) {
				postfix += operator_stack.top();
				postfix += " ";
				operator_stack.pop();
			}
			operator_stack.push(op);
		}
	}
}
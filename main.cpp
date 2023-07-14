// Tom Steinman
// CS303-0001
// Assignment 3
// 7/10/23

#include "Balanced.h"
#include "Postfix.h"
#include "InfixToPostfix.h"
#include "Queue.h"

int main() {
	// Q1
	cout << "Enter an expression\n";
	string expression;
	Postfix_Evaluator evaluation;
	Infix_To_Postfix postfix;
	while (getline(cin, expression) && (expression != "")) {
		cout << expression;
		if (is_balanced(expression)) {
			cout << " is balanced\n";
			if (expression == "") break;
			try {
				string post = postfix.convert(expression);
				cout << "Postfix expression : " << post << endl;
			}
			catch (SyntaxError& ex) {
				cout << "Syntax Error: " << ex.what() << endl;
			}
			
		}
		else {
			cout << " is not balanced\n";
		}
		cout << "Enter another expression: ";
	}

	// Q2
	TS::Queue numbers;
	numbers.enqueue(20);
	numbers.enqueue(40);
	numbers.enqueue(60);
	numbers.print();
	numbers.dequeue();
	numbers.print();
	numbers.getSize();
	std::cout << "Front : " << numbers.getFront() << std::endl;
	numbers.isEmpty();
	numbers.dequeue();
	numbers.dequeue();
	numbers.print();
	numbers.isEmpty();

	return 0;
};
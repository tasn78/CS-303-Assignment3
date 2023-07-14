// Tom Steinman
// CS303-0001
// Assignment 3
// 7/10/23

#include "Balanced.h"

// Confirms if open brackets / NOT USED
bool is_open(char ch) {
	return OPEN.find(ch) != string::npos;
}

// Confirms if balanced, closed brackets / NOT USED
bool is_close(char ch) {
	return CLOSE.find(ch) != string::npos;
}

// Returns true if balanced, false if not balanced
bool is_balanced(const string& expression) {
	// A stack for the open parentheses that haven't been matched
	stack<char> s;
	bool balanced = true;
	string::const_iterator iter = expression.begin();
	while (balanced && (iter != expression.end())) {
		char next_ch = *iter;
		if (is_open(next_ch)) {
			s.push(next_ch);
		}
		else if (is_close(next_ch)) {
			if (s.empty()) {
				balanced = false;
			}
			else {
				char top_ch = s.top();
				s.pop();
				balanced = OPEN.find(top_ch) == CLOSE.find(next_ch);
			}
		}
		++iter;
	}
	return balanced && s.empty();
}
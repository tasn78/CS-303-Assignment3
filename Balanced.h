// Tom Steinman
// CS303-0001
// Assignment 3
// 7/10/23

#pragma once

#ifndef BALANCED_H_
#define BALANCED_H_


/** Program to check an expression for balanced parentheses. */
#include <stack>
#include <string> 
#include <iostream>

using namespace std;

// The set of opening parentheses.
const string OPEN = "([{";
// The corresponding set of closing parentheses.
const string CLOSE = ")]}";

/* Function to determine whether a character is one of the closing parentheses (defined in constant CLOSE).

@param ch Character to be tested
@return true If the character is a closing parenthesis */

bool is_open(char ch);
bool is_close(char ch);
bool is_balanced(const string& expression);

#endif
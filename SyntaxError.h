#pragma once

#ifndef SYNTAXERROR_H_
#define SYNTAXERROR_H_

#include <stdexcept>

class SyntaxError : public std::invalid_argument {
public :
	SyntaxError(std::string msg) : std::invalid_argument(msg) {}
};

#endif
#include "../includes/RPN.hpp"

RPN::RPN() { }

RPN::RPN(RPN const &src){
	*this = src;
}

RPN::~RPN() { }

RPN &RPN::operator=(RPN const &src){
	if (this != &src)
	{
		this->rpnItens = src.rpnItens;
	}
	return (*this);
}

bool RPN::isOperator(std::string item){
	if (item != "+" && item != "-" && item != "*" && item != "/")
		return (false);
	return (true);
}

bool RPN::validNumber(std::string item){
	for (unsigned int i = 0; i != item.size(); i++)
		if (!isdigit(item[i]))
			return(false);
	int nb = std::atoi(item.c_str());
	if (nb < 0 || nb > 9)
		throw RPN::RPNException("Error: Number out of permitted range");
	return (true);  
}

void RPN::makeOperation(char op){
	double a;
	double b;

	if (rpnItens.size() < 2)
		throw RPN::RPNException("Error: Too few operands");
	a = rpnItens.top();
	rpnItens.pop();
	b = rpnItens.top();
	rpnItens.pop();
	switch (op)
	{
	case '+':
		rpnItens.push(b + a);
		break;
	case '-':
		rpnItens.push(b - a);
		break;
	case '*':
		rpnItens.push(b * a);
		break;
	default:
		if (a == 0)
			throw RPN::RPNException("Error: Division by zero");
		rpnItens.push(b / a);
		break;
	}
}

double RPN::calculator(std::string argument){
	std::string item;
	std::istringstream ss(argument);

	if (argument.find_first_not_of("+-/* 01234567890") != std::string::npos)
		throw RPN::RPNException("Error: Invalid character in expression");
	while (ss >> item){
		if (validNumber(item))
			rpnItens.push(std::strtod(item.c_str(), NULL));
		else if (isOperator(item))
			makeOperation(item[0]);
	}
	if (rpnItens.size() != 1)
		throw RPN::RPNException("Error: Invalid expression");
	return (rpnItens.top());
}

RPN::RPNException::RPNException(const std::string &message) : _message(message) { }

RPN::RPNException::~RPNException() throw() { }

const char *RPN::RPNException::what() const throw(){
	return (this->_message.c_str());
}
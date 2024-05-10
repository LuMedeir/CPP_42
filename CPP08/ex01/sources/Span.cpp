#include "../includes/Span.hpp"

Span::Span(void){};

Span::Span(unsigned int newSize): size(newSize){
	vectorInt.reserve(newSize);
}

Span::Span(Span const &copy){
	*this = copy;
}

Span::~Span(){}

Span &Span::operator=(Span const &copy){
	if (this != &copy){
		this->size = copy.size;
		this->vectorInt = copy.vectorInt;
	}
	return(*this);
}

void Span::addNumber(int n)
{
	if (vectorInt.size() < size)
		vectorInt.push_back(n);
	else
		throw FullSpanException();
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (vectorInt.size() + std::distance(begin, end) <= size){

		while (begin != end){
			addNumber(*begin);
			begin++;
		}
	}
	else
		throw FullSpanException();
}

int Span::shortestSpan(void){
	if (vectorInt.size() <= 1)
		throw NoSpanException();

	int	span = std::abs(vectorInt[0] - vectorInt[1]);
	for (unsigned int i = 0; i < vectorInt.size() - 1; i++){
		for (unsigned int j = i + 1; j < vectorInt.size(); j++)
			if (std::abs(vectorInt[i] - vectorInt[j]) < span)
				span = std::abs(vectorInt[i] - vectorInt[j]);
	}
	return (span);
}

int Span::longestSpan(void){
	if (vectorInt.size() <= 1)
		throw NoSpanException();
	int min = *std::min_element(vectorInt.begin(), vectorInt.end());
	int max = *std::max_element(vectorInt.begin(), vectorInt.end());
	return (max - min);
}

const char* Span::FullSpanException::what() const throw()
{
	return (RED "Span is full" RESET);
}

const char* Span::NoSpanException::what() const throw()
{
	return (RED "Span is empty or has only one element" RESET);
}

#include "../includes/ScalarConverter.hpp"

bool	checkInt(std::string str);
bool	checkFloat(std::string str);
bool	checkDouble(std::string str);
void	printPseudo(std::string str);
void	convertInt(std::string str, int type);
void	convertFloat(std::string str, int type);
void	convertDouble(std::string str, int type);
void	convertChar(std::string str, int type);
int		ScalarConverter::type = 0;

ScalarConverter::ScalarConverter(void){};

ScalarConverter::ScalarConverter(ScalarConverter const &that){
	*this = that;
}

ScalarConverter::~ScalarConverter(void){}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &that){
	type = that.type;
	return(*this);
}

void	ScalarConverter::convert(std::string str){
	if (defineType(str))
		return ;
	switch (type)
	{
	case 0:
		printPseudo(str);
		break;
	case 1:
		convertChar(str, type);
		break;
	case 2:
		convertInt(str, type);
		break;
	case 3:
		convertFloat(str, type);
		break;
	case 4:
		convertDouble(str, type);
		break;
	default:
		break;
	}
}

bool	ScalarConverter::defineType(std::string str){
	std::string pseudos[6] = {"nan", "+inf", "-inf", "nanf", "+inff", "-inff"};
	for (int i = 0; i < 6; i++){
		if (str == pseudos[i]){
			type = PSEUDO;
			return(0);
		}
	}
	if (str.size() == 1 && !isdigit(str[0])){
		type = CHAR;
		return(0);
	}
	if (((str[0] == '+' || str[0] == '-' || isdigit(str[0])) && isdigit(str[1])) 
		|| (str.size() == 1 &&  isdigit(str[0]))){
		if (checkInt(str)){
			type = INT;
			return(0);
		}
		if (checkFloat(str)){
			type = FLOAT;
			return(0);
		}
		if(checkDouble(str)){
			type = DOUBLE;
			return(0);
		}
	}
	std::cout << RED << "Error: " << WHITE << "invalid parameters" << RESET << std::endl;
	return(1);
}

bool	checkInt(std::string str){
	for (unsigned int i = 1; i < str.size(); i++)
		if (!isdigit(str[i]))
			return(0);
	return(1);
}

bool	checkFloat(std::string str){
	int	point = 0;
	unsigned int 	size = str.size();

	for (unsigned int i = 1; i < (size - 1); i++){
		if ((str[i] != '.' && !isdigit(str[i])) || point > 1)
			return(0);
		if (str[i] == '.')
			point++;
	}
	if (str[size - 1] == 'f')
		return(1);
	return(0);
}

bool	checkDouble(std::string str){
	int				point = 0;
	unsigned int	size = str.size();

	for (unsigned int i = 1; i < size ; i++){
		if ((str[i] != '.' && !isdigit(str[i])) || point > 1)
			return(0);
		if (str[i] == '.')
			point++;
	}
	return(1);
}

void printPseudo(std::string str)
{
	std::cout << PURPLE << "char: " << WHITE << "impossible" << RESET << std::endl;//é impossível representar esses valores em char e int, 
	std::cout << PURPLE << "int: " << WHITE << "impossible" << RESET << std::endl;	//já que eles são específicos de números de ponto flutuante
	if (str == "nanf" || str == "nan")
	{
		std::cout << PURPLE << "float: " << WHITE << "nanf" << RESET << std::endl;
		std::cout << PURPLE << "double: " << WHITE << "nan" << RESET << std::endl;
	}
	else if (str == "+inff" || str == "+inf")
	{
		std::cout << PURPLE << "float: " << WHITE << "+inff" << RESET << std::endl;
		std::cout << PURPLE << "double: " << WHITE << "+inf" << RESET << std::endl;
	}
	else if (str == "-inff" || str == "-inf")
	{
		std::cout << PURPLE << "float: " << WHITE << "-inff" << RESET << std::endl;
		std::cout << PURPLE << "double: " << WHITE << "-inf" << RESET << std::endl;
	}
}

void	printChar(std::string str, char c){
	if (atol(str.c_str()) < CHAR_MIN || atol(str.c_str()) > CHAR_MAX)
		std::cout << PURPLE << "char: " << WHITE << "impossible" << RESET << std::endl;
	else if (!isprint(c))
		std::cout << PURPLE << "char: " << WHITE << "Non displayable" << RESET << std::endl;
	else
		std::cout << PURPLE << "char: " << WHITE << "'" << c << "'" << RESET << std::endl;
}

void	printInt(std::string str, int i){
	if (atol(str.c_str()) < INT_MIN || atol(str.c_str()) > INT_MAX)
		std::cout << PURPLE << "int: " << WHITE << "impossible" << RESET << std::endl;
	else
		std::cout << PURPLE << "int: "  << WHITE << i << RESET << std::endl;
}

void	printFloat(std::string str, float f, int type){
	if ((atol(str.c_str()) < INT_MIN || atol(str.c_str()) > INT_MAX) 
		&& (type == INT))
		std::cout << PURPLE << "float: " << WHITE << "impossible" << RESET << std::endl;
	else
		std::cout << PURPLE << "float: " << WHITE << std::fixed << std::setprecision(1) << f << "f" << RESET << std::endl;
}

void	printDouble(std::string str, double d, int type){
	if ((atol(str.c_str()) < INT_MIN || atol(str.c_str()) > INT_MAX) 
		&& (type == INT))
		std::cout << PURPLE << "double: " << WHITE << "impossible" << RESET << std::endl;
	else
		std::cout << PURPLE << "double: " << WHITE << std::fixed << std::setprecision(1) << d << RESET << std::endl;
}

//static_cast: É como se você dissesse ao compilador: "Eu sei o que
//estou fazendo, apenas faça a conversão." Ele é usado para converter
//tipos de dados relacionados, como de int para double, e é verificado
//em tempo de compilação.

void	convertChar(std::string str, int type){
	char c = str[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	printChar(str, c);
	printInt(str, i);
	printFloat(str, f, type);
	printDouble(str, d, type);
}

void	convertInt(std::string str, int type){
	int i = atoi(str.c_str());
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	printChar(str, c);
	printInt(str, i);
	printFloat(str, f, type);
	printDouble(str, d, type);
}

void	convertFloat(std::string str, int type){
	float f = strtof(str.c_str(), NULL);
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	printChar(str, c);
	printInt(str, i);
	printFloat(str, f, type);
	printDouble(str, d, type);
}

void	convertDouble(std::string str, int type){
	double d = strtod(str.c_str(), NULL);
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	printChar(str, c);
	printInt(str, i);
	printFloat(str, f, type);
	printDouble(str, d, type);
}
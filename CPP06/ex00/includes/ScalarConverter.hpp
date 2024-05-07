#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include "Defines.hpp"
# include <limits.h>
# include <cstdlib>
# include <cctype>
# include <iomanip>


// nan: Abreviação de "Not a Number" (não é um número), é usado para 
		//representar resultados de operações inválidas, como dividir zero por 
		//zero ou calcular a raiz quadrada de um número negativo.

//+inf e -inf: Representam infinito positivo e infinito negativo.

//nanf, +inff e -inff: São as versões de ponto flutuante dos anteriores.


# define PSEUDO	0
# define CHAR	1
# define INT	2
# define FLOAT	3
# define DOUBLE	4


class ScalarConverter{
	private:
		static int	type;

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &that);
		~ScalarConverter(void);
		ScalarConverter &operator=(ScalarConverter const &that);

		static bool	defineType(std::string str);
	public:
		static void convert(std::string str);
};

#endif
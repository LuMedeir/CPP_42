#include "../includes/Base.hpp"

Base::~Base(void){};

Base *generate(void){
	switch (rand() % 3)
	{
	case 0:
		return(new A);
	case 1:
		return(new B);
	case 2:
		return(new C);
	default:
		return(NULL);
	}
}

//dynamic_cast: É usado para converter ponteiros
//ou referências de uma classe base para uma classe
//derivada, mas ele verifica se a conversão é segura
//em tempo de execução. Se não for, retorna um ponteiro
//nulo ou lança uma exceção.

void	identify(Base *p){
	if(dynamic_cast<A*>(p))
		std::cout << PURPLE << "It's an A class" << RESET << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << PURPLE << "It's an B class" << RESET << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << PURPLE << "It's an C class" << RESET << std::endl;
	else
		std::cout << RED << "It's a invalid class" << RESET << std::endl;
}

void	identify(Base &p){
	try
	{
		A &a = dynamic_cast<A&>(p); //em caso de falha, ele lança uma exceção do tipo std::bad_cast.
		std::cout << PURPLE << "It's an A class" << RESET << std::endl;
		(void)a;
		return ;
	}
	catch (std::exception &e) {}
	try
	{
		B &b = dynamic_cast<B&>(p); //em caso de falha, ele lança uma exceção do tipo std::bad_cast.
		std::cout << PURPLE << "It's an B class" << RESET << std::endl;
		(void)b;
		return ;
	}
	catch (std::exception &e) {}
	try
	{
		C &c = dynamic_cast<C&>(p); //em caso de falha, ele lança uma exceção do tipo std::bad_cast.
		std::cout << PURPLE << "It's an C class" << RESET << std::endl;
		(void)c;
	}
	catch (std::exception &e) 
	{
		std::cout << RED << "It's a invalid class" << RESET << std::endl;
	}
}
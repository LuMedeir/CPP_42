#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include "Defines.hpp"

class Base
{
	public:
		virtual ~Base(void);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
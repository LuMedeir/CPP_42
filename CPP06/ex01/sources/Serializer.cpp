#include "../includes/Serializer.hpp"

Serializer::Serializer(void){};

Serializer::Serializer(Serializer const &that){
	*this = that;
}

Serializer::~Serializer(void){}

Serializer &Serializer::operator=(Serializer const &that){
	(void)that;
	return(*this);
}

//reinterpret_cast: É como uma "conversão bruta". Ele
//basicamente muda a interpretação dos bits de um tipo
//para outro. Você usa isso quando precisa converter
//entre tipos completamente diferentes, como um ponteiro
//para um inteiro, mas pode causar problemas se usado
//incorretamente.

uintptr_t	Serializer::serialize(Data *ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*>(raw));
}
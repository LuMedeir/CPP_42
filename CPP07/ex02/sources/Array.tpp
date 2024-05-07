#include "../includes/Array.hpp"

template <typename T>
Array<T>::Array(): array(NULL), sizeArray(0){};

template <typename T>
Array<T>::Array(unsigned int n): array(new T[n]), sizeArray(n){};

template <typename T>
Array<T>::Array(Array const &that){
	this->sizeArray = that.sizeArray;
	if (that.array != NULL){
		this->array = new T[that.sizeArray];
		for (unsigned int i = 0; i < this->sizeArray; i++) {
				this->array[i] = that[i];
		}
	}
	else
		this->array = NULL;
}

template <typename T>
Array<T>::~Array(void) {
	delete [] this->array;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &that) {
	if(this != &that){
		this->sizeArray = that.sizeArray;
		if (this->array != NULL) {
			delete[] array;
		}
		if (that.array != NULL){
			this->array = new T[this->size];
			for (unsigned int i = 0; i < this->size; i++) {
				this->array[i] = that[i];
			}
		}
		else
			this->array = NULL;
	}
	return *this;
}

template <typename T>
T	&Array<T>::operator[](unsigned int i) const{
	if (i >= Array<T>::sizeArray) {
		throw outOfRange();
		return this->array[0];
	}
	return this->array[i];
}

template <typename T>
unsigned int	Array<T>::size(void) const{
	return(this->sizeArray);
}
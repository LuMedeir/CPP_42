#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define WHITE "\033[1;37m"
# define CYAN "\033[1;36m"
# define YELLOW "\033[1;33m"
# define PURPLE "\033[1;35m"
# define PINK "\033[95m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"


template <typename T>
class Array{
	private:
		T*				array;
		unsigned int	sizeArray;

	public:
		Array(void);
		Array(Array const& that);
		Array(unsigned int n);
		~Array(void);

		Array&	operator=(Array const& that);
		T&		operator[](unsigned int i) const;

		unsigned int size(void) const;

		class outOfRange : public std::exception {
			public:
				virtual const char *what() const throw(){ 
					return ( RED "Error: Index out of bounds" RESET ); };
		};
};

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
	if (i >= Array<T>::sizeArray)
		throw outOfRange();
	return this->array[i];
}

template <typename T>
unsigned int	Array<T>::size(void) const{
	return(this->sizeArray);
}

#endif
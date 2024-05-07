#include "../includes/Serializer.hpp"

int main(void) {

	std::cout << CYAN << std::endl;
	std::cout << "------------------- SERIALIZATION TEST ---------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------Creating data instance and print your values---------" << std::endl;
	std::cout << "---------------------------------------------------------------\n" << std::endl;
	std::cout << RESET;
	Data *data = new Data("Hello World", 42);
	std::cout << PURPLE << "Data is in pointer: \t" << WHITE << data << RESET << std::endl;
	std::cout << PURPLE << "Private string is: \t\t" << WHITE << data->getString() << RESET << std::endl;
	std::cout << PURPLE << "Private number is: \t\t" << WHITE << data->getNumber() << RESET << std::endl;

	std::cout << CYAN;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Creating raw pointer using reinterpret_cast (serializing)..." << std::endl;
	std::cout << "Printing raw pointer address..." << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << RESET;
	uintptr_t raw = Serializer::serialize(data);
	std::cout << PURPLE << "Raw pointer is: \t\t" << WHITE << raw << RESET << std::endl;

	std::cout << CYAN;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Deserializing raw pointer using reinterpret_cast..." << std::endl;
	std::cout << "Confirming that data pointer is still pointing at the same address..." << std::endl;
	std::cout << "Printing private data and number..." << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << RESET;
	Data *ptr = Serializer::deserialize(raw);
	std::cout << PURPLE <<  "Data is still pointing at: \t" << WHITE << ptr << RESET << std::endl;
	std::cout << PURPLE << "Private data is: \t\t" << WHITE << ptr->getString() << RESET << std::endl;
	std::cout << PURPLE << "Private number is: \t\t" << WHITE << ptr->getNumber() << RESET << std::endl;

	delete data;
	return (0);
}

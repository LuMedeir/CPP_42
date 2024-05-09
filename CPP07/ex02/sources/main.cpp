#include "../includes/Array.hpp" 
# include <sstream>

int main(void)
{
	Array<int> intArray(5);
	Array<std::string> stringArray(5);
	Array<float> floatArray(5);
	Array<double> doubleArray(5);
	Array<char> charArray(5);

	std::cout << std::endl;
	std::cout << WHITE <<"---------------------- ARRAY TEST -----------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------------------- INT TEST ------------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << PURPLE;
	intArray[0] = 1;
	intArray[1] = 2;
	intArray[2] = 3;
	intArray[3] = 4;
	intArray[4] = 5;
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << "                            " << intArray[i] << std::endl;

	std::cout << WHITE;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------------------- STRING TEST ---------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << PURPLE;
	stringArray[0] = "one";
	stringArray[1] = "two";
	stringArray[2] = "three";
	stringArray[3] = "four";
	stringArray[4] = "five";
	for (unsigned int i = 0; i < stringArray.size(); i++)
		std::cout << "                           " << stringArray[i] << std::endl;

	std::cout << WHITE;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------------------- FLOAT TEST ----------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << PURPLE;
	floatArray[0] = 1.1f;
	floatArray[1] = 2.2f;
	floatArray[2] = 3.3f;
	floatArray[3] = 4.4f;
	floatArray[4] = 5.5f;
	for (unsigned int i = 0; i < floatArray.size(); i++)
		std::cout << "                           " << floatArray[i] << std::endl;

	std::cout << WHITE;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------------------- DOUBLE TEST ---------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << PURPLE;
	doubleArray[0] = 1.11;
	doubleArray[1] = 2.22;
	doubleArray[2] = 3.33;
	doubleArray[3] = 4.44;
	doubleArray[4] = 5.55;
	for (unsigned int i = 0; i < doubleArray.size(); i++)
		std::cout << "                           " << doubleArray[i] << std::endl;

	std::cout << WHITE;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------------------- CHAR TEST -----------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << PURPLE;
	charArray[0] = 'a';
	charArray[1] = 'b';
	charArray[2] = 'c';
	charArray[3] = 'd';
	charArray[4] = 'e';
	for (unsigned int i = 0; i < charArray.size(); i++)
		std::cout << "                             " << charArray[i] << std::endl;

	std::cout << WHITE;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------------------- COPY TEST -----------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << PURPLE;

	Array<int> intArrayCopy(intArray);
	intArrayCopy[0] = 42;
	for (unsigned int i = 0; i < intArrayCopy.size(); i++)
		std::cout << PURPLE << "                           " << intArray[i] << WHITE << " - " << PURPLE << intArrayCopy[i] << std::endl;

	std::cout << WHITE;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------------------- ASSIGN TEST ---------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	Array<char> charArrayAssign = charArray;
	charArrayAssign[0] = 'Z';
	for (unsigned int i = 0; i < charArrayAssign.size(); i++)
		std::cout << PURPLE << "                           " << charArray[i] << WHITE << " - " << PURPLE << charArrayAssign[i] << std::endl;

	std::cout << WHITE;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "--------------------- OUT OF BOUNDS TEST ----------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	try
	{
		floatArray[10] = 42.42;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << WHITE;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "--------------------- EMPTY ARRAY TEST ------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	Array<int> emptyArray;
	try
	{
		emptyArray[0] = 42;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
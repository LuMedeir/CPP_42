#include "../includes/Array.hpp" 
# include <sstream>

int main() {
	{
		int *exp = new int();
		::Array<int>	res;
		std::cout << HRED "[           TEST 01           ]" reset << std::endl;
		std::cout << *exp << std::endl;
		std::cout << res[0] << std::endl;
		delete exp;
	}
	{
		int 		size = 5;
		::Array<int>	res(size);
		std::cout << HRED "[           TEST 02           ]" reset << std::endl;
		std::cout << HYEL "[           BEFORE             ]" reset << std::endl;
		res.print();
		for (int i = 0; i < size; i++) {
			res[i] = i + 1;
		}
		std::cout << HYEL "[           AFTER             ]" reset << std::endl;
		res.print();
	}
	{
		int 		size = 5;
		::Array<float>	res(size);
		std::cout << HRED "[           TEST 03           ]" reset << std::endl;
		std::cout << HYEL "[           BEFORE             ]" reset << std::endl;
		res.print();
		for (float i = 0; i < size; i++) {
			res[i] = i + 0.5;
		}
		std::cout << HYEL "[           AFTER             ]" reset << std::endl;
		res.print();
	}
	{
		int 		size = 5;
		::Array<float>	res(size);
		std::cout << HRED "[           Out-of-range           ]" reset << std::endl;
		try {
			res[-2];
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			res[size];
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

// #include <iostream>
// #include <Array.hpp>
// #include <stdio.h>      /* printf, NULL */
// #include <stdlib.h>     /* srand, rand */
// #include <time.h>       /* time */

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
// 	numbers.print();
//     delete [] mirror;//
//     return 0;
// }
#include "../includes/MutantStack.hpp"

int main(void){

	std::cout << PURPLE << std::endl;
	std::cout << "----------------- SUBJECT MUTANTSTACK TEST --------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << PURPLE << std::endl;
	std::cout << "----------------- MY OWN MUTANTSTACK TEST --------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "-------- Display top (top is the last element pushed) ---------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;

	MutantStack<int> mstack1;
	mstack1.push(5);
	mstack1.push(17);
	std::cout << CYAN << "top: " << WHITE << mstack1.top() << RESET << std::endl;

	std::cout << PURPLE << "------------- Create iterator using begin and end -------------" << RESET << std::endl;

	MutantStack<int> mstack2;
	mstack2.push(3);
	mstack2.push(5);
	mstack2.push(737);
	mstack2.push(6);
	MutantStack<int>::iterator itb1 = mstack2.begin();
	std::cout << WHITE << "Stack: 3, 5, 737, 6\n" << RESET << std::endl;
	std::cout << CYAN << "Iterator begin: " << WHITE << *itb1 << RESET << std::endl;
	++itb1;
	std::cout << CYAN << "Increment iterator begin: " << WHITE << *itb1 << RESET << std::endl;
	++itb1;
	std::cout << CYAN << "Increment iterator begin: " << WHITE << *itb1 << RESET << std::endl;

	MutantStack<int>::iterator ite1 = mstack2.end();
	std::cout << CYAN << "\nIterator end: " << WHITE << *--ite1 << RESET << std::endl;
	--ite1;
	std::cout << CYAN << "Decrement iterator end: " << WHITE << *ite1 << RESET << std::endl;
	--ite1;
	std::cout << CYAN << "Decrement iterator end: " << WHITE << *ite1 << RESET << std::endl;
	--ite1;
	std::cout << CYAN << "Decrement iterator end: " << WHITE << *ite1 << RESET << std::endl;


	 std::cout << PURPLE << "---------- Display the mutant stack using iterators -----------" << RESET << std::endl;
	++ite1;
	++ite1;
	++ite1;
	--itb1;
	--itb1;
	while(itb1 < ite1){
		std::cout << WHITE << *itb1 << " ";
		++itb1;
	}
	std::cout << RESET << std::endl;

    std::cout << PURPLE << "------------------------- LIST - INT --------------------------" << std::endl;
	std::cout << "-------- Display top (top is the last element pushed) ---------" << std::endl;
	std::cout << "---------------------------------------------------------------" << RESET << std::endl;

	std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << CYAN << "back: " << WHITE << list.back() << std::endl;
	std::cout << RESET;

	std::cout << PURPLE << "------------- Create iterator using begin and end -------------" << RESET << std::endl;

	std::list<int> list1;
	list1.push_back(3);
    list1.push_back(5);
    list1.push_back(737);
    list1.push_back(6);

	std::list<int>::iterator it2 = list1.begin();
	std::list<int>::iterator ite2 = list1.end();

	std::cout << WHITE << "List: 3, 5, 737, 6\n" << RESET << std::endl;
	std::cout << CYAN << "Iterator begin: " << WHITE << *it2 << RESET << std::endl;
	++it2;
	std::cout << CYAN << "Increment iterator begin: " << WHITE << *it2 << RESET << std::endl;
	++it2;
	std::cout << CYAN << "Increment iterator begin: " << WHITE << *it2 << RESET << std::endl;

	std::cout << CYAN << "\nIterator end: " << WHITE << *--ite2 << RESET << std::endl;
	--ite2;
	std::cout << CYAN << "Decrement iterator end: " << WHITE << *ite2 << RESET << std::endl;
	--ite2;
	std::cout << CYAN << "Decrement iterator end: " << WHITE << *ite2 << RESET << std::endl;
	--ite2;
	std::cout << CYAN << "Decrement iterator end: " << WHITE << *ite2 << RESET << std::endl;

	std::cout << PURPLE << "------------- Display the list using iterators ---------------" << RESET << std::endl;
	++ite2;
	++ite2;
	++ite2;
	--it2;
	--it2;
	while(it2 != ite2){
		std::cout << WHITE << *it2 << " ";
		++it2;
	}
	std::cout << RESET << std::endl;
}
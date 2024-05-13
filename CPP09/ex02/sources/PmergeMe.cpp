#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &that) {
	*this = that;
}

PmergeMe::~PmergeMe() {
}

PmergeMe &PmergeMe::operator=(const PmergeMe &that) {
	if (this != &that){
		this->list = that.list;
		this->deque = that.deque;
	}
	return *this;
}

void	PmergeMe::sort(int argc, char **argv){
	try{
		validNumber(argc, argv);
		sortDeque(argc, argv);
		sortList(argc, argv);
	}
	catch (std::exception & e){
		std::cerr << e.what() << std::endl;
	}
}


void PmergeMe::mergeInsertionSort(std::deque<int> &array) { 
	size_t n = array.size();
	if (n <= 1)
		return;
	std::deque<int> larger, smaller;
	for (size_t i = 0; i < n; i += 2) {
		if (i + 1 < n) {
			larger.push_back(std::max(array[i], array[i + 1]));
			smaller.push_back(std::min(array[i], array[i + 1]));
		}
		else
			larger.push_back(array[i]);
	}
	// Send the larger container to the recursion, to sort it
	mergeInsertionSort(larger);

	int firtstLargerArrayElement = larger[0];
	int smallerNumOfCouple = -1;
	for (size_t i = 0; i < n; i += 2) {
		if (i + 1 < n) {
			if (array[i] == firtstLargerArrayElement || array[i + 1] == firtstLargerArrayElement) {
				smallerNumOfCouple = std::min(array[i], array[i + 1]);
				break;
			}
		}
	}

	array.clear();
	array = larger;
	
	if (smallerNumOfCouple != -1)
		array.push_front(smallerNumOfCouple);
	for (size_t i = 0; i < smaller.size(); ++i) {
		size_t n2 = array.size();
		if (smaller[i] != smallerNumOfCouple || n2 == (n - 1)) {
			std::deque<int>::iterator it = std::lower_bound(array.begin(), array.end(), smaller[i]);
			array.insert(it, smaller[i]);
		}
	}
}

void PmergeMe::mergeInsertionSort(std::list<int> &array)
{
	size_t n =array.size();
	if (n <= 1)
		return;
	std::list<int> larger, smaller;

	std::list<int>::iterator it = array.begin();
	for (size_t i = 0; i < n; i += 2){
		if (i + 1 < n){
			int first = *it++;
			int second = *it++;
			larger.push_back(std::max(first, second));
			smaller.push_back(std::min(first, second));
		}
		else
			larger.push_back(*it++);
	}
 
	mergeInsertionSort(larger);

	int firtstLargerlistElement = larger.front();
	int smallerNumOfCouple = -1;
	it = array.begin();
	for (size_t i = 0; i < n; i += 2){
		if (i + 1 < n){
			int first = *it++;
			int second = *it++;
			if (first == firtstLargerlistElement || second == firtstLargerlistElement){
				smallerNumOfCouple = std::min(first, second);
				break;
			}
		}
	}
	array.clear();
	array = larger;
	if (smallerNumOfCouple != -1)
		array.push_front(smallerNumOfCouple);
	for (std::list<int>::iterator it = smaller.begin(); it != smaller.end(); ++it){
		size_t n2 =array.size();
		if (*it != smallerNumOfCouple || n2 == (n - 1)){
			std::list<int>::iterator pos = std::lower_bound(array.begin(), array.end(), *it);
			array.insert(pos, *it);
		}
	}
}

void PmergeMe::sortDeque(int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i)
		deque.push_back(std::atoi(argv[i]));

	printContainer(deque, "Before");

	clock_t startTime = clock();
	mergeInsertionSort(deque);
	clock_t endTime = clock();
	double dequeTime = double(endTime - startTime)/ CLOCKS_PER_SEC;

	printContainer(deque, "After");
	std::cout << CYAN << "Time to process a range of " << deque.size() << " elements with std::deque:\t"
	<< WHITE << std::fixed << std::setprecision(6) << dequeTime << " us" << RESET << std::endl;
}

void PmergeMe::sortList(int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i)
		list.push_back(std::atoi(argv[i]));
	clock_t startTime = clock();
	mergeInsertionSort(list);
	clock_t endTime = clock();
	double listTime = double(endTime - startTime) / CLOCKS_PER_SEC;

	std::cout << CYAN << "Time to process a range of " << list.size() << " elements with std::list:\t"
	<< WHITE << std::fixed << std::setprecision(6) << listTime << " us" << RESET << std::endl;
}


bool PmergeMe::validNumber(int argc, char **argv) {
	for (int i = 1; i < argc; i++){
		std::string numberstr = argv[i];
		for (unsigned int j = 0; j < numberstr.size(); j++)
			if (!isdigit(numberstr[j]))
				throw std::runtime_error("Invalid Argument");
		long number = std::atol(numberstr.c_str());
		if (number > INT_MAX || number < 0) 
			throw std::runtime_error("Numbers too large");
	}
	return false;
}
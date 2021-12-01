#include <iostream>
#include "vector.hpp"
<<<<<<< HEAD
// #include "vector_iterator.hpp"
// #include "Iterator.hpp"

int main() {
	ft::vector<int> v1;
	ft::vector<int> v2(10);
	//ft::vector<int> v3 = v2;
	ft::vector<int>::iterator it = 0;
	for ( int i = it; i < 10; ++i, ++it) {
		std::cout << *it <<std::endl;
	}
=======
#include <vector>

int main() {
	ft::vector<int> v1;
	//ft::vector<int> v2(1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000);
	//ft::vector<int> v3 = v2;
	//std::vector<int> v4(1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000);
>>>>>>> f2450b805165ef18874b88f39f10050afbffeaf5

	return (0);
}

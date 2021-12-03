#include <iostream>
#include "vector.hpp"

int main() {
	ft::vector<int> v1;
	ft::vector<int> v2(10);
	for (size_t i = 0; i < 5; ++i) {
		v1.push_back(i * 1000);
	}
	ft::vector<int> v3 = v1;
	ft::vector<int>::iterator it;
	int i = 0;
	for (it = v3.begin(); it != v3.end(); ++it, ++i)
		std::cout << " it " << *it << " i " << i << std::endl;
	std::cout << '\n';
}

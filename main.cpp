#include <iostream>
#include "vector.hpp"
#include <vector>
#include <ctime>

     // начальное время
    // здесь должен быть фрагмент кода, время выполнения которого нужно измерить
     // конечное время
     // искомое время

int main() {
	unsigned int std_start_time =  clock();
	std::vector<int> vector;
	std::cout << "STD_SIZE " << vector.size() << std::endl;
	std::cout << "STD_CAPACITY " << vector.size() << std::endl;
	vector.resize(2000000000);
	std::cout << "STD_SIZE " << vector.size() << std::endl;
	std::cout << "STD_CAPACITY " << vector.capacity() << std::endl;
	vector.resize(20);
	std::cout << "STD_SIZE " << vector.size() << std::endl;
	std::cout << "STD_CAPACITY " << vector.capacity() << std::endl;
	vector.~vector();
	unsigned int std_end_time = clock();
	unsigned int std_search_time = std_end_time - std_start_time;

	unsigned int ft_start_time =  clock();
	//ft::vector<int> v1;
	ft::vector<int> v2;
	std::cout << "FT_SIZE " << v2.size() << std::endl;
	std::cout << "FT_CAPACITY " << v2.size() << std::endl;
	v2.resize(2000000000);
	std::cout << "FT_SIZE " << v2.size() << std::endl;
	std::cout << "FT_CAPACITY " << v2.size() << std::endl;
	v2.resize(20);
	std::cout << "FT_SIZE " << v2.size() << std::endl;
	std::cout << "FT_CAPACITY " << v2.capacity() << std::endl;
	v2.~vector();
	unsigned int ft_end_time = clock();
	unsigned int ft_search_time = ft_end_time - ft_start_time;

	std::cout << "STD_TIME " << std_search_time << std::endl;
	std::cout << "FT_TIME " << ft_search_time << std::endl;
	std::cout << "RESULT " << ft_search_time / std_search_time << std::endl;
	// for (size_t i = 0; i < 5; ++i) {
	// 	v1.push_back(i * 1000);
	// }
	// ft::vector<int> v3 = v1;
	// ft::vector<int>::iterator it;
	// int i = 0;
	// for (it = v3.begin(); it != v3.end(); ++it, ++i)
	// 	std::cout << " it " << *it << " i " << i << std::endl;
	//std::cout << '\n';
}

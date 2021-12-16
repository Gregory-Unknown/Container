#include "rbtree.hpp"
#include <iostream>
#include <string>

int main()
{
	// tree<Key, T, value_type, allocator_type, key_compare>
	ft::tree<int, std::string> test;
	test.insert(ft::pair<int, std::string>(8, "test"));
	test.test_show_tree();
	std::cout << "-------------------------------------------------" << std::endl;
	test.insert(ft::pair<int, std::string>(11, "test"));
	test.test_show_tree();
	std::cout << "-------------------------------------------------" << std::endl;
	test.insert(ft::pair<int, std::string>(20, "test"));
	test.test_show_tree();
	std::cout << "-------------------------------------------------" << std::endl;
	test.insert(ft::pair<int, std::string>(25, "test"));
	test.test_show_tree();
	std::cout << "-------------------------------------------------" << std::endl;
	test.insert(ft::pair<int, std::string>(30, "test"));
	test.test_show_tree();
	std::cout << "-------------------------------------------------" << std::endl;
	test.insert(ft::pair<int, std::string>(19, "test"));
	test.test_show_tree();
	std::cout << "-------------------------------------------------" << std::endl;
	test.insert(ft::pair<int, std::string>(18, "test"));
	test.test_show_tree();
	std::cout << "-------------------------------------------------" << std::endl;
	test.insert(ft::pair<int, std::string>(17, "test"));
	test.test_show_tree();
	std::cout << "-------------------------------------------------" << std::endl;


	test.deleteElem(ft::pair<int, std::string>(8, "test"));
	test.test_show_tree();
	std::cout << "-------------------------------------------------" << std::endl;
	test.deleteElem(ft::pair<int, std::string>(30, "test"));
	test.test_show_tree();
	std::cout << "-------------------------------------------------" << std::endl;
	test.deleteElem(ft::pair<int, std::string>(11, "test"));
	test.test_show_tree();
	std::cout << "-------------------------------------------------" << std::endl;
	test.deleteElem(ft::pair<int, std::string>(25, "test"));
	test.test_show_tree();
	std::cout << "-------------------------------------------------" << std::endl;
	test.deleteElem(ft::pair<int, std::string>(19, "test"));
	test.test_show_tree();
	std::cout << "-------------------------------------------------" << std::endl;
	test.deleteElem(ft::pair<int, std::string>(20, "test"));
	test.test_show_tree();
	std::cout << "-------------------------------------------------" << std::endl;
	test.deleteElem(ft::pair<int, std::string>(18, "test"));
	test.test_show_tree();
	std::cout << "-------------------------------------------------" << std::endl;
	test.deleteElem(ft::pair<int, std::string>(17, "test"));
	test.test_show_tree();
	std::cout << "-------------------------------------------------" << std::endl;
	return 0;
}

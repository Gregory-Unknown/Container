#include <iostream>
#include <ctime>
#include "ft.cpp"
#include "std.cpp"
#include <map>
#include "map.hpp"

int main()
{
	// std::cout << "ft_vector" << std::endl;
	// std::cout << "Constructor" << std::endl;
	// std_constructor();
	// ft_constructor();

	// std::cout << "Operator_equal" << std::endl;
	// std_operator_equal();
	// ft_operator_equal();

	// std::cout << "Iterators" << std::endl;
	// std_iterators();
	// ft_iterators();

	// std::cout << "Size" << std::endl;
	// std_size();
	// ft_size();

	// std::cout << "Max_size" << std::endl;
	// ft_max_size();
	// ft_max_size();

	// std::cout << "Resize" << std::endl;
	// std_resize();
	// ft_resize();

	// std::cout << "Capacity" << std::endl;
	// std_capacity();
	// ft_capacity();

	// std::cout << "Empty" << std::endl;
	// std_empty();
	// ft_empty();

	// std::cout << "Reserve" << std::endl;
	// std_reserve();
	// ft_reserve();

	// std::cout << "Operator_index" << std::endl;
	// std_operator_index();
	// ft_operator_index();

	// std::cout << "At" << std::endl;
	// std_at();
	// ft_at();

	// std::cout << "Front" << std::endl;
	// std_front();
	// ft_front();

	// std::cout << "Back" << std::endl;
	// std_back();
	// ft_back();

	// std::cout << "Assign" << std::endl;
	// std_assign();
	// ft_assign();

	// std::cout << "Push_and_Pop_back" << std::endl;
	// std_push_and_pop_back();
	// ft_push_and_pop_back();

	// std::cout << "Insert" << std::endl;
	// std_insert();
	// ft_insert();

	// std::cout << "Erase" << std::endl;
	// std_erase();
	// ft_erase();

	// std::cout << "Swap" << std::endl;
	// std_swap();
	// ft_swap();

	// std::cout << "Clear" << std::endl;
	// std_clear();
	// ft_clear();

	// std::cout << "Get_allocator" << std::endl;
	// std_get_allocator();
	// ft_get_allocator();

	// std::cout << "Stack" << std::endl;

	// std::cout << "Stack_constructor" << std::endl;
	// std_stack_constructor();
	// ft_stack_constructor();

	// std::cout << "Stack_empty" << std::endl;
	// std_stack_empty();
	// ft_stack_empty();

	// std::cout << "Stack_size" << std::endl;
	// std_stack_size();
	// ft_stack_size();

	// std::cout << "Stack_top" << std::endl;
	// std_stack_top();
	// ft_stack_top();

	// std::cout << "Stack_push_and_pop" << std::endl;
	// std_stack_push_and_pop();
	// ft_stack_push_and_pop();
	std::cout << "Map" << std::endl;

	std::cout << "Map contructor :" << std::endl;
	std_map_contructor();
	ft_map_contructor();

	std::cout << "Map equal operator :" << std::endl;
	std_map_equal_operator();
	ft_map_equal_operator();
	unsigned int std_search_time = std_time();
	unsigned int ft_search_time = ft_time();

	std::cout << "TIME "<< std::endl;

	std::cout << "STD_TIME " << std_search_time << std::endl;
	std::cout << "FT_TIME  " << ft_search_time << std::endl;
	std::cout << "RESULT " << ft_search_time / std_search_time << std::endl;
}

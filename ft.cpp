#include <iostream>
#include "vector.hpp"
#include <ctime>
#include "stack.hpp"

unsigned int ft_start_time =  clock();
unsigned int ft_end_time = 0;

void ft_constructor()
{
	unsigned int ft_tmp_time =  clock();
	ft::vector<int> ft_first;
	ft::vector<int> ft_second (4,100);
	ft::vector<int> ft_third (ft_second.begin(),ft_second.end());
	ft::vector<int> ft_fourth (ft_third);

	int ft_ints[] = {16,2,77,29};
	ft::vector<int> ft_fifth (ft_ints, ft_ints + sizeof(ft_ints) / sizeof(int) );

	std::cout << "The contents of ft_fifth are: ";
	for (ft::vector<int>::iterator it = ft_fifth.begin(); it != ft_fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}

void ft_operator_equal()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_foo (3,0);
	ft::vector<int> ft_bar (5,0);

	ft_bar = ft_foo;
	ft_foo = ft::vector<int>();

	std::cout << "Size of ft_foo: " << int(ft_foo.size()) << '\n';
	std::cout << "Size of ft_bar: " << int(ft_bar.size()) << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}

void ft_iterators()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector16;
	for (int i = 1; i <= 5; ++i) ft_vector16.push_back(i);

	std::cout << "ft_vector16 contains:";
	for (ft::vector<int>::iterator it = ft_vector16.begin() ; it != ft_vector16.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "ft_vector16_reverse contains:";
	for (ft::vector<int>::reverse_iterator it = ft_vector16.rbegin(); it != ft_vector16.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft_end_time += (clock() - ft_tmp_time);

}
void ft_size()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector2;
	std::cout << "0. ft_size: " << ft_vector2.size() << '\n';

	for (int i=0; i<10; i++) ft_vector2.push_back(i);
	std::cout << "1. ft_size: " << ft_vector2.size() << '\n';

	ft_vector2.insert (ft_vector2.end(), 10, 100);
	std::cout << "2. ft_size: " << ft_vector2.size() << '\n';

	ft_vector2.pop_back();
	std::cout << "3. ft_size: " << ft_vector2.size() << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_max_size()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector3;
	for (int i=0; i < 10; ++i) ft_vector3.push_back(i);

	std::cout << "ft_size:  " << ft_vector3.size() << "\n";
	std::cout << "ft_capacity:  " << ft_vector3.capacity() << "\n";
	std::cout << "ft_max_size:  " << ft_vector3.max_size() << "\n";

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_resize()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector4;
	for (int i=1; i<10; ++i) ft_vector4.push_back(i);

	ft_vector4.resize(5);
	ft_vector4.resize(8,100);
	ft_vector4.resize(12);

	std::cout << "ft_vector16 contains: ";
	for (size_t i=0; i < ft_vector4.size(); i++)
		std::cout << ' ' << ft_vector4[i];
	std::cout << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_capacity()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector5;
	for (int i=0; i<10; i++) ft_vector5.push_back(i);

	std::cout << "ft_size: " << (int) ft_vector5.size() << '\n';
	std::cout << "ft_capacity: " << (int) ft_vector5.capacity() << '\n';
	std::cout << "ft_max_size: " << (int) ft_vector5.max_size() << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_empty()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector6;
	int ft_sum (0);
	for (int i=1; i <= 10; ++i) ft_vector6.push_back(i);
	while (!ft_vector6.empty())
	{
		ft_sum += ft_vector6.back();
		ft_vector6.pop_back();
	}
	std::cout << "ft_total:  " << ft_sum << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_reserve()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_foo;
	ft::vector<int>::size_type sz = ft_foo.capacity();
	std::cout << "ft_capacity  : " << sz << '\n';
	std::cout << "making foo grow:\n";
	for (int i=0; i<10; ++i) {
		ft_foo.push_back(i);
		if (sz!=ft_foo.capacity()) {
			sz = ft_foo.capacity();
			std::cout << "ft_capacity changed: " << sz << '\n';
		}
	}

	ft::vector<int> ft_bar;
	sz = ft_bar.capacity();
	ft_bar.reserve(10);
	std::cout << "making bar grow:\n";
	for (int i=0; i<10; ++i) {
		ft_bar.push_back(i);
		if (sz!=ft_bar.capacity()) {
			sz = ft_bar.capacity();
			std::cout << "ft_capacity changed: " << sz << '\n';
		}
	}
	ft_end_time += (clock() - ft_tmp_time);
}
void ft_operator_index()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int>ft_vector7 (10);
	ft::vector<int>::size_type sz = ft_vector7.size();
	for (unsigned i=0; i<sz; i++) ft_vector7[i]=i;

	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = ft_vector7[sz-1-i];
		ft_vector7[sz-1-i] = ft_vector7[i];
		ft_vector7[i]=temp;
	}

	std::cout << "std_vector contains:";
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << ft_vector7[i];
	std::cout << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_at()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector8;

	ft_vector8.push_back(78);
	ft_vector8.push_back(16);

	ft_vector8.front() -= ft_vector8.back();

	std::cout << "ft_vector8.front() is now " << ft_vector8.front() << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_front()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector9;

	ft_vector9.push_back(78);
	ft_vector9.push_back(16);

	ft_vector9.front() -= ft_vector9.back();

	std::cout << "ft_vector9.front() is now " << ft_vector9.front() << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}

void ft_back()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector10;

	ft_vector10.push_back(10);

	while (ft_vector10.back() != 0)
	{
		ft_vector10.push_back ( ft_vector10.back() - 1 );
	}

	std::cout << "ft_vector10 contains:";
	for (unsigned i = 0; i < ft_vector10.size(); ++i)
		std::cout << ' ' << ft_vector10[i];
	std::cout << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}

void ft_assign()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_first;
	ft::vector<int> ft_second;
	ft::vector<int> ft_third;

	ft_first.assign (7,100);

	ft::vector<int>::iterator ft_it;
	ft_it = ft_first.begin() + 1;

	ft_second.assign (ft_it, ft_first.end() - 1);

	int ft_ints[] = {1776,7,4};
	ft_third.assign (ft_ints, ft_ints + 3);

	std::cout << "ft_size of first: " << int (ft_first.size()) << '\n';
	std::cout << "ft_size of second: " << int (ft_second.size()) << '\n';
	std::cout << "ft_size of third: " << int (ft_third.size()) << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}

void ft_push_and_pop_back()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector11;

	for (size_t i = 0; i < 100; ++i) {
		ft_vector11.push_back (i * i);
	}
	std::cout << "ft_vector11 " << int(ft_vector11.size()) << " numbers.\n";

	for (size_t i = 0; i < 100; ++i) {
		ft_vector11.pop_back ();
	}
	std::cout << "ft_vector11 " << int(ft_vector11.size()) << " numbers.\n";

	ft_end_time += (clock() - ft_tmp_time);
}

void ft_insert()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector12 (3,100);
	ft::vector<int>::iterator ft_it;

	std::cout << "ft_vector12 contains 1 : ";
	for (ft_it = ft_vector12.begin(); ft_it < ft_vector12.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << '\n';

	ft_it = ft_vector12.begin();
	ft_it = ft_vector12.insert (ft_it, 200);

	std::cout << "ft_vector12 contains 2 : ";
	for (ft_it = ft_vector12.begin(); ft_it < ft_vector12.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << '\n';

	ft_vector12.insert (ft_it, 2, 300);

	std::cout << "ft_vector12 contains 3 : ";
	for (ft_it = ft_vector12.begin(); ft_it < ft_vector12.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << '\n';

	ft_it = ft_vector12.begin();

	ft::vector<int> ft_anothervector(2,400);
	ft_vector12.insert (ft_it + 2, ft_anothervector.begin(), ft_anothervector.end());

	std::cout << "ft_vector12 contains 4 : ";
	for (ft_it = ft_vector12.begin(); ft_it < ft_vector12.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << '\n';

	int ft_array [] = { 501,502,503 };
	ft_vector12.insert (ft_vector12.begin(), ft_array, ft_array + 3);

	std::cout << "ft_vector12 contains 5 : ";
	for (ft_it = ft_vector12.begin(); ft_it < ft_vector12.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}

void ft_erase()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector13;
	for (int i = 1; i <= 10; ++i) ft_vector13.push_back(i);
	std::cout << "ft_vector13 contains: ";
	for (unsigned i = 0; i < ft_vector13.size(); ++i)
		std::cout << ' ' << ft_vector13[i];
	std::cout << '\n';

	ft_vector13.erase (ft_vector13.begin() + 5);
	ft_vector13.erase (ft_vector13.begin(), ft_vector13.begin() + 3);

	std::cout << "ft_vector13 contains: ";
	for (unsigned i = 0; i < ft_vector13.size(); ++i)
		std::cout << ' ' << ft_vector13[i];
	std::cout << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}

void ft_swap()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_foo (3,100);
	ft::vector<int> ft_bar (5,200);

	std::cout << "ft_foo contains: ";
	for (unsigned i = 0; i < ft_foo.size(); ++i)
		std::cout << ' ' << ft_foo[i];
	std::cout << '\n';

	std::cout << "ft_bar contains: ";
	for (unsigned i = 0; i < ft_bar.size(); ++i)
		std::cout << ' ' << ft_bar[i];
	std::cout << '\n';

	ft_foo.swap(ft_bar);

	std::cout << "ft_foo contains: ";
	for (unsigned i = 0; i < ft_foo.size(); ++i)
		std::cout << ' ' << ft_foo[i];
	std::cout << '\n';

	std::cout << "ft_bar contains: ";
	for (unsigned i = 0; i < ft_bar.size(); ++i)
		std::cout << ' ' << ft_bar[i];
	std::cout << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}

void ft_clear()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector14;
	ft_vector14.push_back (100);
	ft_vector14.push_back (200);
	ft_vector14.push_back (300);

	std::cout << "ft_vector14 contains: ";
	for (unsigned i = 0; i < ft_vector14.size(); ++i)
		std::cout << ' ' << ft_vector14[i];
	std::cout << '\n';

	ft_vector14.clear();
	ft_vector14.push_back (1101);
	ft_vector14.push_back (2202);

	std::cout << "ft_vector14 contains: ";
	for (unsigned i = 0; i < ft_vector14.size(); ++i)
		std::cout << ' ' << ft_vector14[i];
	std::cout << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}

void ft_get_allocator()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector15;
	int* ft_p;
	ft_p = ft_vector15.get_allocator().allocate(5);

	for (unsigned int i = 0; i < 5; ++i) ft_vector15.get_allocator().construct(&ft_p[i],i);

	std::cout << "The allocated array contains:";
	for (unsigned int i = 0; i < 5; ++i)
		std::cout << ' ' << ft_p[i];
	std::cout << '\n';

	for (unsigned int i = 0; i < 5; ++i) ft_vector15.get_allocator().destroy(&ft_p[i]);
	ft_vector15.get_allocator().deallocate(ft_p, 5);

	ft_end_time += (clock() - ft_tmp_time);
}

void ft_stack_constructor()
{
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector16 (2,200);

	ft::stack<int> ft_first;
	ft::stack<int,ft::vector<int> > ft_second;
	ft::stack<int,ft::vector<int> > ft_third (ft_vector16);

	std::cout << "size of ft_first: " << ft_first.size() << '\n';
	std::cout << "size of ft_second: " << ft_second.size() << '\n';
	std::cout << "size of ft_third: " << ft_third.size() << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_stack_empty()
{
	unsigned int ft_tmp_time =  clock();

	ft::stack<int> ft_stack1;
	int ft_sum (0);

	for (int i = 1; i <= 10; ++i) ft_stack1.push(i);

	while (!ft_stack1.empty())
	{
		ft_sum += ft_stack1.top();
		ft_stack1.pop();
	}
	std::cout << "total ft_sum : " << ft_sum << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_stack_size()
{
	unsigned int ft_tmp_time =  clock();

	ft::stack<int> ft_stack2;
	std::cout << "0. ft_stack size: " << ft_stack2.size() << '\n';

	for (int i = 0; i < 4; ++i) ft_stack2.push(i);
	std::cout << "1. ft_stack2 size: " << ft_stack2.size() << '\n';

	ft_stack2.pop();
	std::cout << "2. ft_stack2 size: " << ft_stack2.size() << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}

void ft_stack_top()
{
	unsigned int ft_tmp_time =  clock();

	ft::stack<int> ft_stack3;

	ft_stack3.push(10);
	ft_stack3.push(20);

	ft_stack3.top() -= 5;

	std::cout << "ft_stack3.top() is now " << ft_stack3.top() << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_stack_push_and_pop()
{
	unsigned int ft_tmp_time =  clock();

	ft::stack<int> ft_stack4;

	for (int i = 0; i < 5; ++i) ft_stack4.push(i);

	std::cout << "Popping out elements...";
	while (!ft_stack4.empty())
	{
		std::cout << ' ' << ft_stack4.top();
		ft_stack4.pop();
	}
	std::cout << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}
unsigned int ft_time()
{
	return (ft_end_time - ft_start_time);
}

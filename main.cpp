#include <iostream>
#include "vector.hpp"
#include <vector>
#include <iterator>
#include <ctime>

unsigned int std_start_time =  clock();
unsigned int std_end_time = 0;

unsigned int ft_start_time =  clock();
unsigned int ft_end_time = 0;

void ft_constructor()
{
	unsigned int std_tmp_time =  clock();
	std::vector<int> std_first;
	std::vector<int> std_second (4,100);
	std::vector<int> std_third (std_second.begin(),std_second.end());
	std::vector<int> std_fourth (std_third);

	int std_ints[] = {16,2,77,29};
	std::vector<int> std_fifth (std_ints, std_ints + sizeof(std_ints) / sizeof(int) );

	std::cout << "The contents of std_fifth are:";
	for (std::vector<int>::iterator it = std_fifth.begin(); it != std_fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std_end_time += (clock() - std_tmp_time);

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
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_foo (3,0);
	std::vector<int> std_bar (5,0);

	std_bar = std_foo;
	std_foo = std::vector<int>();

	std::cout << "Size of std_foo: " << int(std_foo.size()) << '\n';
	std::cout << "Size of std_bar: " << int(std_bar.size()) << '\n';

	std_end_time += (clock() - std_tmp_time);

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
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector;
	for (int i = 1; i <= 5; ++i) std_vector.push_back(i);

	std::cout << "std_vector contains:";
	for (std::vector<int>::iterator it = std_vector.begin() ; it != std_vector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "std_vector_reverse contains:";
	for (std::vector<int>::reverse_iterator it = std_vector.rbegin() ; it != std_vector.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std_end_time += (clock() - std_tmp_time);

	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector;
	for (int i = 1; i <= 5; ++i) ft_vector.push_back(i);

	std::cout << "ft_vector contains:";
	for (ft::vector<int>::iterator it = ft_vector.begin() ; it != ft_vector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "ft_vector_reverse contains:";
	for (ft::vector<int>::reverse_iterator it = ft_vector.rbegin(); it != ft_vector.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft_end_time += (clock() - ft_tmp_time);

}
void ft_size()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector;
	std::cout << "0. std_size: " << std_vector.size() << '\n';

	for (int i=0; i<10; i++) std_vector.push_back(i);
	std::cout << "1. std_size: " << std_vector.size() << '\n';

	std_vector.insert (std_vector.end(),10 , 100);
	std::cout << "2. std_size: " << std_vector.size() << '\n';

	std_vector.pop_back();
	std::cout << "3. std_size: " << std_vector.size() << '\n';

	std_end_time += (clock() - std_tmp_time);

	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector;
	std::cout << "0. ft_size: " << ft_vector.size() << '\n';

	for (int i=0; i<10; i++) ft_vector.push_back(i);
	std::cout << "1. ft_size: " << ft_vector.size() << '\n';

	ft_vector.insert (ft_vector.end(), 10, 100);
	std::cout << "2. ft_size: " << ft_vector.size() << '\n';

	ft_vector.pop_back();
	std::cout << "3. ft_size: " << ft_vector.size() << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_max_size()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector;
	for (int i=0; i < 10; ++i) std_vector.push_back(i);

	std::cout << "std_size: " << std_vector.size() << "\n";
	std::cout << "std_capacity: " << std_vector.capacity() << "\n";
	std::cout << "std_max_size: " << std_vector.max_size() << "\n";

	std_end_time += (clock() - std_tmp_time);
	
	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector;
	for (int i=0; i < 10; ++i) ft_vector.push_back(i);

	std::cout << "ft_size:  " << ft_vector.size() << "\n";
	std::cout << "ft_capacity:  " << ft_vector.capacity() << "\n";
	std::cout << "ft_max_size:  " << ft_vector.max_size() << "\n";

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_resize()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector;
	for (int i=1; i<10; ++i) std_vector.push_back(i);

	std_vector.resize(5);
	std_vector.resize(8,100);
	std_vector.resize(12);

	std::cout << "std_vector contains:";
	for (size_t i=0; i < std_vector.size(); i++)
		std::cout << ' ' << std_vector[i];
	std::cout << '\n';

	std_end_time += (clock() - std_tmp_time);

	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector;
	for (int i=1; i<10; ++i) ft_vector.push_back(i);

	ft_vector.resize(5);
	ft_vector.resize(8,100);
	ft_vector.resize(12);

	std::cout << "ft_vector contains: ";
	for (size_t i=0; i < ft_vector.size(); i++)
		std::cout << ' ' << ft_vector[i];
	std::cout << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_capacity()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector;
	for (int i=0; i<10; i++) std_vector.push_back(i);

	std::cout << "std_size: " << (int) std_vector.size() << '\n';
	std::cout << "std_capacity: " << (int) std_vector.capacity() << '\n';
	std::cout << "std_max_size: " << (int) std_vector.max_size() << '\n';

	std_end_time += (clock() - std_tmp_time);

	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector;
	for (int i=0; i<10; i++) ft_vector.push_back(i);

	std::cout << "ft_size: " << (int) ft_vector.size() << '\n';
	std::cout << "ft_capacity: " << (int) ft_vector.capacity() << '\n';
	std::cout << "ft_max_size: " << (int) ft_vector.max_size() << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_empty()
{
	unsigned int std_tmp_time =  clock();
	
	std::vector<int> std_vector;
	std_vector.clear();
	int std_sum (0);
	for (int i=1; i <= 10; ++i) std_vector.push_back(i);
	while (!std_vector.empty())
	{
		std_sum += std_vector.back();
		std_vector.pop_back();
	}
	std::cout << "std_total: " << std_sum << '\n';

	std_end_time += (clock() - std_tmp_time);

	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector;
	int ft_sum (0);
	for (int i=1; i <= 10; ++i) ft_vector.push_back(i);
	while (!ft_vector.empty())
	{
		ft_sum += ft_vector.back();
		ft_vector.pop_back();
	}
	std::cout << "ft_total:  " << ft_sum << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_reserve()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int>::size_type sz;
	std::vector<int> std_foo;
	sz = std_foo.capacity();
	std::cout << "std_capacity: " << sz << '\n';
	std::cout << "making foo grow:\n";
	for (int i=0; i<10; ++i) {
		std_foo.push_back(i);
		if (sz!=std_foo.capacity()) {
			sz = std_foo.capacity();
			std::cout << "std_capacity changed: " << sz << '\n';
		}
	}

	std::vector<int> std_bar;
	sz = std_bar.capacity();
	std_bar.reserve(10); 
	std::cout << "making bar grow:\n";
	for (int i=0; i<10; ++i) {
		std_bar.push_back(i);
		if (sz!=std_bar.capacity()) {
			sz = std_bar.capacity();
			std::cout << "std_capacity changed: " << sz << '\n';
		}
	}

	std_end_time += (clock() - std_tmp_time);

	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_foo;
	sz = ft_foo.capacity();
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
	unsigned int std_tmp_time =  clock();

	std::vector<int>std_vector (10);

	std::vector<int>::size_type sz = std_vector.size();
	for (unsigned i=0; i<sz; i++) std_vector[i]=i;

	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = std_vector[sz-1-i];
		std_vector[sz-1-i]=std_vector[i];
		std_vector[i]=temp;
	}

	std::cout << "std_vector contains:";
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << std_vector[i];
	std::cout << '\n';

	std_end_time += (clock() - std_tmp_time);

	unsigned int ft_tmp_time =  clock();
	
	ft::vector<int>ft_vector (10);
	sz = ft_vector.size();
	for (unsigned i=0; i<sz; i++) ft_vector[i]=i;
	
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = ft_vector[sz-1-i];
		ft_vector[sz-1-i] = ft_vector[i];
		ft_vector[i]=temp;
	}

	std::cout << "std_vector contains:";
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << ft_vector[i];
	std::cout << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_at()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector;

	std_vector.push_back(78);
	std_vector.push_back(16);

	std_vector.front() -= std_vector.back();

	std::cout << "std_vector.front() is now " << std_vector.front() << '\n';

	std_end_time += (clock() - std_tmp_time);

	unsigned int ft_tmp_time =  clock();
	
	ft::vector<int> ft_vector;

	ft_vector.push_back(78);
	ft_vector.push_back(16);

	ft_vector.front() -= ft_vector.back();

	std::cout << "ft_vector.front() is now " << ft_vector.front() << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_front()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector;

	std_vector.push_back(78);
	std_vector.push_back(16);

	std_vector.front() -= std_vector.back();

	std::cout << "std_vector.front() is now " << std_vector.front() << '\n';

	std_end_time += (clock() - std_tmp_time);

	unsigned int ft_tmp_time =  clock();
	
	ft::vector<int> ft_vector;

	ft_vector.push_back(78);
	ft_vector.push_back(16);

	ft_vector.front() -= ft_vector.back();

	std::cout << "ft_vector.front() is now " << ft_vector.front() << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}
void ft_back()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector;

	std_vector.push_back(10);

	while (std_vector.back() != 0)
	{
		std_vector.push_back ( std_vector.back() - 1 );
	}

	std::cout << "std_vector contains:";
	for (unsigned i = 0; i < std_vector.size(); ++i)
		std::cout << ' ' << std_vector[i];
	std::cout << '\n';

	std_end_time += (clock() - std_tmp_time);

	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector;

	ft_vector.push_back(10);

	while (ft_vector.back() != 0)
	{
		ft_vector.push_back ( ft_vector.back() - 1 );
	}

	std::cout << "ft_vector contains:";
	for (unsigned i = 0; i < ft_vector.size(); ++i)
		std::cout << ' ' << ft_vector[i];
	std::cout << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}

void ft_assign()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_first;
	std::vector<int> std_second;
	std::vector<int> std_third;

	std_first.assign (7,100);

	std::vector<int>::iterator it;
	it=std_first.begin()+1;

	std_second.assign (it,std_first.end()-1);

	int std_ints[] = {1776,7,4};
	std_third.assign (std_ints,std_ints+3);

	std::cout << "std_size of first: " << int (std_first.size()) << '\n';
	std::cout << "std_size of second: " << int (std_second.size()) << '\n';
	std::cout << "std_size of third: " << int (std_third.size()) << '\n';

	std_end_time += (clock() - std_tmp_time);

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
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector;

	for (size_t i = 0; i < 100; ++i) {
		std_vector.push_back (i * i);
	}
	std::cout << "std_vector " << int(std_vector.size()) << " numbers.\n";

	for (size_t i = 0; i < 100; ++i) {
		std_vector.pop_back ();
	}
	std::cout << "std_vector " << int(std_vector.size()) << " numbers.\n";

	std_end_time += (clock() - std_tmp_time);

	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector;

	for (size_t i = 0; i < 100; ++i) {
		ft_vector.push_back (i * i);
	}
	std::cout << "ft_vector " << int(ft_vector.size()) << " numbers.\n";

	for (size_t i = 0; i < 100; ++i) {
		ft_vector.pop_back ();
	}
	std::cout << "ft_vector " << int(ft_vector.size()) << " numbers.\n";

	ft_end_time += (clock() - ft_tmp_time);
}

void ft_insert()
{
	unsigned int std_tmp_time =  clock();

	ft::vector<int> std_vector (3,100);
	ft::vector<int>::iterator iter;
	std::cout << "std_vector contains 1 :";
	for (iter = std_vector.begin(); iter < std_vector.end(); iter++)
		std::cout << ' ' << *iter;
	std::cout << '\n';

	iter = std_vector.begin();
	iter = std_vector.insert ( iter , 200 );

	std::cout << "std_vector contains 2 :";
	for (iter = std_vector.begin(); iter < std_vector.end(); iter++)
		std::cout << ' ' << *iter;
	std::cout << '\n';

	std_vector.insert (iter,2,300);

	std::cout << "std_vector contains 3 :";
	for (iter = std_vector.begin(); iter < std_vector.end(); iter++)
		std::cout << ' ' << *iter;
	std::cout << '\n';

	iter = std_vector.begin();

	ft::vector<int> anothervector1 (2,400);
	std_vector.insert (iter + 2,anothervector1.begin(), anothervector1.end());

	std::cout << "std_vector contains 4 :";
	for (iter = std_vector.begin(); iter < std_vector.end(); iter++)
		std::cout << ' ' << *iter;
	std::cout << '\n';

	int std_array1 [] = { 501,502,503 };
	std_vector.insert(std_vector.begin(), std_array1, std_array1 + 3);

	std::cout << "std_vector contains 5 :";
	for (iter = std_vector.begin(); iter < std_vector.end(); iter++)
		std::cout << ' ' << *iter;
	std::cout << '\n';

	std_end_time += (clock() - std_tmp_time);

	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector (3,100);
	ft::vector<int>::iterator ft_it;

	std::cout << "ft_vector contains 1 : ";
	for (ft_it = ft_vector.begin(); ft_it < ft_vector.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << '\n';

	ft_it = ft_vector.begin();
	ft_it = ft_vector.insert (ft_it, 200);

	std::cout << "ft_vector contains 2 : ";
	for (ft_it = ft_vector.begin(); ft_it < ft_vector.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << '\n';

	ft_vector.insert (ft_it, 2, 300);

	std::cout << "ft_vector contains 3 : ";
	for (ft_it = ft_vector.begin(); ft_it < ft_vector.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << '\n';

	ft_it = ft_vector.begin();

	ft::vector<int> ft_anothervector(2,400);
	ft_vector.insert (ft_it + 2, ft_anothervector.begin(), ft_anothervector.end());

	std::cout << "ft_vector contains 4 : ";
	for (ft_it = ft_vector.begin(); ft_it < ft_vector.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << '\n';

	int ft_array [] = { 501,502,503 };
	ft_vector.insert (ft_vector.begin(), ft_array, ft_array + 3);

	std::cout << "ft_vector contains 5 : ";
	for (ft_it = ft_vector.begin(); ft_it < ft_vector.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}

void ft_erase()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector;
	for (int i = 1; i <= 10; ++i) std_vector.push_back(i);
	std::cout << "std_vector contains:";
	for (unsigned i = 0; i < std_vector.size(); ++i)
		std::cout << ' ' << std_vector[i];
	std::cout << '\n';

	std_vector.erase (std_vector.begin() + 5);
	std_vector.erase (std_vector.begin(), std_vector.begin() + 3);

	std::cout << "std_vector contains:";
	for (unsigned i = 0; i < std_vector.size(); ++i)
		std::cout << ' ' << std_vector[i];
	std::cout << '\n';

	std_end_time += (clock() - std_tmp_time);

	unsigned int ft_tmp_time =  clock();
	
	ft::vector<int> ft_vector;
	for (int i = 1; i <= 10; ++i) ft_vector.push_back(i);
	std::cout << "ft_vector contains: ";
	for (unsigned i = 0; i < ft_vector.size(); ++i)
		std::cout << ' ' << ft_vector[i];
	std::cout << '\n';

	ft_vector.erase (ft_vector.begin() + 5);
	ft_vector.erase (ft_vector.begin(), ft_vector.begin() + 3);

	std::cout << "ft_vector contains: ";
	for (unsigned i = 0; i < ft_vector.size(); ++i)
		std::cout << ' ' << ft_vector[i];
	std::cout << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}

void ft_swap()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_foo (3,100);
	std::vector<int> std_bar (5,200);

	std::cout << "std_foo contains:";
	for (unsigned i = 0; i < std_foo.size(); ++i)
		std::cout << ' ' << std_foo[i];
	std::cout << '\n';

	std::cout << "std_bar contains:";
	for (unsigned i = 0; i < std_bar.size(); ++i)
		std::cout << ' ' << std_bar[i];
	std::cout << '\n';

	std_foo.swap(std_bar);

	std::cout << "std_foo contains:";
	for (unsigned i = 0; i < std_foo.size(); ++i)
		std::cout << ' ' << std_foo[i];
	std::cout << '\n';

	std::cout << "std_bar contains:";
	for (unsigned i = 0; i < std_bar.size(); ++i)
		std::cout << ' ' << std_bar[i];
	std::cout << '\n';

	std_end_time += (clock() - std_tmp_time);

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
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector;
	std_vector.push_back (100);
	std_vector.push_back (200);
	std_vector.push_back (300);

	std::cout << "std_vector contains:";
	for (unsigned i = 0; i < std_vector.size(); ++i)
		std::cout << ' ' << std_vector[i];
	std::cout << '\n';

	std_vector.clear();
	std_vector.push_back (1101);
	std_vector.push_back (2202);

	std::cout << "std_vector contains:";
	for (unsigned i = 0; i < std_vector.size(); ++i)
		std::cout << ' ' << std_vector[i];
	std::cout << '\n';

	std_end_time += (clock() - std_tmp_time);

	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector;
	ft_vector.push_back (100);
	ft_vector.push_back (200);
	ft_vector.push_back (300);

	std::cout << "ft_vector contains: ";
	for (unsigned i = 0; i < ft_vector.size(); ++i)
		std::cout << ' ' << ft_vector[i];
	std::cout << '\n';

	ft_vector.clear();
	ft_vector.push_back (1101);
	ft_vector.push_back (2202);

	std::cout << "ft_vector contains: ";
	for (unsigned i = 0; i < ft_vector.size(); ++i)
		std::cout << ' ' << ft_vector[i];
	std::cout << '\n';

	ft_end_time += (clock() - ft_tmp_time);
}

void ft_get_allocator()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector;
	int* std_p;
	std_p = std_vector.get_allocator().allocate(5);

	for (unsigned int i = 0; i < 5; ++i) std_vector.get_allocator().construct(&std_p[i],i);

	std::cout << "The allocated array contains:";
	for (unsigned int i = 0; i < 5; ++i)
		std::cout << ' ' << std_p[i];
	std::cout << '\n';

	for (unsigned int i = 0; i < 5; ++i) std_vector.get_allocator().destroy(&std_p[i]);
	std_vector.get_allocator().deallocate(std_p, 5);

	std_end_time += (clock() - std_tmp_time);

	unsigned int ft_tmp_time =  clock();

	ft::vector<int> ft_vector;
	int* ft_p;
	ft_p = ft_vector.get_allocator().allocate(5);

	for (unsigned int i = 0; i < 5; ++i) ft_vector.get_allocator().construct(&ft_p[i],i);

	std::cout << "The allocated array contains:";
	for (unsigned int i = 0; i < 5; ++i)
		std::cout << ' ' << ft_p[i];
	std::cout << '\n';

	for (unsigned int i = 0; i < 5; ++i) ft_vector.get_allocator().destroy(&ft_p[i]);
	ft_vector.get_allocator().deallocate(ft_p, 5);

	ft_end_time += (clock() - ft_tmp_time);
}

int main()
{
	// std::cout << "ft_constructor" << std::endl;
	// ft_constructor();

	// std::cout << "ft_operator_equal" << std::endl;
	// ft_operator_equal();

	// std::cout << "ft_iterators" << std::endl;
	// ft_iterators();

	// std::cout << "ft_size" << std::endl;
	// ft_size();

	// std::cout << "ft_max_size" << std::endl;
	// ft_max_size();

	// std::cout << "ft_resize" << std::endl;
	// ft_resize();

	// std::cout << "ft_capacity" << std::endl;
	// ft_capacity();

	// std::cout << "ft_empty" << std::endl;
	// ft_empty();

	// std::cout << "ft_reserve" << std::endl;
	// ft_reserve();
	
	// std::cout << "ft_operator_index" << std::endl;
	// ft_operator_index();

	// std::cout << "ft_at" << std::endl;
	// ft_at();

	// std::cout << "ft_front" << std::endl;
	// ft_front();

	// std::cout << "ft_back" << std::endl;
	// ft_back();

	// std::cout << "ft_assign" << std::endl;
	// ft_assign();

	// std::cout << "ft_push_and_pop_back" << std::endl;
	// ft_push_and_pop_back();

	// std::cout << "ft_insert" << std::endl;
	// ft_insert();

	// std::cout << "ft_erase" << std::endl;
	// ft_erase();

	// std::cout << "ft_swap" << std::endl;
	// ft_swap();

	// std::cout << "ft_clear" << std::endl;
	// ft_clear();

	// std::cout << "ft_get_allocator" << std::endl;
	// ft_get_allocator();


	unsigned int std_search_time = std_end_time - std_start_time;
	unsigned int ft_search_time = ft_end_time - ft_start_time;

	std::cout << "STD_TIME " << std_search_time << std::endl;
	std::cout << "FT_TIME  " << ft_search_time << std::endl;
	std::cout << "RESULT " << ft_search_time / std_search_time << std::endl;
}

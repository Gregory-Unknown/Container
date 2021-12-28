#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>
#include <stack>
#include <map>

unsigned int std_start_time =  clock();
unsigned int std_end_time = 0;


void std_constructor()
{
	unsigned int std_tmp_time =  clock();
	std::vector<int> std_first;
	std::vector<int> std_second (4,100);
	std::vector<int> std_third (std_second.begin(),std_second.end());
	std::vector<int> std_fourth (std_third);

	int std_ints[] = {16,2,77,29};
	std::vector<int> std_fistdh (std_ints, std_ints + sizeof(std_ints) / sizeof(int) );

	std::cout << "The contents of std_fistdh are:";
	for (std::vector<int>::iterator it = std_fistdh.begin(); it != std_fistdh.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std_end_time += (clock() - std_tmp_time);
}

void std_operator_equal()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_foo (3,0);
	std::vector<int> std_bar (5,0);

	std_bar = std_foo;
	std_foo = std::vector<int>();

	std::cout << "Size of std_foo: " << int(std_foo.size()) << '\n';
	std::cout << "Size of std_bar: " << int(std_bar.size()) << '\n';

	std_end_time += (clock() - std_tmp_time);
}

void std_iterators()
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

}
void std_size()
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
}
void std_max_size()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector;
	for (int i=0; i < 10; ++i) std_vector.push_back(i);

	std::cout << "std_size: " << std_vector.size() << "\n";
	std::cout << "std_capacity: " << std_vector.capacity() << "\n";
	std::cout << "std_max_size: " << std_vector.max_size() << "\n";

	std_end_time += (clock() - std_tmp_time);
}
void std_resize()
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
}
void std_capacity()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector;
	for (int i=0; i<10; i++) std_vector.push_back(i);

	std::cout << "std_size: " << (int) std_vector.size() << '\n';
	std::cout << "std_capacity: " << (int) std_vector.capacity() << '\n';
	std::cout << "std_max_size: " << (int) std_vector.max_size() << '\n';

	std_end_time += (clock() - std_tmp_time);
}
void std_empty()
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
}
void std_reserve()
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
}
void std_operator_index()
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
}
void std_at()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector;

	std_vector.push_back(78);
	std_vector.push_back(16);

	std_vector.front() -= std_vector.back();

	std::cout << "std_vector.front() is now " << std_vector.front() << '\n';

	std_end_time += (clock() - std_tmp_time);
}
void std_front()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector;

	std_vector.push_back(78);
	std_vector.push_back(16);

	std_vector.front() -= std_vector.back();

	std::cout << "std_vector.front() is now " << std_vector.front() << '\n';

	std_end_time += (clock() - std_tmp_time);
}
void std_back()
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
}

void std_assign()
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
}

void std_push_and_pop_back()
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
}

void std_insert()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector (3,100);
	std::vector<int>::iterator iter;
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

	std::vector<int> anothervector1 (2,400);
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
}

void std_erase()
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
}

void std_swap()
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
}

void std_clear()
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
}

void std_get_allocator()
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
}

void std_stack_constructor()
{
	unsigned int std_tmp_time =  clock();

	std::vector<int> std_vector (2,200);

	std::stack<int> std_first;
	std::stack<int,std::vector<int> > std_second;
	std::stack<int,std::vector<int> > std_third (std_vector);

	std::cout << "size of std_first: " << std_first.size() << '\n';
	std::cout << "size of std_second: " << std_second.size() << '\n';
	std::cout << "size of std_third: " << std_third.size() << '\n';

	std_end_time += (clock() - std_tmp_time);
}
void std_stack_empty()
{
	unsigned int std_tmp_time =  clock();

	std::stack<int> std_stack;
	int std_sum (0);

	for (int i = 1;i <= 10; ++i) std_stack.push(i);

	while (!std_stack.empty())
	{
		std_sum += std_stack.top();
		std_stack.pop();
	}

  	std::cout << "total std_sum : " << std_sum << '\n';

	std_end_time += (clock() - std_tmp_time);
}
void std_stack_size()
{
	unsigned int std_tmp_time =  clock();

	std::stack<int> std_stack;
	std::cout << "0. std_stack size: " << std_stack.size() << '\n';

	for (int i = 0; i < 5; ++i) std_stack.push(i);
	std::cout << "1. std_stack size: " << std_stack.size() << '\n';

	std_stack.pop();
	std::cout << "2. std_stack size: " << std_stack.size() << '\n';

	std_end_time += (clock() - std_tmp_time);
}

void std_stack_top()
{
	unsigned int std_tmp_time =  clock();

	std::stack<int> std_stack;

	std_stack.push(10);
	std_stack.push(20);

	std_stack.top() -= 5;

	std::cout << "std_stack.top() is now " << std_stack.top() << '\n';

	std_end_time += (clock() - std_tmp_time);
}
void std_stack_push_and_pop()
{
	unsigned int std_tmp_time =  clock();

	std::stack<int> std_stack;

	for (int i = 0; i < 5; ++i) std_stack.push(i);

	std::cout << "Popping out elements...";
	while (!std_stack.empty())
	{
		std::cout << ' ' << std_stack.top();
		std_stack.pop();
	}
	std::cout << '\n';

	std_end_time += (clock() - std_tmp_time);
}
void std_map_contructor()
{
	unsigned int std_tmp_time =  clock();
	std::map<char,int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	std::map<char,int> second (first.begin(),first.end());

	std::map<char,int> third (second);

	for (std::map<char,int>::iterator it = first.begin(); it != first.end(); ++it) {
		std::cout << "std " << it->first << " => " << it->second << std::endl;
	}
	std::cout << std::endl;
	for (std::map<char,int>::iterator it = second.begin(); it != second.end(); ++it) {
		std::cout << "std " << it->first << " => " << it->second << std::endl;
	}
	std::cout << std::endl;
	for (std::map<char,int>::iterator it = third.begin(); it != third.end(); ++it) {
		std::cout << "std " << it->first << " => " << it->second << std::endl;
	}
	std::cout << std::endl;
	std_end_time += (clock() - std_tmp_time);
}
void std_map_equal_operator()
{
	unsigned int std_tmp_time =  clock();
	std::map<char,int> first;
	std::map<char,int> second;

	first['x']=8;
	first['y']=16;
	first['z']=32;

	second = first;
	first = std::map<char,int>();
	std::cout << std::endl;
	std::cout << "std size of first: " << first.size() << '\n';
	std::cout << "std size of second: " << second.size() << '\n';
	std::cout << std::endl;
	for (std::map<char,int>::iterator it = first.begin(); it != first.end(); ++it) {
		std::cout << it->first << " => " << it->second << std::endl;
	}
	std::cout << std::endl;
	for (std::map<char,int>::iterator it = second.begin(); it != second.end(); ++it) {
		std::cout << it->first << " => " << it->second << std::endl;
	}

	std_end_time += (clock() - std_tmp_time);
}
unsigned int std_time()
{
	return (std_end_time - std_start_time);
}

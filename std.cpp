#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>
#include <stack>
#include <map>
#include <set>

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
void std_map_iterator()
{
	unsigned int std_tmp_time = clock();
	std::map<char,int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	first['e']=10;
	first['f']=30;
	first['g']=50;
	first['h']=70;

	for (std::map<char,int>::iterator it = first.begin(); it != first.end(); ++it) {
		std::cout << "std " << it->first << " => " << it->second << std::endl;
	}
	std::cout << std::endl;
	std::map<char,int>::iterator tmp = first.end();
	--tmp;
	for (std::map<char,int>::iterator it = tmp; it != first.begin(); --it) {
		std::cout << "std " << it->first << " => " << it->second << std::endl;
	}
	std::cout << std::endl;
	for (std::map<char,int>::reverse_iterator it = first.rbegin(); it != first.rend(); ++it) {
		std::cout << "std " << it->first << " => " << it->second << std::endl;
	}
	std::cout << std::endl;

	std::map<char,int>::reverse_iterator tmp2 = first.rend();
	--tmp2;
	for (std::map<char,int>::reverse_iterator it = tmp2; it != first.rbegin(); --it) {
		std::cout << "std " << it->first << " => " << it->second << std::endl;
	}

	std_end_time += (clock() - std_tmp_time);
}
void std_map_empty()
{
	unsigned int std_tmp_time = clock();
	std::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}
	std_end_time += (clock() - std_tmp_time);
}
void std_map_size()
{
	unsigned int std_tmp_time = clock();
	std::map<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_map_max_size()
{
	unsigned int std_tmp_time = clock();
	int i;
	std::map<int,int> mymap;

	if (mymap.max_size()>1000)
	{
		for (i=0; i<1000; i++) mymap[i]=0;
		std::cout << "The map contains 1000 elements.\n";
	}
	else std::cout << "The map could not hold 1000 elements.\n";
	std_end_time += (clock() - std_tmp_time);
}
void std_map_operator_index()
{
	unsigned int std_tmp_time = clock();
	std::map<char,std::string> mymap;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "std map now contains " << mymap.size() << " elements.\n";
	std_end_time += (clock() - std_tmp_time);
}
void std_map_insert()
{
	unsigned int std_tmp_time = clock();
	std::cout << "STD" << std::endl;
	std::map<char,int> mymap;

	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('z',200) );

	std::pair<std::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	std::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, std::pair<char,int>('b',300));
	mymap.insert (it, std::pair<char,int>('c',400));

	std::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_map_erase()
{
	unsigned int std_tmp_time = clock();
	std::map<char,int> mymap;
	std::map<char,int>::iterator it;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);

	mymap.erase ('c');
	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );

	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << "STD " << it->first << " => " << it->second << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_map_swap()
{
	unsigned int std_tmp_time = clock();
	std::cout << "STD" << std::endl;
	std::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_map_clear()
{
	unsigned int std_tmp_time =  clock();
	std::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "std map contains:\n";
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;

	std::cout << "std map contains:\n";
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_map_key_comp()
{
	unsigned int std_tmp_time =  clock();
	std::map<char,int> mymap;

	std::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	std::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_map_value_comp()
{
	unsigned int std_tmp_time =  clock();
	std::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	std::cout << "std map contains:\n";

	std::pair<char,int> highest = *mymap.rbegin();

	std::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );
	std_end_time += (clock() - std_tmp_time);
}
void std_map_find()
{
	unsigned int std_tmp_time =  clock();
	std::map<char,int> mymap;
	std::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);

	std::cout << "elements in std map:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_map_count()
{
	unsigned int std_tmp_time =  clock();
	std::map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c) > 0)
			std::cout << " is an element of std map.\n";
		else
			std::cout << " is not an element of std map.\n";
	}
	std_end_time += (clock() - std_tmp_time);
}
void std_map_lower_bound()
{
	unsigned int std_tmp_time =  clock();
	std::map<char,int> mymap;
	std::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');
	itup=mymap.upper_bound ('d');

	mymap.erase(itlow,itup);
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_map_upper_bound()
{
	unsigned int std_tmp_time =  clock();
	std::map<char,int> mymap;
	std::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');
	itup=mymap.upper_bound ('d');

	mymap.erase(itlow,itup);

	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_map_equal_range()
{
	unsigned int std_tmp_time =  clock();
	std::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_map_get_allocator()
{
	unsigned int std_tmp_time =  clock();
	int psize;
	std::map<char,int> mymap;
	std::pair<const char,int>* p;

	p=mymap.get_allocator().allocate(5);
	psize = sizeof(std::map<char,int>::value_type)*5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	mymap.get_allocator().deallocate(p,5);
	std_end_time += (clock() - std_tmp_time);
}
void std_set_contructor()
{
	unsigned int std_tmp_time =  clock();

	std::set<int> first;
	int myints[]= {10,20,30,40,50};
	std::set<int> second (myints, myints+5);
	first = second;

	std::set<int> third (second);

	std::set<int> fourth (second.begin(), second.end());
	std::cout << "std " << std::endl;
	std::cout << "first" << std::endl;
	for (std::set<int>::iterator it = first.begin(); it != first.end(); ++it) {
		std::cout << "std " << *it << std::endl;
	}
	std::cout << std::endl;
	std::cout << "std " << std::endl;
	std::cout << "second" << std::endl;
	for (std::set<int>::iterator it = second.begin(); it != second.end(); ++it) {
		std::cout << "std " << *it << std::endl;
	}
	std::cout << std::endl;
	std::cout << "std " << std::endl;
	std::cout << "third" << std::endl;
	for (std::set<int>::iterator it = third.begin(); it != third.end(); ++it) {
		std::cout << "std " << *it << std::endl;
	}
	std::cout << std::endl;
	std::cout << "std " << std::endl;
	std::cout << "fourth" << std::endl;
	for (std::set<int>::iterator it = fourth.begin(); it != fourth.end(); ++it) {
		std::cout << "std " << *it << std::endl;
	}
	std::cout << std::endl;

	std_end_time += (clock() - std_tmp_time);
}
void std_set_equal_operator()
{
	unsigned int std_tmp_time =  clock();

	int myints[]={ 12,82,37,64,15 };
	std::set<int> first (myints,myints+5);
	std::set<int> second;

	second = first;
	first = std::set<int>();

	std::cout << "std\n";
	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';

	std_end_time += (clock() - std_tmp_time);
}
void std_set_iterator()
{
	unsigned int std_tmp_time =  clock();

	int myints[]= {10,20,30,40,50};
	std::set<int> first (myints, myints+5);

	std::cout << std::endl;

	for (std::set<int>::iterator it = first.begin(); it != first.end(); ++it) {
		std::cout << "std " << *it << std::endl;
	}
	std::cout << std::endl;
	std::set<int>::iterator tmp = first.end();
	--tmp;
	for (std::set<int>::iterator it = tmp; it != first.begin(); --it) {
		std::cout << "std " << *it << std::endl;
	}
	std::cout << std::endl;
	for (std::set<int>::reverse_iterator it = first.rbegin(); it != first.rend(); ++it) {
		std::cout << "std " << *it << std::endl;
	}
	std::cout << std::endl;

	std::set<int>::reverse_iterator tmp2 = first.rend();
	--tmp2;
	for (std::set<int>::reverse_iterator it = tmp2; it != first.rbegin(); --it) {
		std::cout << "std " << *it << std::endl;
	}
	std_end_time += (clock() - std_tmp_time);
}
void std_set_empty()
{
	unsigned int std_tmp_time =  clock();
	std::set<int> myset;

	myset.insert(20);
	myset.insert(30);
	myset.insert(10);

	std::cout << "std set contains:";
	while (!myset.empty())
	{
		std::cout << ' ' << *myset.begin();
		myset.erase(myset.begin());
	}
	std::cout << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_set_size()
{
	unsigned int std_tmp_time = clock();
	std::set<int> myints;
	std::cout << "std\n";
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; ++i) myints.insert(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.erase(5);
	std::cout << "3. size: " << myints.size() << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_set_max_size()
{
	unsigned int std_tmp_time =  clock();
	int i;
	std::set<int> myset;

	if (myset.max_size()>1000)
	{
		for (i=0; i<1000; i++) myset.insert(i);
		std::cout << "The std set contains 1000 elements.\n";
	}
	else std::cout << "The std set could not hold 1000 elements.\n";
	std_end_time += (clock() - std_tmp_time);
}
void std_set_insert()
{
	unsigned int std_tmp_time =  clock();
	std::set<int> myset;
	std::set<int>::iterator it;
	std::pair<std::set<int>::iterator,bool> ret;

	for (int i=1; i<=5; ++i) myset.insert(i*10);

	ret = myset.insert(20);

	if (ret.second==false) it=ret.first;

	myset.insert (it,25);
	myset.insert (it,24);
	myset.insert (it,26);

	int myints[]= {5,10,15};
	myset.insert (myints, myints+3);

	std::cout << "std set contains:";
	for (it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_set_erase()
{
	unsigned int std_tmp_time =  clock();
	std::set<int> myset;
	std::set<int>::iterator it;
	for (int i=1; i<10; i++) myset.insert(i*10);
	it = myset.begin();
	++it;

	myset.erase (it);

	myset.erase (40);

	it = myset.find (60);
	myset.erase (it, myset.end());

	std::cout << "std set contains:";
	for (it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_set_clear()
{
	unsigned int std_tmp_time =  clock();
	std::set<int> myset;

	myset.insert (100);
	myset.insert (200);
	myset.insert (300);

	std::cout << "std set contains:";
	for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	myset.clear();
	myset.insert (1101);
	myset.insert (2202);

	std::cout << "std set contains:";
	for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_set_swap()
{
	unsigned int std_tmp_time =  clock();
	int myints[]={12,75,10,32,20,25};
	std::set<int> first (myints,myints+3);
	std::set<int> second (myints+3,myints+6);

	first.swap(second);

	std::cout << "first contains:";
	for (std::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "second contains:";
	for (std::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_set_key_comp()
{
	unsigned int std_tmp_time =  clock();
	std::set<int> myset;
	int highest;

	std::set<int>::key_compare mycomp = myset.key_comp();

	for (int i=0; i<=5; i++) myset.insert(i);

	std::cout << "std set contains:";

	highest=*myset.rbegin();
	std::set<int>::iterator it=myset.begin();
	do {
		std::cout << ' ' << *it;
	} while ( mycomp(*(++it),highest) );

	std::cout << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_set_value_comp()
{
	unsigned int std_tmp_time =  clock();
	std::set<int> myset;

	std::set<int>::value_compare mycomp = myset.value_comp();

	for (int i=0; i<=5; i++) myset.insert(i);

	std::cout << "std set contains:";

	int highest=*myset.rbegin();
	std::set<int>::iterator it=myset.begin();
	do {
		std::cout << ' ' << *it;
	} while ( mycomp(*(++it),highest) );

	std::cout << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_set_find()
{
	unsigned int std_tmp_time =  clock();
	std::set<int> myset;
	std::set<int>::iterator it;

	for (int i=1; i<=5; i++) myset.insert(i*10);

	it=myset.find(20);
	myset.erase (it);
	myset.erase (myset.find(40));

	std::cout << "std set contains:";
	for (it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_set_count()
{
	unsigned int std_tmp_time =  clock();
	std::set<int> myset;

	for (int i=1; i<5; ++i) myset.insert(i*3);

	for (int i=0; i<10; ++i)
	{
		std::cout << i;
		if (myset.count(i)!=0)
			std::cout << " is an element of std set.\n";
		else
			std::cout << " is not an element of std set.\n";
	}
	std_end_time += (clock() - std_tmp_time);
}
void std_set_lower_bound()
{
	unsigned int std_tmp_time =  clock();
	std::set<int> myset;
	std::set<int>::iterator itlow,itup;

	for (int i=1; i<10; i++) myset.insert(i*10);

	itlow=myset.lower_bound (30);
	itup=myset.upper_bound (60);

	myset.erase(itlow,itup);

	std::cout << "std set contains:";
	for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_set_upper_bound()
{
	unsigned int std_tmp_time =  clock();
	std::set<int> myset;
	std::set<int>::iterator itlow,itup;

	for (int i=1; i<10; i++) myset.insert(i*10);

	itlow=myset.lower_bound (30);
	itup=myset.upper_bound (60);

	myset.erase(itlow,itup);

	std::cout << "std set contains:";
	for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_set_equal_range()
{
	unsigned int std_tmp_time =  clock();
	std::set<int> myset;

	for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

	std::pair<std::set<int>::const_iterator,std::set<int>::const_iterator> ret;
	ret = myset.equal_range(30);

	std::cout << "std the lower bound points to: " << *ret.first << '\n';
	std::cout << "std the upper bound points to: " << *ret.second << '\n';
	std_end_time += (clock() - std_tmp_time);
}
void std_set_get_allocator()
{
	unsigned int std_tmp_time =  clock();
	std::set<int> myset;
	int * p;
	unsigned int i;

	p=myset.get_allocator().allocate(5);

	for (i=0; i<5; i++) p[i]=(i+1)*10;

	std::cout << "The allocated std array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	myset.get_allocator().deallocate(p,5);
	std_end_time += (clock() - std_tmp_time);
}
unsigned int std_time()
{
	return (std_end_time - std_start_time);
}

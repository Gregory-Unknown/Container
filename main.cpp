#include <iostream>
#include "vector.hpp"
#include <vector>
#include <iterator>
#include <ctime>

void ft_constructor()
{
	// constructors used in the same order as described above:
	std::vector<int> std_first;                                // empty vector of ints
	std::vector<int> std_second (4,100);                       // four ints with value 100
	std::vector<int> std_third (std_second.begin(),std_second.end());  // iterating through second
	std::vector<int> std_fourth (std_third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int std_ints[] = {16,2,77,29};
	std::vector<int> std_fifth (std_ints, std_ints + sizeof(std_ints) / sizeof(int) );

	std::cout << "The contents of std_fifth are:";
	for (std::vector<int>::iterator it = std_fifth.begin(); it != std_fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	// constructors used in the same order as described above:
	ft::vector<int> ft_first;										// empty vector of ints
	ft::vector<int> ft_second (4,100);								// four ints with value 100
	ft::vector<int> ft_third (ft_second.begin(),ft_second.end());	// iterating through second
	ft::vector<int> ft_fourth (ft_third);							// a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int ft_ints[] = {16,2,77,29};
	ft::vector<int> ft_fifth (ft_ints, ft_ints + sizeof(ft_ints) / sizeof(int) );

	std::cout << "The contents of ft_fifth are: ";
	for (ft::vector<int>::iterator it = ft_fifth.begin(); it != ft_fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void ft_operator_equal()
{
	std::vector<int> std_foo (3,0);
	std::vector<int> std_bar (5,0);

	std_bar = std_foo;
	std_foo = std::vector<int>();

	std::cout << "Size of std_foo: " << int(std_foo.size()) << '\n';
	std::cout << "Size of std::bar: " << int(std_bar.size()) << '\n';

	ft::vector<int> ft_foo (3,0);
	ft::vector<int> ft_bar (5,0);

	ft_bar = ft_foo;
	ft_foo = ft::vector<int>();

	std::cout << "Size of ft_foo: " << int(ft_foo.size()) << '\n';
	std::cout << "Size of ft::bar: " << int(ft_bar.size()) << '\n';
}

void ft_begin()
{
	std::vector<int> std_vector;
	for (int i=1; i<=5; i++) std_vector.push_back(i);

	std::cout << "std_vector contains:";
	for (std::vector<int>::iterator it = std_vector.begin() ; it != std_vector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::vector<int> ft_vector;
	for (int i=1; i<=5; i++) ft_vector.push_back(i);

	std::cout << "ft_vector contains:";
	for (ft::vector<int>::iterator it = ft_vector.begin() ; it != ft_vector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

int main() {

	ft_constructor();
	ft_operator_equal();
	ft_begin();

	// ft::vector<int> myvector (3,100);
	// ft::vector<int>::iterator iter;
	// std::cout << "myvector contains 1 :";
	// for (iter = myvector.begin(); iter < myvector.end(); iter++)
	// 	std::cout << ' ' << *iter;
	// std::cout << '\n';

	// iter = myvector.begin();
	// iter = myvector.insert ( iter , 200 );

	// std::cout << "myvector contains 2 :";
	// for (iter = myvector.begin(); iter < myvector.end(); iter++)
	// 	std::cout << ' ' << *iter;
	// std::cout << '\n';

	// myvector.insert (iter,2,300);

	// std::cout << "myvector contains 3 :";
	// for (iter = myvector.begin(); iter < myvector.end(); iter++)
	// 	std::cout << ' ' << *iter;
	// std::cout << '\n';

	// iter = myvector.begin();

	// ft::vector<int> anothervector1 (2,400);
	// myvector.insert (iter + 2,anothervector1.begin(), anothervector1.end());

	// std::cout << "myvector contains 4 :";
	// for (iter = myvector.begin(); iter < myvector.end(); iter++)
	// 	std::cout << ' ' << *iter;
	// std::cout << '\n';

	// int myarray1 [] = { 501,502,503 };
	// myvector.insert(myvector.begin(), myarray1, myarray1 + 3);

	// std::cout << "myvector contains 5 :";
	// for (iter = myvector.begin(); iter < myvector.end(); iter++)
	// 	std::cout << ' ' << *iter;
	// std::cout << '\n';

	// std::vector<int> vector (3,100);
	// std::vector<int>::iterator it;

	// std::cout << "vector contains 1 :  ";
	// for (it = vector.begin(); it<vector.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// it = vector.begin();
	// it = vector.insert ( it , 200 );

	// std::cout << "vector contains 2 :  ";
	// for (it = vector.begin(); it<vector.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// vector.insert (it,2,300);

	// std::cout << "vector contains 3 :  ";
	// for (it = vector.begin(); it<vector.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// it = vector.begin();

	// std::vector<int> anothervector (2,400);
	// vector.insert (it+2,anothervector.begin(),anothervector.end());

	// std::cout << "vector contains 4 :  ";
	// for (it = vector.begin(); it<vector.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// int myarray [] = { 501,502,503 };
	// vector.insert (vector.begin(), myarray, myarray+3);

	// std::cout << "vector contains 5 :  ";
	// for (it = vector.begin(); it<vector.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// ft::vector<int> vector (3,100);
	// ft::vector<int>::iterator iter;

	// iter = myvector.begin();
	// ft::distance(myvector.begin(), myvector.end());
	// iter = myvector.insert ( iter , 200 );

	// myvector.insert (iter,2,300);

	// iter = myvector.begin();

	// ft::vector<int> anothervector1 (2,400);
	// myvector.insert (iter + 2,anothervector1.begin(), anothervector1.end());

	// int myarray1 [] = { 501,502,503 };
	// myvector.insert(vector.begin(), myarray1, myarray1 + 3);

	// std::cout << "myvector contains:";
	// for (iter = vector.begin(); iter < myvector.end(); iter++)
	// 	std::cout << ' ' << *iter;
	// std::cout << '\n';

	// unsigned int std_start_time =  clock();
	// std::vector<int> vector;
	// std::cout << "STD_SIZE " << vector.size() << std::endl;
	// std::cout << "STD_CAPACITY " << vector.size() << std::endl;
	// vector.resize(2000000000);
	// std::cout << "STD_SIZE " << vector.size() << std::endl;
	// std::cout << "STD_CAPACITY " << vector.capacity() << std::endl;
	// vector.resize(20);
	// vector.insert(1, 20);
	// std::cout << "STD_SIZE " << vector.size() << std::endl;
	// std::cout << "STD_CAPACITY " << vector.capacity() << std::endl;
	// vector.~vector();
	// unsigned int std_end_time = clock();
	// unsigned int std_search_time = std_end_time - std_start_time;

	// unsigned int ft_start_time =  clock();
	//ft::vector<int> v1;
	// ft::vector<int> v2;
	// std::cout << "FT_SIZE " << v2.size() << std::endl;
	// std::cout << "FT_CAPACITY " << v2.size() << std::endl;
	// v2.resize(2000000000);
	// std::cout << "FT_SIZE " << v2.size() << std::endl;
	// std::cout << "FT_CAPACITY " << v2.size() << std::endl;
	// v2.resize(20);
	// std::cout << "FT_SIZE " << v2.size() << std::endl;
	// std::cout << "FT_CAPACITY " << v2.capacity() << std::endl;
	// v2.~vector();
	// unsigned int ft_end_time = clock();
	// unsigned int ft_search_time = ft_end_time - ft_start_time;

	// std::cout << "STD_TIME " << std_search_time << std::endl;
	// std::cout << "FT_TIME  " << ft_search_time << std::endl;
	// std::cout << "RESULT " << ft_search_time / std_search_time << std::endl;
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

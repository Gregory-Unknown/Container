#ifndef PAIR_HPP
#define PAIR_HPP

#include <ostream>

namespace ft {

	template<typename T1, typename T2>
	struct pair {
		typedef T1 first_type;
		typedef T2 second_type;

		first_type  first;
		second_type second;

		pair(): first(T1()), second(T2())
		{

		}
		template<typename U, typename V>
		pair(const pair<U, V> &pr): first(first_type(pr.first)), second(second_type(pr.second))
		{

		}
		pair(const first_type &a, const second_type &b): first(a), second(b)
		{

		}
		pair &operator=(const pair &pr)
		{
			if (this != &pr) {
				first = pr.first;
				second = pr.second;
			}
			return (*this);
		}
	};

	template<typename T1, typename T2>
	bool operator==(const pair<T1, T2> &l, const pair<T1, T2> &r)
	{
		return (l.first == r.first && l.second == r.second);
	}

	template<typename T1, typename T2>
	bool operator!=(const pair<T1, T2> &l, const pair<T1, T2> &r)
	{
		return (!(l == r));
	}

	template<typename T1, typename T2>
	bool operator<(const pair<T1, T2> &l, const pair<T1, T2> &r)
	{
		return (l.first < r.first || (!(r.first < l.first) && l.second < r.second));
	}

	template<typename T1, typename T2>
	bool operator<=(const pair<T1, T2> &l, const pair<T1, T2> &r)
	{
		return (!(r < l));
	}

	template<typename T1, typename T2>
	bool operator>(const pair<T1, T2> &l, const pair<T1, T2> &r)
	{
		return (r < l);
	}

	template<typename T1, typename T2>
	bool operator>=(const pair<T1, T2> &l, const pair<T1, T2> &r)
	{
		return (!(l < r));
	}

	template<typename T1, typename T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}

	template<typename T1, typename T2>
	std::ostream &operator<<(std::ostream &o, const pair<T1, T2> &p)
	{
		o << "(" << p.first << ", " << p.second << ")";
		return (o);
	}

}

#endif

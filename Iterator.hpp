#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
#include "traits.hpp"

namespace ft {

	class input_iterator_tag {};
	class forward_iterator_tag : public input_iterator_tag {};
	class bidirectional_iterator_tag : public  forward_iterator_tag {};
	class random_access_iterator_tag : public  bidirectional_iterator_tag {};

	template<bool Cond, typename T>
	struct is_iterator_tag {
		typedef T type;
		static const bool value = Cond;
	};

	template<typename T>
	struct is_input_iterator_tag: public is_iterator_tag<false, T> {};
	template<>
	struct is_input_iterator_tag<random_access_iterator_tag>: public is_iterator_tag<true, random_access_iterator_tag> {};
	template<>
	struct is_input_iterator_tag<bidirectional_iterator_tag>: public is_iterator_tag<true, bidirectional_iterator_tag> {};
	template<>
	struct is_input_iterator_tag<forward_iterator_tag>: public is_iterator_tag<true, forward_iterator_tag> {};
	template<>
	struct is_input_iterator_tag<input_iterator_tag>: public is_iterator_tag<true, input_iterator_tag> {};

	template <class Iterator>
	class iterator_traits {
	public:
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::value_type			difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits <T*> {
	public:
		typedef T									value_type;
		typedef ptrdiff_t							difference_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef random_access_iterator_tag			iterator_category;
	};

	template <class T>
	class iterator_traits <const T*> {
	public:
		typedef T									value_type;
		typedef ptrdiff_t							difference_type;
		typedef const T*							pointer;
		typedef const T&							reference;
		typedef random_access_iterator_tag			iterator_category;
	};

	template<class Iterator>
	class reverse_iterator {
	public:
		typedef Iterator												iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;

	private:
		iterator_type m_it;
	public:
		reverse_iterator(): m_it(Iterator())
		{

		}
		explicit reverse_iterator(iterator_type it) : m_it(it)
		{

		}
		template<class Iter>
		reverse_iterator(const reverse_iterator<Iter> &src) : m_it(src.geter())
		{

		}
		~reverse_iterator()
		{

		}
		iterator_type geter() const
		{
			return (m_it);
		}
		reference operator*() const
		{
			return (*(--geter()));
		}
		reverse_iterator operator+(difference_type n) const
		{
			return (m_it - n);
		}
		reverse_iterator &operator++()
		{
			--m_it;
			return (*this);
		}
		const reverse_iterator operator++(int)
		{
			reverse_iterator<Iterator> tmp = *this;
			--m_it;
			return (this);
		}
		reverse_iterator &operator+=(difference_type n)
		{
			m_it -= n;
			return(*this);
		}
		reverse_iterator operator-(difference_type n) const
		{
			return(m_it + n);
		}
		reverse_iterator &operator--()
		{
			m_it++;
			return (*this);
		}
		const reverse_iterator operator--(int)
		{
			reverse_iterator<Iterator> tmp = *this;
			++m_it;
			return (this);
		}
		reverse_iterator &operator-=(difference_type n)
		{
			m_it += n;
			return(*this);
		}
		pointer operator->() const
		{
			return (&(operator*()));
		}
		reference operator[](difference_type n) const
		{
			return (geter()[n - 1]);
		}
	};

	template<class Iterator>
	bool operator==(const reverse_iterator<Iterator> &l, const reverse_iterator<Iterator> &r) {
		return (l.geter() == r.geter());
	}

	template<class Iterator>
	bool operator!=(const reverse_iterator<Iterator> &l, const reverse_iterator<Iterator> &r) {
		return (l.geter() != r.geter());
	}

	template<class Iterator>
	bool operator<(const reverse_iterator<Iterator> &l, const reverse_iterator<Iterator> &r) {
		return (l.geter() > r.geter());
	}

	template<class Iterator>
	bool operator>(const reverse_iterator<Iterator> &l, const reverse_iterator<Iterator> &r) {
		return (l.geter() < r.geter());
	}

	template<class Iterator>
	bool operator<=(const reverse_iterator<Iterator> &l, const reverse_iterator<Iterator> &r) {
		return (l.geter() >= r.geter());
	}

	template<class Iterator>
	bool operator>=(const reverse_iterator<Iterator> &l, const reverse_iterator<Iterator> &r) {
		return (l.geter() <= r.geter());
	}

	template<class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> x) {
		return (x + n);
	}

	template<class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &l, const reverse_iterator<Iterator> &r) {
		return (r.geter() - l.geter());
	}

}

#endif

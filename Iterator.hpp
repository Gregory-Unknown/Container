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
	template<typename T>
	struct is_random_access_iterator_tag: public is_iterator_tag<false, T> {};
	template<>
	struct is_random_access_iterator_tag<random_access_iterator_tag>: public is_iterator_tag<true, random_access_iterator_tag> {};

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

	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last, typename ft::enable_if<ft::is_random_access_iterator_tag<typename InputIterator::iterator_category>::value>::type* = NULL) {
		return (last - first);
	}

	template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_random_access_iterator_tag<typename InputIterator::iterator_category>::value>::type* = NULL) {
		typename iterator_traits<InputIterator>::difference_type diff = 0;
		while (first != last) {
			first++;
			diff++;
		}
		return (diff);
	}

	template<typename Iterator>
	class reverse_iterator {
	public:
		typedef Iterator												iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;

	private:
		Iterator _it;

	public:
		reverse_iterator();
		explicit reverse_iterator(iterator_type it);
		template<typename Iter>
		reverse_iterator(const reverse_iterator<Iter> &src);

		~reverse_iterator();

		iterator_type base() const;
		reference operator*() const;

		reverse_iterator operator+(difference_type n) const;
		reverse_iterator &operator++();
		const reverse_iterator operator++(int);
		reverse_iterator &operator+=(difference_type n);

		reverse_iterator operator-(difference_type n) const;
		reverse_iterator &operator--();
		const reverse_iterator operator--(int);
		reverse_iterator &operator-=(difference_type n);

		pointer operator->() const;
		reference operator[](difference_type n) const;
	};

	template<typename Iterator>
	reverse_iterator<Iterator>::reverse_iterator(): _it(Iterator()) {}

	template<typename Iterator>
	reverse_iterator<Iterator>::reverse_iterator(iterator_type it): _it(it) {}

	template<typename Iterator>
	template<typename Iter>
	reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iter> &src): _it(src.base()) {}

	template<typename Iterator>
	reverse_iterator<Iterator>::~reverse_iterator() {}

	template<typename Iterator>
	typename reverse_iterator<Iterator>::iterator_type reverse_iterator<Iterator>::base() const {
		return (_it);
	}

	template<typename Iterator>
	typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator*() const {
		return (*(--base()));
	}

	template<typename Iterator>
	reverse_iterator<Iterator> reverse_iterator<Iterator>::operator+(difference_type n) const {
		return (_it - n);
	}

	template<typename Iterator>
	reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator++() {
		_it--;
		return (*this);
	}

	template<typename Iterator>
	const reverse_iterator<Iterator> reverse_iterator<Iterator>::operator++(int) {
		reverse_iterator<Iterator> tmp = *this;
		++(*this);
		return (tmp);
	}

	template<typename Iterator>
	reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator+=(difference_type n) {
		_it -= n;
		return (*this);
	}

	template<typename Iterator>
	reverse_iterator<Iterator> reverse_iterator<Iterator>::operator-(difference_type n) const {
		return (_it + n);
	}

	template<typename Iterator>
	reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator--() {
		_it++;
		return (*this);
	}

	template<typename Iterator>
	const reverse_iterator<Iterator> reverse_iterator<Iterator>::operator--(int) {
		reverse_iterator<Iterator> tmp = *this;
		--(*this);
		return (tmp);
	}

	template<typename Iterator>
	reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator-=(difference_type n) {
		_it += n;
		return (*this);
	}

	template<typename Iterator>
	typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::operator->() const {
		return (&(operator*()));
	}

	template<typename Iterator>
	typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator[](difference_type n) const {
		return (base()[-n - 1]);
	}

	template<typename Iterator>
	bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() == rhs.base());
	}

	template<typename Iterator>
	bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename Iterator>
	bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() > rhs.base());
	}

	template<typename Iterator>
	bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template<typename Iterator>
	bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() >= rhs.base());
	}

	template<typename Iterator>
	bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
		return (lhs.base() <= rhs.base());
	}

	template<typename Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> x) {
		return (x + n);
	}

	template<typename Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
		return (rhs.base() - lhs.base());
	}

}

#endif

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "Iterator.hpp"
#include "vector.hpp"


namespace ft {

	template<typename T, typename Pointer, typename Reference>
	class vector_iterator {
	public :
		typedef T									value_type;
		typedef ptrdiff_t							difference_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef random_access_iterator_tag			iterator_category;
	private:
		pointer m_p;
	public:
		vector_iterator() : m_p(0)
		{

		}
		explicit vector_iterator(Pointer p) : m_p(p)
		{

		}
		template <class Point, class Ref>
		explicit vector_iterator(const vector_iterator<T, Point, Ref> &src) : m_p(src.geter())
		{

		}
		~vector_iterator()
		{

		}
		pointer	geter() const
		{
			return (m_p);
		}
		template<typename Point, typename Ref>
		vector_iterator &operator=(const vector_iterator<T, Point, Ref> &src)
		{
			if (this != &src) {
				m_p = src.geter();
			}
			return (*this);
		}
		reference operator*() const
		{
			return (*m_p);
		}
		pointer operator->() const
		{
			return (m_p);
		}
		vector_iterator &operator++()
		{
			++m_p;
			return (*this);
		}
		const vector_iterator operator++(int)
		{
			vector_iterator tmp(*this);
			++m_p;
			return (tmp);
		}
		vector_iterator &operator--()
		{
			--m_p;
			return (*this);
		}
		const vector_iterator operator--(int)
		{
			vector_iterator tmp(*this);
			--m_p;
			return (tmp);
		}

		vector_iterator operator+(difference_type n) const
		{
			return (vector_iterator(m_p + n));
		}
		vector_iterator operator-(difference_type n) const
		{
			return (vector_iterator(m_p - n));
		}
		vector_iterator operator+=(difference_type n)
		{
			m_p += n;
			return (*this);
		}
		vector_iterator operator-=(difference_type n)
		{
			m_p -= n;
			return (*this);
		}
		reference operator[](difference_type n) const
		{
			return (m_p[n]);
		}
	};

	template<class T, class Pointer, class Reference>
	vector_iterator<T, Pointer, Reference> operator+(typename vector_iterator<T, Pointer, Reference>::difference_type n, const vector_iterator<T, Pointer, Reference> x)
	{
		return (x + n);
	}
	template<class T, class Pointer, class Reference>
	typename vector_iterator<T, Pointer, Reference>::difference_type
	operator-(const vector_iterator<T, Pointer, Reference> &l, const vector_iterator<T, Pointer, Reference> &r)
	{
		return (l.geter() - r.geter());
	}
	template<class T, class LPoint, class LRef, class RPoint, class RRef>
	bool operator==(const vector_iterator<T, LPoint, LRef> &l, const vector_iterator<T, RPoint, RRef> &r)
	{
		return (l.geter() == r.geter());
	}
	template<class T, class LPoint, class LRef, class RPoint, class RRef>
	bool operator!=(const vector_iterator<T, LPoint, LRef> &l, const vector_iterator<T, RPoint, RRef> &r)
	{
		return (l.geter() != r.geter());
	}
	template<class T, class LPoint, class LRef, class RPoint, class RRef>
	bool operator<(const vector_iterator<T, LPoint, LRef> &l, const vector_iterator<T, RPoint, RRef> &r)
	{
		return (r > l);
	}
	template<class T, class LPoint, class LRef, class RPoint, class RRef>
	bool operator>(const vector_iterator<T, LPoint, LRef> &l, const vector_iterator<T, RPoint, RRef> &r)
	{
		return (l.geter() > r.geter());
	}
	template<class T, class LPoint, class LRef, class RPoint, class RRef>
	bool operator<=(const vector_iterator<T, LPoint, LRef> &l, const vector_iterator<T, RPoint, RRef> &r)
	{
		return (!(l > r));
	}
	template<class T, class LPoint, class LRef, class RPoint, class RRef>
	bool operator>=(const vector_iterator<T, LPoint, LRef> &l, const vector_iterator<T, RPoint, RRef> &r)
	{
		return (!(r > l));
	}
}
#endif

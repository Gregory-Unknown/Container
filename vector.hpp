#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "my_iterator.hpp"
# include <iostream>
# include <cstddef>   // size_t, ptrdiff_t ...
# include <cstring>   // memcpy();
# include <memory>    // allocator
# include <cstddef>   // ptrdiff_t
# include <limits>    // std::numeric_limits
# include <exception>
# include <memory>
# include <stdexcept>

namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T																	value_type;
			typedef Alloc																allocator_type;
			typedef typename allocator_type::reference									reference;
			typedef typename allocator_type::const_reference							const_reference;
			typedef typename allocator_type::pointer									pointer;
			typedef typename allocator_type::const_pointer								const_pointer;
			typedef vector_iterator <value_type, value_type*, value_type&>				iterator;
			typedef vector_iterator <value_type, const value_type*, const value_type&>	const_iterator;
			// typedef ft::vector_reverse_iterator<iterator>							reverse_iterator;
			// typedef ft::vector_reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type					difference_type;
			typedef size_t																size_type;
		private:
			pointer			m_data;
			pointer			m_begin;
			size_type		m_capacity;
			size_type		m_size;
			allocator_type	m_alloc;
		public:
			explicit vector (const allocator_type& alloc = allocator_type())
			: m_data(0), m_begin(0), m_capacity(0), m_size(0), m_alloc(alloc)
			{
				std::cout << m_data << std::endl;
				std::cout << m_capacity << std::endl;
				std::cout << m_size << std::endl;
			}
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: m_data(0), m_begin(0), m_capacity(n), m_size(n), m_alloc(alloc)
			{
				try {
					m_data = m_alloc.allocate(n);
				} catch (std::bad_alloc &e) {
					this->~vector();
					throw ;
				}
				m_begin = m_data;
				for (int i = 0; i < n; ++i) {
					m_alloc.construct(m_data + i, val);
				}
				std::cout << m_data << std::endl;
				std::cout << m_capacity << std::endl;
				std::cout << m_size << std::endl;
			}
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename std::enable_if < !std::numeric_limits<InputIterator>::is_specialized >::type* = 0)
			: m_data(0), m_begin(0), m_capacity(0), m_size(0), m_alloc(alloc)
			{
				m_size = m_capacity = std::distance(first, last);
				try {
					m_data = m_alloc.allocate(m_size);
				} catch (std::bad_alloc &e) {
					~vector();
					throw ;
				}
				m_begin = m_data;
				for (int i = 0; i < m_size; ++i) {
					m_alloc.construct(m_data + i, *first);
					++first;
				}
			}
			vector (const vector& x)
			: m_data(0), m_begin(0), m_capacity(x.m_capacity), m_size(x.m_size), m_alloc(x.m_alloc)
			{
				try {
					m_data = m_alloc.allocate(m_size);
				} catch (std::bad_alloc &e) {
					~vector();
					throw ;
				}
				m_begin = m_data;
				for (int i = 0; i < m_size; ++i) {
					m_alloc.construct(m_data + i, x[i]);
				}
			}
			~vector()
			{
				if (m_begin) {
					for (int i = 0; i < m_size; ++i) {
						m_alloc.destroy(m_data + i);
					}
					m_alloc.deallocate(m_begin, m_capacity);
					m_data = 0;
					m_begin = 0;
					m_size = 0;
					m_capacity = 0;
				}
			}
	};
}
#endif

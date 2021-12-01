#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vector_iterator.hpp"
#include <memory>
#include <stdexcept>
#include <exception>

namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T															value_type;
			typedef Alloc														allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef vector_iterator <T, T*, T&>									iterator;
			typedef vector_iterator <T, const T*, const T&>						const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type			difference_type;
			typedef size_t														size_type;
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
				for (size_t i = 0; i < n; ++i) {
					m_alloc.construct(m_data + i, val);
				}
			}
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if < !std::numeric_limits<InputIterator>::is_specialized >::type* = 0)
			: m_data(0), m_begin(0), m_capacity(0), m_size(0), m_alloc(alloc)
			{
				m_size = m_capacity = std::distance(first, last);
				try {
					m_data = m_alloc.allocate(m_size);
				} catch (std::bad_alloc &e) {
					this->~vector();
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
					this->~vector();
					throw ;
				}
				m_begin = m_data;
				for (size_t i = 0; i < m_size; ++i) {
					m_alloc.construct(m_data + i, x[i]);
				}
			}
			virtual ~vector()
			{
				if (m_begin) {
					for (size_t i = 0; i < m_size; ++i) {
						m_alloc.destroy(m_data + i);
					}
					m_alloc.deallocate(m_begin, m_capacity);
					m_data = 0;
					m_begin = 0;
					m_size = 0;
					m_capacity = 0;
				}
			}
			vector &operator=(const vector &vec)
			{
				if (this != &vec) {
					this->vector();
					m_alloc= vec.m_alloc;
					m_data = m_alloc.allocate(vec.m_capacity);
					for (size_type i = 0; i < vec.m_size; ++i) {
						m_alloc.construct(m_data + i, vec[i]);
					}
					m_begin = m_data;
					m_size = vec.m_size;
					m_capacity = vec.m_capacity;
					return (*this);
				}
			}
			iterator begin()
			{
				return (iterartor(m_data));
			}
			const_iterator begin() const;
			{
				return (const_iterartor(m_data));
			}
			iterator end()
			{
				return (iterartor(m_data + m_size));
			}
			const_iterator end() const
			{
				return (const_iterartor(m_data + m_size));
			}
			reverse_iterator rbegin()
			{
				return (reverse_iterartor(end()));
			}
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterartor(end()));
			}
			iterator rend()
			{
				return (reverse_iterartor(begin()));
			}
			const_iterator rend() const
			{
				return (const_reverse_iterartor(begin()));
			}
			size_type size() const
			{
				return (m_size);
			}
			size_type max_size() const
			{
				return (m_alloc.max_size());
			}
			void resize (size_type n, value_type val = value_type());
			size_type capacity() const
			{
				return (m_capacity);
			}
			bool empty() const
			{
				return (m_size == 0);
			}
			void reserve (size_type n);
			reference operator[] (size_type n)
			{
				return (m_data[n]);
			}
			const_reference operator[] (size_type n) const
			{
				return (m_data[n]);
			}
			reference at (size_type n)
			{
				if (n > m_size)
					throw std::out_of_range("Out of Range error: vector");
				return (m_data[n]);
			}
			const_reference at (size_type n) const
			{
				if (n > m_size)
					throw std::out_of_range("Out of Range error: vector");
				return (m_data[n]);
			}
			reference front()
			{
				return (m_data[0]);
			}
			const_reference front() const
			{
				return (m_data[0]);
			}
			reference back()
			{
				return (m_data[m_size - 1]);
			}
			const_reference back() const
			{
				return (m_data[m_size - 1]);
			}
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last);
			void assign (size_type n, const value_type& val);
			void push_back (const value_type& val);
			void pop_back();
			iterator insert (iterator position, const value_type& val);
			void insert (iterator position, size_type n, const value_type& val);
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last);
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			void swap (vector& x);
			void clear();
			allocator_type get_allocator() const;
	};
}
#endif

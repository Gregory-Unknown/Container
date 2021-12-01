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
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if < !ft::numeric_limits<InputIterator>::is_specialized >::type* = 0)
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
			~vector()
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

			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			size_type size() const;
			size_type max_size() const;
			void resize (size_type n, value_type val = value_type());
			size_type capacity() const;
			bool empty() const;
			void reserve (size_type n);
			reference operator[] (size_type n);
			const_reference operator[] (size_type n) const;
			reference at (size_type n);
			const_reference at (size_type n) const;
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;
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

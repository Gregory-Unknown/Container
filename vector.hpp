#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vector_iterator.hpp"
#include <memory>
#include <stdexcept>
#include <exception>
// #include <cstdint>
#include <cstddef>
#include <cstring>
#include <limits>

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
			: m_data(0), m_begin(0), m_capacity(10), m_size(0), m_alloc(alloc)
			{
				reserve(10);
			}
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: m_data(0), m_begin(0), m_capacity(2 * n), m_size(n), m_alloc(alloc)
			{
				m_data = m_alloc.allocate(m_capacity);
				for (size_type i = 0; i < n; ++i) {
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
				for (size_type i = 0; i < m_size; ++i) {
					m_alloc.construct(m_data + i, x[i]);
				}
			}
			virtual ~vector()
			{
				if (m_data) {
					for (size_type i = 0; i < m_size; ++i) {
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
					this->~vector();
					m_alloc = vec.m_alloc;
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
				return (iterator(m_data));
			}
			const_iterator begin() const
			{
				return (const_iterator(m_data));
			}
			iterator end()
			{
				return (iterator(m_data + m_size));
			}
			const_iterator end() const
			{
				return (const_iterator(m_data + m_size));
			}
			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}
			iterator rend()
			{
				return (reverse_iterator(begin()));
			}
			const_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}
			size_type size() const
			{
				return (m_size);
			}
			size_type max_size() const
			{
				return (m_alloc.max_size());
			}
			void resize (size_type n, value_type val = value_type())
			{
				if (n > m_capacity) {
					if (m_capacity * 2 > n)
						reserve(m_capacity * 2);
					else
						reserve(n);
				}
				for (size_type i = m_size; i < n; ++i) {
					m_alloc.construct(m_data + i, val);
				}
				for (size_type i = n; i < m_size; ++i) {
					m_alloc.destroy(m_data + i);
				}
				m_size = n;
			}
			size_type capacity() const
			{
				return (m_capacity);
			}
			bool empty() const
			{
				return (m_size == 0);
			}
			void reserve (size_type n)
			{
				if (n <= m_capacity) return ;
				pointer newdata = m_alloc.allocate(n);
				// for (size_type i = 0; i < m_size; ++i) {
				// 	m_alloc.construct(newdata + i, m_data[i]);
				// }
				try {
					std::uninitialized_copy(m_data, m_data + m_size, newdata);
				} catch (...) {
					m_alloc.deallocate(newdata, n);
					throw;
				}
				for (size_type i = 0; i < m_size; ++i) {
					m_alloc.destroy(m_data + i);
				}
				m_alloc.deallocate(m_data, m_capacity);
				m_data = newdata;
				m_capacity = n;
			}
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
			void assign (InputIterator first, InputIterator last)
			{
				difference_type new_size = std::distance(first, last);
				if (new_size < 0 ) {
					this->~Vector();
					throw ;
				}
				vector save(first, last);
				clear();
				reserve(new_size);
				insert(this->begin(), save.begin(), save.end());
			}
			void assign (size_type n, const value_type& val)
			{
				value_type save(val);
				clear();
				reserve(n);
				insert(begin(), n, save);
			}
			void push_back (const value_type& val)
			{
				insert(end(), val);
			}
			void pop_back()
			{
				m_alloc.destroy(m_data + m_size - 1);
				--m_size;
			}
			iterator insert (iterator position, const value_type& val)
			{
				size_type tmp = position - begin();
				insert(position, 1, val);
				return (iterator(m_data + tmp));

			}
			void insert (iterator position, size_type n, const value_type& val)
			{
				size_type tmp = position - begin();

				// m_capacity >= m_size + n example: [1,2,3,.,.,.] <-- 5 between 1, 2
				if (m_capacity >= m_size + n) {
					size_type last = (m_size == 0) ? 0 : m_size - 1;

					// moving [1,2,3,.,.,.] ----> [1,.,2,3,.,.]
					for (size_type i = tmp; i < m_size; ++i, --last) {
						memmove(m_data + last + n, m_data + last, sizeof(value_type));
					}
					// adding 5: [1,.,2,3,.,.] ----> [1,5,2,3,.,.];
					for (size_type i = 0; i < n; ++i) {
						m_alloc.construct(m_data + tmp + i, val);
					}
					m_size += n;
					iterator(m_data + tmp);
					return ;
				}
				// m_capacity < m_size + n: allocate new memory
				size_type new_capacity = m_capacity * 2;

				if (new_capacity < m_size + n) {
					new_capacity = m_size + n;
				}

				value_type      save_val(val);
				difference_type save_pos(position - begin());

				reserve(new_capacity);
				insert(iterator(m_data + save_pos), n, save_val);
				iterator(m_data + tmp);
			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last)
			{
				difference_type n = std::distance(first, last);
				difference_type tmp = position - begin();

				if (n <= 0) {
					return ;
				}
				// m_capacity >= m_size + n: just adding elements.
				if (m_capacity >= m_size + n) {
					while (first != last) {
						insert(position, *first);
						++first;
						++position;
					}
					return ;
				}

				// m_capacity < m_size + n: allocate new memory
				pointer newdata;
				size_type  new_capacity = m_capacity * 2;

				if (m_size + n > new_capacity) {
					new_capacity = m_size + n;
				}

				newdata = m_alloc.allocate(new_capacity);

				memmove(newdata, m_data, sizeof(value_type) * tmp);
				std::copy(first, last, newdata + tmp);
				memmove(newdata + tmp + n, m_data + tmp, sizeof(value_type) * (m_size - tmp));
				if (m_begin != 0) {
					m_alloc.deallocate(m_begin, m_capacity);
				}
				m_size += n;
				m_data = newdata;
				m_begin = newdata;
				m_capacity = new_capacity;
			}
			iterator erase (iterator position)
			{
				difference_type index = position - this->begin();

				if (m_size == 0) {
					return iterator(m_data + index);
				}

				m_alloc.destroy(m_data + index);
				--m_size;
				memmove
				(
				m_data + index,
				m_data + index + 1,
				sizeof(value_type) * (m_size - index)
				);
				return iterator(m_data + index);
			}
			iterator erase (iterator first, iterator last)
			{
				size_type start = first - this->begin();

				while (first != last) {
					this->erase(first);
					--last;
				}
				return iterator(m_data + start);
			}
			void swap (vector& x)
			{
				allocator_type alloc_tmp = m_alloc;
				size_type cap_tmp = m_capacity;
				size_type size_tmp = m_size;
				pointer data_tmp = m_data;

				m_alloc = x.m_alloc;
				m_capacity = x.m_capacity;
				m_size = x.m_size;
				m_data = x.m_data;

				x.m_alloc = alloc_tmp;
				x.m_capacity = cap_tmp;
				x.m_size = size_tmp;
				x.m_data = data_tmp;
			}
			void clear()
			{
				if (m_begin != 0) {
					for (size_type i = 0; i < m_size; ++i) {
						m_alloc.destroy(m_data + i);
					}
				}
				m_size = 0;
			}
			allocator_type get_allocator() const
			{
				return (m_alloc);
			}
			private:
			void shrink_to_fit()
			{
				size_type new_cap = m_size * 2;
				pointer newdata = m_alloc.allocate(new_cap);
				try {
					std::uninitialized_copy(m_data, m_data + m_size, newdata);
				} catch (...) {
					m_alloc.deallocate(newdata, new_cap);
					throw;
				}
				for (size_type i = 0; i < m_size; ++i) {
					m_alloc.destroy(m_data + i);
				}
				m_alloc.deallocate(m_data, m_capacity);
				m_data = newdata;
				m_capacity = new_cap;
			}
	};
}
#endif

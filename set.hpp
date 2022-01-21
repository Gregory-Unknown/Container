#ifndef SET_HPP
#define SET_HPP

#include <memory>
#include "rbtree.hpp"
#include "Iterator.hpp"

namespace ft {
	template< class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set {
	public:
		typedef T													key_type;
		typedef T													value_type;
		typedef Compare												key_compare;
		typedef Compare												value_compare;
		typedef Alloc												allocator_type;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef typename RBTree<T>::iterator						iterator;
		typedef typename RBTree<T>::const_iterator					const_iterator;
		typedef ft::reverse_iterator<iterator>						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type	difference_type;
		typedef size_t												size_type;

		RBTree<value_type, value_compare, allocator_type> m_tree;

	public:
		explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		: m_tree(RBTree<value_type, value_compare, allocator_type>(comp, alloc))
		{

		}
		template<typename InputIterator>
		set(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		: m_tree(RBTree<value_type, value_compare, allocator_type>(comp, alloc))
		{
			m_tree.insert(first, last);
		}
		set(const set &src): m_tree(src.m_tree)
		{

		}
		~set()
		{

		}
		set &operator=(const set &other)
		{
			if (this != &other)
				m_tree = other.m_tree;
			return (*this);
		}
		iterator begin()
		{
			return (m_tree.begin());
		}
		const_iterator begin() const
		{
			return (m_tree.begin());
		}
		iterator end()
		{
			return (m_tree.end());
		}
		const_iterator end() const
		{
			return (m_tree.end());
		}
		reverse_iterator rbegin()
		{
			return (m_tree.rbegin());
		}
		const_reverse_iterator rbegin() const
		{
			return (m_tree.rbegin());
		}
		reverse_iterator rend()
		{
			return (m_tree.rend());
		}
		const_reverse_iterator rend() const
		{
			return (m_tree.rend());
		}
		bool empty() const
		{
			return (m_tree.empty());
		}
		size_type size() const
		{
			return (m_tree.size());
		}
		size_type max_size() const
		{
			return (m_tree.max_size());
		}
		pair<iterator, bool> insert(const value_type &val)
		{
			return (m_tree.insert(val));
		}
		iterator insert(iterator position, const value_type &val)
		{
			return (m_tree.insert(position, val));
		}
		template<typename InputIterator>
		void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value && ft::is_input_iterator_tag<typename InputIterator::iterator_category>::value>::type * = NULL)
		{
			m_tree.insert(first, last);
		}
		void erase(iterator position)
		{
			m_tree.erase(position);
		}
		size_type erase(const key_type &k)
		{
			return (m_tree.erase(k));
		}
		void erase(iterator first, iterator last)
		{
			m_tree.erase(first, last);
		}
		void swap(set &x)
		{
			m_tree.swap(x.m_tree);
		}
		void clear()
		{
			m_tree.clear();
		}
		key_compare key_comp() const
		{
			return (m_tree.value_comp()._comp);
		}
		value_compare value_comp() const
		{
			return (m_tree.value_comp());
		}
		iterator find(const key_type &k)
		{
			return (m_tree.find(k));
		}
		const_iterator find(const key_type &k) const
		{
			return (m_tree.find(k));
		}
		size_type count(const key_type &k) const
		{
			return (m_tree.count(k));
		}
		iterator lower_bound(const key_type &k)
		{
			return (m_tree.lower_bound(k));
		}
		const_iterator lower_bound(const key_type &k) const
		{
			return (m_tree.lower_bound(k));
		}
		iterator upper_bound(const key_type &k)
		{
			return (m_tree.upper_bound(k));
		}
		const_iterator upper_bound(const key_type &k) const
		{
			return (m_tree.upper_bound(k));
		}
		pair<iterator, iterator> equal_range(const key_type &k)
		{
			return (m_tree.equal_range(k));
		}
		pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			return (m_tree.equal_range(k));
		}
		allocator_type get_allocator() const
		{
			return (m_tree.get_allocator());
		}
	};
}

#endif

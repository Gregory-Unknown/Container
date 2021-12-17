#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <utility>
#include <limits>
#include "map_iterator.hpp"
#include "rbtree.hpp"


namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			//typedef typename Alloc::template rebind<node >::other			allocator_type;
			typedef Alloc													allocator_type;
			typedef Key														key_type;
			typedef T														mapped_type;
			typedef ft::pair<const key_type, mapped_type>					value_type;
			typedef Compare													key_compare;
			//typedef map<key_type, mapped_type, key_compare, allocator_type>	value_compare;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			// typedef ft::map_iterator<const key_type	, mapped_type>			iterator;
			// typedef ft::const_map_iterator<const key_type, mapped_type>		const_iterator;
			// typedef ft::reverse_map_iterator<const Key, mapped_type>		reverse_iterator;
			// typedef ft::reverse_map_iterator<const Key, mapped_type>		const_reverse_iterator;
			typedef unsigned long											size_type;
			class															value_compare
			{
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {};
				public:
					typedef bool									result_type;
					typedef value_type								first_argument_type;
					typedef value_type								second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					};
			};
		private:
			tree<key_type, mapped_type, value_type, allocator_type, key_compare> m_tree;
		public:
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{

			}
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{

			}
			map (const map& x)
			{

			}
			~map()
			{

			}
			map& operator= (const map& x)
			{

			}
	};
}

#endif

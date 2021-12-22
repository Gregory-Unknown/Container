#ifndef FT_CONTAINERS_MAP_HPP
#define FT_CONTAINERS_MAP_HPP

#include <memory>
#include "rbtree.hpp"
#include "Iterator.hpp"

namespace ft {
	template< typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator< pair<const Key, T> > >
	class map {
	public:
		typedef Key													key_type;
		typedef T													mapped_type;
		typedef pair<const key_type, mapped_type>					value_type;
		typedef Compare												key_compare;
		typedef Alloc												allocator_type;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;

	private:
		class value_compare {
			friend class map;

		protected:
			key_compare _comp;
			explicit value_compare(Compare c) : _comp(c)
			{

			}

		public:
			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;

			bool operator()(const value_type &x, const value_type &y) const
			{
				return (_comp(x.first, y.first));
			}
		};

		RBTree<value_type, value_compare, allocator_type> _tree;

	public:
		typedef typename RBTree<value_type, value_compare, allocator_type>::iterator               iterator;
		typedef typename RBTree<value_type, value_compare, allocator_type>::const_iterator         const_iterator;
		typedef typename RBTree<value_type, value_compare, allocator_type>::reverse_iterator       reverse_iterator;
		typedef typename RBTree<value_type, value_compare, allocator_type>::const_reverse_iterator const_reverse_iterator;
		typedef typename RBTree<value_type, value_compare, allocator_type>::difference_type        difference_type;
		typedef typename RBTree<value_type, value_compare, allocator_type>::size_type              size_type;

		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		: _tree(RBTree<value_type, value_compare, allocator_type>(value_compare(comp), allocator_type(alloc)))
		{

		}
		template<typename InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value && ft::is_input_iterator_tag<typename InputIterator::iterator_category>::value>::type * = NULL)
		:_tree(RBTree<value_type, value_compare, allocator_type>(value_compare(comp), allocator_type(alloc)))
		{
			insert(first, last);
		}
		map(const map &src): _tree(src._tree)
		{

		}
		~map()
		{

		}
		map &operator=(const map &other)
		{
			if (this == &other)
				return (*this);
			_tree = other._tree;
			return (*this);
		}
		iterator begin()
		{
			return (_tree.begin());
		}
		const_iterator begin() const
		{
			return (_tree.begin());
		}
		iterator end()
		{
			return (_tree.end());
		}
		const_iterator                       end() const
		{
			return (_tree.end());
		}
		reverse_iterator rbegin()
		{
			return (_tree.rbegin());
		}
		const_reverse_iterator rbegin() const
		{
			return (_tree.rbegin());
		}
		reverse_iterator rend()
		{
			return (_tree.rend());
		}
		const_reverse_iterator rend() const
		{
			return (_tree.rend());
		}
		bool empty() const
		{
			return (_tree.empty());
		}
		size_type size() const
		{
			return (_tree.size());
		}
		size_type max_size() const
		{
			return (_tree.max_size());
		}

		mapped_type &operator[](const key_type &k)
		{
			ft::pair<iterator, bool> res = insert(ft::make_pair(k, mapped_type()));
			return ((*res.first).second);
		}

		pair<iterator, bool> insert(const value_type &val)
		{
			return (_tree.insert(val));
		}
		iterator insert(iterator position, const value_type &val)
		{
			return (_tree.insert(position, val));
		}
		template<typename InputIterator>
		void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value && ft::is_input_iterator_tag<typename InputIterator::iterator_category>::value>::type * = NULL)
		{
			_tree.insert(first, last);
		}
		void erase(iterator position)
		{
			_tree.erase(position);
		}
		size_type erase(const key_type &k)
		{
			return (_tree.erase(ft::make_pair(k, mapped_type())));
		}
		void erase(iterator first, iterator last)
		{
			_tree.erase(first, last);
		}
		void swap(map &x)
		{
			_tree.swap(x._tree);
		}
		void clear()
		{
			_tree.clear();
		}
		key_compare key_comp() const
		{
			return (_tree.value_comp()._comp);
		}
		value_compare value_comp() const
		{
			return (_tree.value_comp());
		}

		iterator find(const key_type &k)
		{
			return (_tree.find(ft::make_pair(k, mapped_type())));
		}
		const_iterator find(const key_type &k) const
		{
			return (_tree.find(ft::make_pair(k, mapped_type())));
		}
		size_type count(const key_type &k) const
		{
			return (_tree.count(ft::make_pair(k, mapped_type())));
		}
		iterator lower_bound(const key_type &k)
		{
			return (_tree.lower_bound(ft::make_pair(k, mapped_type())));
		}
		const_iterator lower_bound(const key_type &k) const
		{
			return (_tree.lower_bound(ft::make_pair(k, mapped_type())));
		}
		iterator upper_bound(const key_type &k)
		{
			return (_tree.upper_bound(ft::make_pair(k, mapped_type())));
		}
		const_iterator upper_bound(const key_type &k) const
		{
			return (_tree.upper_bound(ft::make_pair(k, mapped_type())));
		}
		pair<iterator, iterator> equal_range(const key_type &k)
		{
			return (_tree.equal_range(ft::make_pair(k, mapped_type())));
		}
		pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			return (_tree.equal_range(ft::make_pair(k, mapped_type())));
		}
		allocator_type get_allocator() const
		{
			return (_tree.get_allocator());
		}
	};
}

#endif

#ifndef FT_CONTAINERS_RB_TREE_HPP
# define FT_CONTAINERS_RB_TREE_HPP

namespace ft {
    template<typename T, typename Compare, typename Alloc, typename NodeAlloc> class RBTree;
    template<typename T> struct RBTreeNode;
}

# include <memory>
# include <iostream>
# include "map_iterator.hpp"

namespace ft
{
	template<typename T>
	void swap(T &a, T &b) {
		T tmp = a;
		a = b;
		b = tmp;
	}

	template<typename T>
	struct RBTreeNode {
		T			*value;
		RBTreeNode	*left;
		RBTreeNode	*right;
		RBTreeNode	*parent;
		bool		color;

		RBTreeNode(T *value): value(value), left(NULL), right(NULL), parent(NULL), color(true)
		{

		}
	};

	template< typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T>, typename NodeAlloc = std::allocator< RBTreeNode<T> > >
	class RBTree
	{
		public:
		typedef T										value_type;
		typedef Alloc									allocator_type;
		typedef NodeAlloc								node_allocator_type;
		typedef Compare									value_compare;
		typedef rb_tree_iterator<T, T*, T&>				iterator;
		typedef rb_tree_iterator<T, const T*, const T&>	const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef ptrdiff_t								difference_type;
		typedef size_t									size_type;

		private:
		allocator_type			_alloc;
		node_allocator_type		_node_alloc;
		value_compare			_comp;
		RBTreeNode<value_type>	*_root;
		RBTreeNode<value_type>	*_end;
		size_type				_size;

		RBTreeNode<value_type> *_find_leftmost_node(RBTreeNode<value_type> *node) const
		{
			while (node && node->left)
				node = node->left;
			return (node);
		}
		RBTreeNode<value_type> *_find_rightmost_node(RBTreeNode<value_type> *node) const
		{
			while (node && node->right)
				node = node->right;
			return (node);
		}
		RBTreeNode<value_type> *_create_node(const value_type &val)
		{
			value_type *p = _alloc.allocate(1);
			_alloc.construct(p, val);

			RBTreeNode<value_type> *node = _node_alloc.allocate(1);
			_node_alloc.construct(node, RBTreeNode<value_type>(p));

			return (node);
		}
		void _clear_node(RBTreeNode<value_type> *node)
		{
			if (node->value) {
				_alloc.destroy(node->value);
				_alloc.deallocate(node->value, 1);
			}
			_node_alloc.destroy(node);
			_node_alloc.deallocate(node, 1);
		}
		pair<RBTreeNode<value_type>*, bool> _bst_insert(RBTreeNode<value_type> *node)
		{
			if (!_root) {
				_root = node;
				return (ft::make_pair(node, true));
			}

			RBTreeNode<T> *x = _root;
			RBTreeNode<T> *y = NULL;

			while (x) {
				y = x;

				if (_comp(*x->value, *node->value))
					x = y->right;
				else if (_comp(*node->value, *x->value))
					x = y->left;
				else
					return (ft::make_pair(x, false));
			}

			node->parent = y;

			if (_comp(*y->value, *node->value))
				y->right = node;
			else
				y->left = node;

			return (ft::make_pair(node, true));
			}
			RBTreeNode<value_type> *_bst_erase(RBTreeNode<value_type> *node){
				if (!node)
					return (NULL);

			RBTreeNode<value_type> *parent = node->parent;

			if (!node->left && !node->right) {
				if (parent == _end) {
					_root = NULL;
				} else if (parent->left == node) {
					parent->left = NULL;
				} else {
					parent->right = NULL;
				}

				_clear_node(node);
				return (parent);
			}

			if (!node->right) {
				RBTreeNode<value_type> *left = node->left;

				if (node->parent == _end) {
					_root = left;
					left->parent = NULL;
				} else if (node->parent->left == node) {
					node->parent->left = left;
					left->parent = node->parent;
				} else {
					node->parent->right = left;
					left->parent = node->parent;
				}

				_clear_node(node);
				return (left);
			}

			if (!node->left) {
				RBTreeNode<value_type> *right = node->right;

				if (node->parent == _end) {
					_root = right;
					right->parent = NULL;
				} else if (node->parent->left == node) {
					node->parent->left = right;
					right->parent = node->parent;
				} else {
					node->parent->right = right;
					right->parent = node->parent;
				}

				_clear_node(node);
				return (right);
			}

			RBTreeNode<value_type> *prev = _find_rightmost_node(node->left);

			_alloc.destroy(node->value);
			_alloc.construct(node->value, *prev->value);

			return (_bst_erase(prev));
		}
		void _bst_clear(RBTreeNode<value_type> *node)
		{
			if (!node)
				return;
			_bst_clear(node->left);
			_bst_clear(node->right);
			_clear_node(node);
		}
		RBTreeNode<typename RBTree<T, Compare, Alloc, NodeAlloc>::value_type> *_bst_clone(RBTreeNode <value_type> *node, RBTreeNode <value_type> *parent)
		{
			if (!node)
				return (NULL);
			RBTreeNode<value_type> *new_node = _create_node(*node->value);
			new_node->parent = parent;
			new_node->color = node->color;
			new_node->left = _bst_clone(node->left, new_node);
			new_node->right = _bst_clone(node->right, new_node);
			return (new_node);
		}
		RBTreeNode<value_type> *_bst_find(const value_type &val, RBTreeNode<value_type> *node) const
		{
			if (!node)
				return (_end);
			if (_comp(*node->value, val))
				return (_bst_find(val, node->right));
			else if (_comp(val, *node->value))
				return (_bst_find(val, node->left));
			else
				return (node);
		}
		RBTreeNode<value_type> *_bst_lower_bound(const value_type &val, RBTreeNode<value_type> *node) const
		{
			if (!node)
				return (_end);
			if (_comp(*node->value, val))
				return (_bst_lower_bound(val, node->right));
			else {
				RBTreeNode<value_type> *left = _bst_lower_bound(val, node->left);
				return (left != _end ? left : node);
			}
		}
		RBTreeNode<value_type> *_bst_upper_bound(const value_type &val, RBTreeNode<value_type> *node) const
		{
			if (!node)
				return (_end);
			if (!_comp(val, *node->value))
				return (_bst_upper_bound(val, node->right));
			else {
				RBTreeNode<value_type> *left = _bst_upper_bound(val, node->left);
				return (left != _end ? left : node);
			}
		}
		void _rotateLeft(RBTreeNode<value_type> *node)
		{
			RBTreeNode<value_type> *right = node->right;
			node->right = right->left;

			if (node->right)
				node->right->parent = node;

			right->parent = node->parent;

			if (!node->parent)
				_root = right;
			else if (node == node->parent->left)
				node->parent->left = right;
			else
				node->parent->right = right;

			right->left = node;
			node->parent = right;
		}
		void _rotateRight(RBTreeNode<value_type> *node)
		{
			RBTreeNode<value_type> *left = node->left;
			node->left = left->right;

			if (node->left)
				node->left->parent = node;

			left->parent = node->parent;

			if (!node->parent)
				_root = left;
			else if (node == node->parent->left)
				node->parent->left = left;
			else
				node->parent->right = left;

			left->right = node;
			node->parent = left;
		}
		void _balance(RBTreeNode<value_type> *node)
		{
			RBTreeNode<value_type> *parent;
			RBTreeNode<value_type> *grandparent;
			RBTreeNode<value_type> *uncle;

			while (node != _root && node->color && node->parent->color) {
				parent = node->parent;
				grandparent = node->parent->parent;

				if (parent == grandparent->left) {
					uncle = grandparent->right;

					if (uncle && uncle->color) {
						grandparent->color = true;
						parent->color = false;
						uncle->color = false;
						node = grandparent;
					} else {
						if (node == parent->right) {
							_rotateLeft(parent);
							node = parent;
							parent = node->parent;
						}

						_rotateRight(grandparent);
						ft::swap(parent->color, grandparent->color);
						node = parent;
					}
				} else {
					uncle = grandparent->left;

					if (uncle && uncle->color) {
						grandparent->color = true;
						parent->color = false;
						uncle->color = false;
						node = grandparent;
					} else {
						if (node == parent->left) {
							_rotateRight(parent);
							node = parent;
							parent = node->parent;
						}

						_rotateLeft(grandparent);
						ft::swap(parent->color, grandparent->color);
						node = parent;
					}
				}
			}

			_root->color = false;
		}

		public:
		RBTree(const value_compare &comp = value_compare(), const allocator_type &alloc = allocator_type(), const node_allocator_type &node_alloc = node_allocator_type())
		: _alloc(alloc), _node_alloc(node_alloc), _comp(comp), _root(NULL), _size(0)
		{
			_end = _node_alloc.allocate(1);
			_node_alloc.construct(_end, RBTreeNode<value_type>(NULL));
		}
		RBTree(const RBTree &src)
		:_alloc(src._alloc), _node_alloc(src._node_alloc), _comp(src._comp), _root(NULL), _size(src._size)
		{
			_root = _bst_clone(src._root, NULL);
			_end = _node_alloc.allocate(1);
			_node_alloc.construct(_end, RBTreeNode<value_type>(NULL));
			if (_root) {
				_root->parent = _end;
				_end->left = _root;
			}
		}
		~RBTree()
		{
			clear();
			_clear_node(_end);
		}
		RBTree &operator=(const RBTree &other)
		{
			if (this == &other)
				return (*this);
			clear();
			_alloc = other._alloc;
			_node_alloc = other._node_alloc;
			_comp = other._comp;
			_root = _bst_clone(other._root, NULL);
			_size = other._size;

			return (*this);
		}
		iterator begin()
		{
			RBTreeNode<T> *node = _root;
			if (!node)
				return (end());
			return (iterator(_find_leftmost_node(node)));
		}
		const_iterator begin() const
		{
			RBTreeNode<T> *node = _root;
			if (!node)
				return (end());
			return (const_iterator(_find_leftmost_node(node)));
		}
		iterator end()
		{
			return (iterator(_end));
		}
		const_iterator end() const
		{
			return (const_iterator(_end));
		}
		reverse_iterator rbegin()
		{
			return (reverse_iterator(end()));
		}
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(end()));
		}
		reverse_iterator rend()
		{
			return (reverse_iterator(begin()));
		}
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(begin()));
		}
		bool empty() const
		{
			return (!_root);
		}
		size_type size() const
		{
			return (_size);
		}
		size_type max_size() const
		{
			size_type a = _alloc.max_size();
			size_type b = _node_alloc.max_size();
			return (a < b ? a : b);
		}
		pair<iterator, bool> insert(const value_type &value)
		{
			RBTreeNode<value_type> *node = _create_node(value);
			if (_root)
				_root->parent = NULL;
			ft::pair<RBTreeNode<value_type>*, bool> res = _bst_insert(node);
			if (!res.second) {
				_clear_node(node);
				_root->parent = _end;
				_end->left = _root;
				return (ft::make_pair(iterator(res.first), false));
			}
			_balance(node);
			_root->parent = _end;
			_end->left = _root;
			_size++;
			return (ft::make_pair(iterator(res.first), true));
		}
		iterator insert(iterator position, const value_type &val)
		{
			(void)position;
			return (insert(val).first);
		}
		template<typename InputIterator>
		void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value && ft::is_input_iterator_tag<typename InputIterator::iterator_category>::value>::type * = NULL)
		{
			while (first != last) {
				insert(*first);
				first++;
			}
		}
		void erase(iterator position)
		{
			RBTreeNode<value_type> *parent = _bst_erase(position.baseNode());
			if (parent != _end)
				_balance(parent);
			if (_size == 1) {
				_root = NULL;
			} else{
				_root->parent = _end;
				_end->left = _root;
			}
			_size--;
		}
		size_type erase(const value_type &val)
		{
			iterator it = find(val);
			if (it == end())
				return (0);

			erase(it);
			return (1);
		}
		void erase(iterator first, iterator last)
		{
			iterator next;
			while (first != last) {
				next = first;
				next++;
				erase(first);
				first = next;
			}
		}
		void swap(RBTree &x)
		{
			allocator_type         _alloc_tmp = this->_alloc;
			node_allocator_type    _node_alloc_tmp = this->_node_alloc;
			value_compare          _comp_tmp = this->_comp;
			RBTreeNode<value_type> *_root_tmp = this->_root;
			RBTreeNode<value_type> *_end_tmp = this->_end;
			size_type              _size_tmp = this->_size;

			this->_alloc = x._alloc;
			this->_node_alloc = x._node_alloc;
			this->_comp = x._comp;
			this->_root = x._root;
			this->_end = x._end;
			this->_size = x._size;

			x._alloc = _alloc_tmp;
			x._node_alloc = _node_alloc_tmp;
			x._comp = _comp_tmp;
			x._root = _root_tmp;
			x._end = _end_tmp;
			x._size = _size_tmp;
		}
		void clear()
		{
			_bst_clear(_root);
			_root = NULL;
			_size = 0;
		}
		value_compare value_comp() const
		{
			return (_comp);
		}
		iterator find(const value_type &val)
		{
			return (iterator(_bst_find(val, _root)));
		}
		const_iterator find(const value_type &val) const
		{
			return (const_iterator(_bst_find(val, _root)));
		}
		size_type count(const value_type &val) const
		{
			iterator it = find(val);
			return (it == end() ? 0 : 1);
		}
		iterator lower_bound(const value_type &val)
		{
			return (iterator(_bst_lower_bound(val, _root)));
		}
		const_iterator lower_bound(const value_type &val) const
		{
			return (const_iterator(_bst_lower_bound(val, _root)));
		}
		iterator upper_bound(const value_type &val)
		{
			return (iterator(_bst_upper_bound(val, _root)));
		}
		const_iterator upper_bound(const value_type &val) const
		{
			return (const_iterator(_bst_upper_bound(val, _root)));
		}
		pair<iterator, iterator> equal_range(const value_type &val)
		{
			return (ft::make_pair(lower_bound(val), upper_bound(val)));
		}
		pair<const_iterator, const_iterator> equal_range(const value_type &val) const
		{
			return (ft::make_pair(lower_bound(val), upper_bound(val)));
		}
		allocator_type get_allocator() const
		{
			return (_alloc);
		}
	};

}

#endif

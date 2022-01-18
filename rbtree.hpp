#ifndef FT_CONTAINERS_RB_TREE_HPP
# define FT_CONTAINERS_RB_TREE_HPP

namespace ft {
	template<typename T, typename Compare, typename Alloc, typename NodeAlloc> class RBTree;
	template<typename T> struct Tree;
}

# include <memory>
# include <iostream>
# include "tree_iterator.hpp"
#include "pair.hpp"

namespace ft
{
	template<typename T>
	void swap(T &a, T &b) {
		T tmp = a;
		a = b;
		b = tmp;
	}

	template<typename T>
	struct Tree {
		T			*value;
		Tree		*left;
		Tree		*right;
		Tree		*parent;
		bool		color;

		Tree(T *value): value(value), left(NULL), right(NULL), parent(NULL), color(true)
		{

		}
	};

	template< typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T>, typename NodeAlloc = std::allocator< Tree<T> > >
	class RBTree
	{
		public:
		typedef T																	value_type;
		typedef typename Alloc::template rebind<value_type >::other					allocator_type;
		typedef Tree<value_type>													node;
		typedef typename NodeAlloc::template rebind<node >::other					node_allocator_type;
		typedef Compare																value_compare;
		typedef rb_tree_iterator<value_type, value_type*, value_type&>				iterator;
		typedef rb_tree_iterator<value_type, const value_type*, const value_type&>	const_iterator;
		typedef ft::reverse_iterator<iterator>										reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;
		typedef ptrdiff_t															difference_type;
		typedef size_t																size_type;

		private:
		allocator_type			m_alloc;
		node_allocator_type		m_node_alloc;
		value_compare			m_comp;
		Tree<value_type>		*m_root;
		Tree<value_type>		*m_end;
		size_type				m_size;

		public:
		RBTree(const value_compare &comp = value_compare(), const allocator_type &alloc = allocator_type(), const node_allocator_type &nodem_alloc = node_allocator_type())
		: m_alloc(alloc), m_node_alloc(nodem_alloc), m_comp(comp), m_root(NULL), m_size(0)
		{
			m_end = m_node_alloc.allocate(1);
			m_node_alloc.construct(m_end, Tree<value_type>(NULL));
		}
		RBTree(const RBTree &src)
		:m_alloc(src.m_alloc), m_node_alloc(src.m_node_alloc), m_comp(src.m_comp), m_root(NULL), m_size(src.m_size)
		{
			m_root = clone_tree(src.m_root, NULL);
			m_end = m_node_alloc.allocate(1);
			m_node_alloc.construct(m_end, Tree<value_type>(NULL));
			if (m_root) {
				m_root->parent = m_end;
				m_end->left = m_root;
			}
		}
		~RBTree()
		{
			clear();
			clear(m_end);
		}
		RBTree &operator=(const RBTree &other)
		{
			if (this == &other) {
				clear();
				m_alloc = other.m_alloc;
				m_node_alloc = other.m_node_alloc;
				m_comp = other.m_comp;
				m_root = clone_tree(other.m_root, NULL);
				m_size = other.m_size;
			}

			return (*this);
		}
		iterator begin()
		{
			Tree<T> *node = m_root;
			if (!node)
				return (end());
			return (iterator(find_leftmost(node)));
		}
		const_iterator begin() const
		{
			Tree<T> *node = m_root;
			if (!node)
				return (end());
			return (const_iterator(find_leftmost(node)));
		}
		iterator end()
		{
			return (iterator(m_end));
		}
		const_iterator end() const
		{
			return (const_iterator(m_end));
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
			return (!m_root);
		}
		size_type size() const
		{
			return (m_size);
		}
		size_type max_size() const
		{
			size_type a = m_alloc.max_size();
			size_type b = m_node_alloc.max_size();
			return (a < b ? a : b);
		}
		pair<iterator, bool> insert(const value_type &value)
		{
			Tree<value_type> *node = create_tree(value);
			if (m_root)
				m_root->parent = NULL;
			ft::pair<Tree<value_type>*, bool> res = insert_tree(node);
			if (!res.second) {
				clear(node);
				m_root->parent = m_end;
				m_end->left = m_root;
				return (ft::make_pair(iterator(res.first), false));
			}
			balance_tree(node);
			m_root->parent = m_end;
			m_end->left = m_root;
			m_size++;
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
			Tree<value_type> *parent = erase_tree(position.geter());
			if (parent != m_end)
				balance_tree(parent);
			if (m_size == 1) {
				m_root = NULL;
			} else{
				m_root->parent = m_end;
				m_end->left = m_root;
			}
			m_size--;
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
			allocator_type			m_alloc_tmp = this->m_alloc;
			node_allocator_type		m_node_alloc_tmp = this->m_node_alloc;
			value_compare			m_comp_tmp = this->m_comp;
			Tree<value_type>		*m_root_tmp = this->m_root;
			Tree<value_type>		*m_end_tmp = this->m_end;
			size_type				m_size_tmp = this->m_size;

			this->m_alloc = x.m_alloc;
			this->m_node_alloc = x.m_node_alloc;
			this->m_comp = x.m_comp;
			this->m_root = x.m_root;
			this->m_end = x.m_end;
			this->m_size = x.m_size;

			x.m_alloc = m_alloc_tmp;
			x.m_node_alloc = m_node_alloc_tmp;
			x.m_comp = m_comp_tmp;
			x.m_root = m_root_tmp;
			x.m_end = m_end_tmp;
			x.m_size = m_size_tmp;
		}
		void clear()
		{
			clear_tree(m_root);
			m_root = NULL;
			m_size = 0;
		}
		value_compare valuem_comp() const
		{
			return (m_comp);
		}
		iterator find(const value_type &val)
		{
			return (iterator(find_tree(val, m_root)));
		}
		const_iterator find(const value_type &val) const
		{
			return (const_iterator(find_tree(val, m_root)));
		}
		size_type count(const value_type &val) const
		{
			iterator it = find(val);
			return (it == end() ? 0 : 1);
		}
		iterator lower_bound(const value_type &val)
		{
			return (iterator(lower_bound_tree(val, m_root)));
		}
		const_iterator lower_bound(const value_type &val) const
		{
			return (const_iterator(lower_bound_tree(val, m_root)));
		}
		iterator upper_bound(const value_type &val)
		{
			return (iterator(upper_bound_tree(val, m_root)));
		}
		const_iterator upper_bound(const value_type &val) const
		{
			return (const_iterator(upper_bound_tree(val, m_root)));
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
			return (m_alloc);
		}
		private:
		Tree<value_type> *find_leftmost(Tree<value_type> *node) const
		{
			while (node && node->left)
				node = node->left;
			return (node);
		}
		Tree<value_type> *find_rightmost(Tree<value_type> *node) const
		{
			while (node && node->right)
				node = node->right;
			return (node);
		}
		Tree<value_type> *create_tree(const value_type &val)
		{
			value_type *p = m_alloc.allocate(1);
			m_alloc.construct(p, val);

			Tree<value_type> *node = m_node_alloc.allocate(1);
			m_node_alloc.construct(node, Tree<value_type>(p));

			return (node);
		}
		void clear(Tree<value_type> *node)
		{
			if (node->value) {
				m_alloc.destroy(node->value);
				m_alloc.deallocate(node->value, 1);
			}
			m_node_alloc.destroy(node);
			m_node_alloc.deallocate(node, 1);
		}
		pair<Tree<value_type>*, bool> insert_tree(Tree<value_type> *node)
		{
			if (!m_root) {
				m_root = node;
				return (ft::make_pair(node, true));
			}

			Tree<T> *x = m_root;
			Tree<T> *y = NULL;

			while (x) {
				y = x;

				if (m_comp(*x->value, *node->value))
					x = y->right;
				else if (m_comp(*node->value, *x->value))
					x = y->left;
				else
					return (ft::make_pair(x, false));
			}

				node->parent = y;

				if (m_comp(*y->value, *node->value))
					y->right = node;
				else
					y->left = node;

				return (ft::make_pair(node, true));
		}
		Tree<value_type> *erase_tree(Tree<value_type> *node)
		{
			if (!node)
				return (NULL);
			Tree<value_type> *parent = node->parent;
			if (!node->left && !node->right) {
				if (parent == m_end) {
					m_root = NULL;
				} else if (parent->left == node) {
					parent->left = NULL;
				} else {
					parent->right = NULL;
				}
				clear(node);
				return (parent);
			}
			if (!node->right) {
				Tree<value_type> *left = node->left;
				if (node->parent == m_end) {
					m_root = left;
					left->parent = NULL;
				} else if (node->parent->left == node) {
					node->parent->left = left;
					left->parent = node->parent;
				} else {
					node->parent->right = left;
					left->parent = node->parent;
				}
				clear(node);
				return (left);
			}
			if (!node->left) {
				Tree<value_type> *right = node->right;
				if (node->parent == m_end) {
					m_root = right;
					right->parent = NULL;
				} else if (node->parent->left == node) {
					node->parent->left = right;
					right->parent = node->parent;
				} else {
					node->parent->right = right;
					right->parent = node->parent;
				}
				clear(node);
				return (right);
			}
			Tree<value_type> *prev = find_leftmost(node->right);
			m_alloc.destroy(node->value);
			m_alloc.construct(node->value, *prev->value);
			return (erase_tree(prev));
		}
		void clear_tree(Tree<value_type> *node)
		{
			if (!node)
				return;
			clear_tree(node->left);
			clear_tree(node->right);
			clear(node);
		}
		Tree<typename RBTree<T, Compare, Alloc, NodeAlloc>::value_type> *clone_tree(Tree <value_type> *node, Tree <value_type> *parent)
		{
			if (!node)
				return (NULL);
			Tree<value_type> *new_node = create_tree(*node->value);
			new_node->parent = parent;
			new_node->color = node->color;
			new_node->left = clone_tree(node->left, new_node);
			new_node->right = clone_tree(node->right, new_node);
			return (new_node);
		}
		Tree<value_type> *find_tree(const value_type &val, Tree<value_type> *node) const
		{
			if (!node)
				return (m_end);
			if (m_comp(*node->value, val))
				return (find_tree(val, node->right));
			else if (m_comp(val, *node->value))
				return (find_tree(val, node->left));
			else
				return (node);
		}
		Tree<value_type> *lower_bound_tree(const value_type &val, Tree<value_type> *node) const
		{
			if (!node)
				return (m_end);
			if (m_comp(*node->value, val))
				return (lower_bound_tree(val, node->right));
			else {
				Tree<value_type> *left = lower_bound_tree(val, node->left);
				return (left != m_end ? left : node);
			}
		}
		Tree<value_type> *upper_bound_tree(const value_type &val, Tree<value_type> *node) const
		{
			if (!node)
				return (m_end);
			if (!m_comp(val, *node->value))
				return (upper_bound_tree(val, node->right));
			else {
				Tree<value_type> *left = upper_bound_tree(val, node->left);
				return (left != m_end ? left : node);
			}
		}
		void rotate_left(Tree<value_type> *node)
		{
			Tree<value_type> *right = node->right;
			node->right = right->left;

			if (node->right)
				node->right->parent = node;

			right->parent = node->parent;

			if (!node->parent)
				m_root = right;
			else if (node == node->parent->left)
				node->parent->left = right;
			else
				node->parent->right = right;

			right->left = node;
			node->parent = right;
		}
		void rotate_right(Tree<value_type> *node)
		{
			Tree<value_type> *left = node->left;
			node->left = left->right;

			if (node->left)
				node->left->parent = node;

			left->parent = node->parent;

			if (!node->parent)
				m_root = left;
			else if (node == node->parent->left)
				node->parent->left = left;
			else
				node->parent->right = left;

			left->right = node;
			node->parent = left;
		}
		void balance_tree(Tree<value_type> *node)
		{
			Tree<value_type> *parent;
			Tree<value_type> *grandparent;

			while (node != m_root && node->color && node->parent->color) {
				parent = node->parent;
				grandparent = node->parent->parent;

				if (parent == grandparent->left) {
					Tree<value_type> *uncle = grandparent->right;

					if (uncle && uncle->color) {
						grandparent->color = true;
						parent->color = false;
						uncle->color = false;
						node = grandparent;
					} else {
						if (node == parent->right) {
							rotate_left(parent);
							node = parent;
							parent = node->parent;
						}

						rotate_right(grandparent);
						ft::swap(parent->color, grandparent->color);
						node = parent;
					}
				} else {
					Tree<value_type> *uncle = grandparent->left;

					if (uncle && uncle->color) {
						grandparent->color = true;
						parent->color = false;
						uncle->color = false;
						node = grandparent;
					} else {
						if (node == parent->left) {
							rotate_right(parent);
							node = parent;
							parent = node->parent;
						}

						rotate_left(grandparent);
						ft::swap(parent->color, grandparent->color);
						node = parent;
					}
				}
			}
			m_root->color = false;
		}
	};

}

#endif

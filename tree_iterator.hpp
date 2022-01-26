#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "Iterator.hpp"
#include "map.hpp"

namespace ft {

	template<typename T, typename Pointer, typename Reference>
	class rb_tree_iterator {
		Tree<T> *m_p;
	public:
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef Pointer						pointer;
		typedef Reference					reference;
		typedef bidirectional_iterator_tag	iterator_category;

		rb_tree_iterator(): m_p(NULL)
		{

		}
		explicit rb_tree_iterator(Tree<T> *node): m_p(node)
		{

		}
		template<typename SPointer, typename SReference>
		rb_tree_iterator(const rb_tree_iterator<T, SPointer, SReference> &src): m_p(src.geter())
		{

		}
		~rb_tree_iterator()
		{

		}
		template<typename SPointer, typename SReference>
		rb_tree_iterator &operator=(const rb_tree_iterator<T, SPointer, SReference> &src)
		{
			if (this != &src)
				m_p = src.geter();
			return (*this);
		}

		Tree<T> *geter() const
		{
			return (m_p);
		}

		reference operator*() const
		{
			return (*m_p->value);
		}
		pointer operator->() const
		{
			return (m_p->value);
		}
		rb_tree_iterator &operator++()
		{
			if (m_p->right) {
				m_p = m_p->right;
				while (m_p->left)
					m_p = m_p->left;
			} else {
				Tree<T> *tmp = m_p->parent;
				while (tmp && m_p == tmp->right) {
					m_p = tmp;
					tmp = tmp->parent;
				}
				m_p = m_p->parent;
			}
			return (*this);
		}
		const rb_tree_iterator operator++(int)
		{
			rb_tree_iterator it(*this);
			++(*this);
			return (it);
		}

		rb_tree_iterator &operator--()
		{
			if (m_p->left) {
				m_p = m_p->left;
				while (m_p->right)
					m_p = m_p->right;
			} else {
				Tree<T> *tmp = m_p->parent;
				while (tmp && m_p == tmp->left) {
					m_p = tmp;
					tmp = tmp->parent;
				}
				m_p = m_p->parent;
			}
			return (*this);
		}
		const rb_tree_iterator operator--(int)
		{
			rb_tree_iterator it(*this);
			--(*this);
			return (it);
		}
	};

	template<typename T, typename LPointer, typename LReference, typename RPointer, typename RReference>
	bool operator==(const rb_tree_iterator<T, LPointer, LReference> &lhs, const rb_tree_iterator<T, RPointer, RReference> &rhs) {
		return (lhs.geter() == rhs.geter());
	}

	template<typename T, typename LPointer, typename LReference, typename RPointer, typename RReference>
	bool operator!=(const rb_tree_iterator<T, LPointer, LReference> &lhs, const rb_tree_iterator<T, RPointer, RReference> &rhs) {
		return (!(lhs == rhs));
	}
}
#endif

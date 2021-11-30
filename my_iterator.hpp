#ifndef MY_ITERATOR_HPP
#define MY_ITERATOR_HPP

#include <cstddef>
#include "vector.hpp"

namespace ft {

    class input_iterator_tag{};
    class forward_iterator_tag : public input_iterator_tag{};
    class biderectional_iterator_tag : public forward_iterator_tag{};
    class random_access_iterator_tag : public biderectional_iterator_tag{};
    
    template<class Iterator>
    class iterator_traits {
    public:
        typedef typename Iterator::difference_type   difference_type;
        typedef typename Iterator::value_type        value_type;
        typedef typename Iterator::pointer           pointer;
        typedef typename Iterator::reference         reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template<class T>
    class iterator_traits<T*> {
        typedef ptrdiff_t                  difference_type;
        typedef T                          value_type;
        typedef T*                         pointer;
        typedef T&                         reference;
        typedef random_access_iterator_tag iterator_category;
    };

    template<class T>
    class iterator_traits<const T*> {
        typedef ptrdiff_t                  difference_type;
        typedef T                          value_type;
        typedef const T*                   pointer;
        typedef const T&                   reference;
        typedef random_access_iterator_tag iterator_category;
    };

    template<class T, class Pointer, class Reference>
    class vector_iterator {
    public:
        typedef T                          value_type;
        typedef ptrdiff_t                  difference_type;
        typedef Pointer                    pointer;
        typedef Reference                  reference;
        typedef random_access_iterator_tag iterator_category;

    private:
        pointer m_p;

    public:
        vector_iterator() : m_p(NULL)
        {

        }
        explicit vector_iterator(pointer p) : m_p(p)
        {

        }
        template<typename SPointer, typename SReference>
        explicit vector_iterator(const vector_iterator<T, SPointer, SReference> &src) : m_p(src.base())
        {

        }
        ~vector_iterator()
        {

        }
        pointer               base() const
        {
            return (m_p);
        }

        template<typename SPointer, typename SReference>
        vector_iterator       &operator=(vector_iterator<T, SPointer, SReference> const &other)
        {
            if (this != &other) {
                this->m_p = other.base();
            }
            return (*this);
        }
        reference             operator*() const
        {
            return (*m_p);
        }
        pointer               operator->() const
        {
            return (this->m_p);
        }

        vector_iterator &operator++()
        {
            ++m_p;
            return (*this);
        }
        const vector_iterator operator++(int)
        {
            vector_iterator tmp(*this);
            ++m_p;
            return (tmp);
        }

        vector_iterator &operator--()
        {
            --m_p;
            return (*this);
        }
        const vector_iterator operator--(int)
        {
            vector_iterator tmp(*this);
            --m_p;
            return (tmp);
        }

        vector_iterator       operator+(difference_type n) const
        {
            return (vector_iterator(m_p + n));
        }
        vector_iterator       operator-(difference_type n) const
        {
            return (vector_iterator(m_p - n));
        }

        vector_iterator       operator+=(difference_type n)
        {
            m_p += n;
            return (*this);
        }
        vector_iterator       operator-=(difference_type n)
        {
            m_p -= n;
            return (*this);
        }

        reference             operator[](difference_type n) const
        {
            return (m_p[n]);
        }
    };

    template<typename T, typename LPointer, typename LReference, typename RPointer, typename RReference>
    bool operator==(const vector_iterator<T, LPointer, LReference> &lhs, const vector_iterator<T, RPointer, RReference> &rhs) {
        return (lhs.base() == rhs.base());
    }

    template<typename T, typename LPointer, typename LReference, typename RPointer, typename RReference>
    bool operator!=(const vector_iterator<T, LPointer, LReference> &lhs, const vector_iterator<T, RPointer, RReference> &rhs) {
        return (lhs.base() != rhs.base());
    }

    template<typename T, typename LPointer, typename LReference, typename RPointer, typename RReference>
    bool operator<(const vector_iterator<T, LPointer, LReference> &lhs, const vector_iterator<T, RPointer, RReference> &rhs) {
        return (rhs > lhs);
    }

    template<typename T, typename LPointer, typename LReference, typename RPointer, typename RReference>
    bool operator>(const vector_iterator<T, LPointer, LReference> &lhs, const vector_iterator<T, RPointer, RReference> &rhs) {
        return (lhs.base() > rhs.base());
    }

    template<typename T, typename LPointer, typename LReference, typename RPointer, typename RReference>
    bool operator<=(const vector_iterator<T, LPointer, LReference> &lhs, const vector_iterator<T, RPointer, RReference> &rhs) {
        return (!(lhs > rhs));
    }

    template<typename T, typename LPointer, typename LReference, typename RPointer, typename RReference>
    bool operator>=(const vector_iterator<T, LPointer, LReference> &lhs, const vector_iterator<T, RPointer, RReference> &rhs) {
        return (!(rhs > lhs));
    }

    template<typename T, typename Pointer, typename Reference> vector_iterator<T, Pointer, Reference>
    operator+(typename vector_iterator<T, Pointer, Reference>::difference_type n, const vector_iterator<T, Pointer, Reference> x) {
        return (x + n);
    }

    template<typename T, typename Pointer, typename Reference> typename vector_iterator<T, Pointer, Reference>::difference_type
    operator-(const vector_iterator<T, Pointer, Reference> &lhs, const vector_iterator<T, Pointer, Reference> &rhs) {
        return (lhs.base() - rhs.base());
    }
    // struct input_iterator_tag{};
    // struct forward_iterator_tag : public input_iterator_tag{};
    // struct biderectional_iterator_tag : public forward_iterator_tag{};
    // struct random_access_iterator_tag : public biderectional_iterator_tag{};
    
    // template<class Iterator>
    // class iterator_traits {
    // public:
    //     typedef typename Iterator::difference_type   difference_type;
    //     typedef typename Iterator::value_type        value_type;
    //     typedef typename Iterator::pointer           pointer;
    //     typedef typename Iterator::reference         reference;
    //     typedef typename Iterator::iterator_category iterator_category;
    // };

    // template<class T>
    // class iterator_traits<T*> {
    //     typedef ptrdiff_t                  difference_type;
    //     typedef T                          value_type;
    //     typedef T*                         pointer;
    //     typedef T&                         reference;
    //     typedef random_access_iterator_tag iterator_category;
    // };

    // template<class T>
    // class iterator_traits<const T*> {
    //     typedef ptrdiff_t                  difference_type;
    //     typedef T                          value_type;
    //     typedef const T*                   pointer;
    //     typedef const T&                   reference;
    //     typedef random_access_iterator_tag iterator_category;
    // };
}

#endif
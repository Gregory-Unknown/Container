#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {

    template< class T, class Container = ft::vector<T> >
    class stack {
    public:
        typedef T         value_type;
        typedef Container container_type;
        typedef size_t    size_type;

    protected:
        container_type m_ctnr;

    public:
        explicit stack(const container_type &ctnr = container_type()) : m_ctnr(ctnr)
        {

        }
        // virtual ~stack() {}
        bool empty() const
        {
            return (m_ctnr.empty());
        }
        size_type size() const
        {
            return (m_ctnr.size());
        }
        value_type &top()
        {
            return (m_ctnr.back());
        }
        const value_type &top() const
        {
            return (m_ctnr.back());
        }
        void push(const value_type &val)
        {
            m_ctnr.push_back(val);
        }
        void pop()
        {
            m_ctnr.pop_back();
        }
        // friend bool operator==(const stack<T, Container> &l, const stack<T, Container> &r) {
        //     return (l.ctnr == r.ctnr);
        // }

        // friend bool operator!=(const stack<T, Container> &l, const stack<T, Container> &r) {
        //     return (l.ctnr != r.ctnr);
        // }

        // friend bool operator>(const stack<T, Container> &l, const stack<T, Container> &r) {
        //     return (l.ctnr > r.ctnr);
        // }

        // friend bool operator>=(const stack<T, Container> &l, const stack<T, Container> &r) {
        //     return (l.ctnr >= r.ctnr);
        // }

        // friend bool operator<(const stack<T, Container> &l, const stack<T, Container> &r) {
        //     return (l.ctnr < r.ctnr);
        // }

        // friend bool operator<=(const stack<T, Container> &l, const stack<T, Container> &r) {
        //     return (l.ctnr <= r.ctnr);
        // }
    };

    template <class T, class Container>
    bool operator== (const stack<T,Container>& l, const stack<T,Container>& r)
    {
        return (l.m_ctnr == r.m_ctnr);
    }
    template <class T, class Container>
    bool operator!= (const stack<T,Container>& l, const stack<T,Container>& r)
    {
        return (l.m_ctnr != r.m_ctnr);
    }
    template <class T, class Container>
    bool operator< (const stack<T,Container>& l, const stack<T,Container>& r)
    {
        return (l.m_ctnr < r.m_ctnr);
    } 
    template <class T, class Container>
    bool operator<= (const stack<T,Container>& l, const stack<T,Container>& r)
    {
        return (l.m_ctnr <= r.m_ctnr);
    }
    template <class T, class Container>
    bool operator>  (const stack<T,Container>& l, const stack<T,Container>& r)
    {
        return (l.m_ctnr > r.m_ctnr);
    }
    template <class T, class Container>
    bool operator>= (const stack<T,Container>& l, const stack<T,Container>& r)
    {
        return (l.m_ctnr >= r.m_ctnr);
    }
}

#endif
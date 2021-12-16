#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
	class pair
	{
		public:
			typedef T1	first_type;
			typedef T2	second_type;
		private:
			first_type	m_first;
			second_type	m_second;
		public:
			pair() : m_first(first_type()), m_second(second_type())
			{

			}
			template<class U, class V>
			pair(const pair<U,V>& src) : m_first(src.getFirst()), m_second(src.getSecond())
			{

			}
			pair(const first_type& a, const second_type& b) : m_first(a), m_second(b)
			{

			}
			~pair()
			{

			}
			pair& operator= (const pair& src)
			{
				m_first = src.getFirst();
				m_second = src.getSecond();
			}
			first_type getFirst() const
			{
				return (m_first);
			}
			second_type getSecond() const
			{
				return (m_second);
			}
			void setFirst(first_type first)
			{
				m_first = first;
			}
			void setSecond(second_type second)
			{
				m_second = second;
			}
	};
}

#endif

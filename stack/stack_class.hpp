#ifndef STACK_CLASS_HPP
# define STACK_CLASS_HPP

#include "../vector/vector_class.hpp"
#include "../vector/vector_impl.hpp"

namespace ft 
{


template <class T, class Container = vector<T> >
class stack 
{

public:

	// ******** Member type ********
	typedef	T				value_type;
	typedef	Container		container_type;
	typedef	size_t			size_type;

	// ******** Member function ********

	explicit stack (const container_type& ctnr = container_type()) : _container(ctnr) { };
	stack(const stack &src) : _container(src._container) { };
	stack &operator=(stack const &rhs) { _container = rhs._container; return *this; };
	~stack() { };

	bool empty() const { return _container.empty(); };
	size_type size() const { return _container.size(); }
	value_type& top() { return _container.back(); }
	const value_type& top() const { return _container.back(); }
	void push (const value_type& val) { _container.push_back(val); }
	void pop() { _container.pop_back(); }


friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{ return lhs._container == rhs._container; }

friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{ return lhs._container != rhs._container; }

friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{ return lhs._container < rhs._container; }

friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{ return lhs._container <= rhs._container; }

friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{ return lhs._container > rhs._container; }

friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{ return lhs._container >= rhs._container; }

private:
	container_type _container;

}; //-------------------end Vector Class 

}; //-------------------end Namespace ft


#endif
#ifndef LIST_IMPL_HPP
# define LIST_IMPL_HPP

#include "list_class.hpp"

namespace ft 
{

// *** Constructors ***

// default
template <typename T, typename Alloc>
list<T, Alloc>::list(const allocator_type& alloc) :
_size(0),
_alloc(alloc)
{
	_node = new Node<T>;
	_node->prev = _node;
	_node->next = _node;
}

// fill
template <typename T, typename Alloc>
list<T, Alloc>::list(size_type n, const value_type& val, const allocator_type& alloc) :
_size(0),
_alloc(alloc)
{
	_node = new Node<T>;
	_node->prev = _node;
	_node->next = _node;
	for (size_type i = 0; i < n; i++)
		push_back(val);
}

// range	
template <typename T, typename Alloc> template <class InputIterator>
list<T, Alloc>::list(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const allocator_type& alloc) :
_size(0),
_alloc(alloc)
{
	_node = new Node<T>;
	_node->prev = _node;
	_node->next = _node;
    while (first != last)
    {
        push_back(*first);
        first++;
    }
}

// copy
template <typename T, typename Alloc>
list<T, Alloc>::list(const list& x) :
_alloc(x._alloc),
_size(x._size)
{
	_node = new Node<T>;
	_node->prev = _node;
	_node->next = _node;
	*this = x;
}

// operator=
template <typename T, typename Alloc>
list<T, Alloc>& list<T, Alloc>::operator= (const list& x)
{
	clear();
	for (iterator it = x.begin(); it != x.end(); it++)
		push_back(*it);
	return (*this);
}



// *** Destructors ***
template <typename T, typename Alloc>
list<T, Alloc>::~list()
{
	clear();
	delete _node;
}



}; //-------------------end Namespace ft

#endif

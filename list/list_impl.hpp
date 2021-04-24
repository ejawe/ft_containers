/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_impl.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:06:31 by ejawe             #+#    #+#             */
/*   Updated: 2021/04/24 18:06:32 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
_size(0),
_alloc(x._alloc)

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
	for (const_iterator it = x.begin(); it != x.end(); it++)
		push_back(*it);
	return (*this);
}


// *** Destructors ***
template <typename T, typename Alloc>
list<T, Alloc>::~list()
{
	while(_size)
		pop_back();
	delete _node;
	
}


//---------------------------------------------------------------------------------------



// *** Iterator ***
template <typename T, typename Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::begin()
{ return iterator(_node->next); } 

template <typename T, typename Alloc>
typename list<T, Alloc>::const_iterator list<T, Alloc>::begin() const
{ return const_iterator(_node->next); } 

template <typename T, typename Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::end()
{ return iterator(_node); } 

template <typename T, typename Alloc>
typename list<T, Alloc>::const_iterator list<T, Alloc>::end() const
{ return const_iterator(_node); } 

template <typename T, typename Alloc>
typename list<T, Alloc>::reverse_iterator list<T, Alloc>::rbegin()
{ return reverse_iterator(_node->prev); }


template <typename T, typename Alloc>
typename list<T, Alloc>::const_reverse_iterator list<T, Alloc>::rbegin() const
{ return const_reverse_iterator(_node->prev); }

template <typename T, typename Alloc>
typename list<T, Alloc>::reverse_iterator list<T, Alloc>::rend()
{ return reverse_iterator(_node); } 


template <typename T, typename Alloc>
typename list<T, Alloc>::const_reverse_iterator list<T, Alloc>::rend() const
{ return const_reverse_iterator(_node); } 


//---------------------------------------------------------------------------------------


// *** Capacity ***
template <typename T, typename Alloc>
bool list<T, Alloc>::empty() const
{
    if (_size == 0)
        return true;
    return false;
}

template <typename T, typename Alloc>
typename list<T, Alloc>::size_type list<T, Alloc>::size() const
{ return _size; }

template <typename T, typename Alloc>
typename list<T, Alloc>::size_type list<T, Alloc>::max_size() const
{ return (std::numeric_limits<size_type>::max() / (sizeof(node) * 2)); } 


//---------------------------------------------------------------------------------------


// *** Element acces ***
template <typename T, typename Alloc>
typename list<T, Alloc>::reference list<T, Alloc>::front()
{ return _node->next->val; }

template <typename T, typename Alloc>
typename list<T, Alloc>::const_reference list<T, Alloc>::front() const
{ return _node->next->val; }

template <typename T, typename Alloc>
typename list<T, Alloc>::reference list<T, Alloc>::back()
{ return _node->prev->val; }

template <typename T, typename Alloc>
typename list<T, Alloc>::const_reference list<T, Alloc>::back() const
{ return _node->prev->val; }


//---------------------------------------------------------------------------------------


// *** Modifiers ***
// range
template <typename T, typename Alloc> template <class InputIterator>
void list<T, Alloc>::assign(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
{
    if (empty() == false)
        clear();
    while (first != last)
    {
        push_back(*first);
        first++;
    }
}

// fill
template <typename T, typename Alloc>
void list<T, Alloc>::assign(size_type n, const value_type& val)
{
    if (empty() == false)
        clear();
    for (size_type i = 0; i < n; i++)
        push_back(val);
}

template <typename T, typename Alloc>
void list<T, Alloc>::push_front (const value_type& val)
{
	Node<T>	*newnode = new Node<T>;

	newnode->next = _node->next;
	newnode->prev = _node;
	newnode->val = val;

	_node->next->prev = newnode;
	_node->next = newnode;
	_size++;
}

template <typename T, typename Alloc>
void list<T, Alloc>::pop_front()
{
	if (!_size)
		return;
	Node<T> *tmp = _node->next;
	_node->next = tmp->next;
	tmp->next->prev = _node;
	delete tmp;
	_size--;
}

template <typename T, typename Alloc>
void list<T, Alloc>::push_back (const value_type& val)
{

	Node<T> *newnode = new Node<T>;

	newnode->next = _node;
	newnode->prev = _node->prev;
	newnode->val = val;

	_node->prev->next = newnode;
	_node->prev = newnode;
	_size++;
}

template <typename T, typename Alloc>
void list<T, Alloc>::pop_back()
{
	Node<T> *tmp = _node->prev;
	_node->prev->prev->next = _node;
	_node->prev = _node->prev->prev;
	delete tmp;
	_size--;
}

// single element
template <typename T, typename Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::insert (iterator position, const value_type& val)
{
	Node<T> *newnode = new Node<T>;
	Node<T> *element = position.operator->();

	newnode->val = val;
	newnode->next = element->prev->next;
	newnode->prev = element->prev;

	element->prev->next = newnode;
	element->prev = newnode;

	_size++;
	return (--position);
}

// fill
template <typename T, typename Alloc>
void list<T, Alloc>::insert (iterator position, size_type n, const value_type& val)
{
	while (n--)
		position = insert(position, val);
}

// range	
template <typename T, typename Alloc> template <class InputIterator>
void list<T, Alloc>::insert (iterator position, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
{
	while (first != last)
	{
		position = insert(position, *(first++));
		if (position != end())
			position++;
	}
}

template <typename T, typename Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::erase (iterator position)
{
	Node<T> *element = position.operator->();
	Node<T> *ret = element->next;

	element->prev->next = element->next;
	element->next->prev = element->prev;

	delete element;
	_size--;
	return (ret);
}

template <typename T, typename Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::erase (iterator first, iterator last)
{
	while (first != last)
		erase(first++);
	return (first);
}

template <typename T, typename Alloc>
void list<T, Alloc>::swap (list& x)
{
	Node<T> *tmpnode = _node;
	size_type tmpsize = _size;

	_node = x._node;
	x._node = tmpnode;
	_size = x._size;
	x._size = tmpsize;
    // ft::swap(_node, x._node);
    // ft::swap(_alloc, x._alloc);
    // ft::swap(_size, x._size);
}

template <typename T, typename Alloc>
void list<T, Alloc>::resize (size_type n, value_type val)
{
	if (n < size())
	{
		iterator it = begin();
		for (size_t i = 0; i < n; i++)
			it++;
		erase(it, end());
	}
	else if (n > size())
		insert(end(), n - size(), val);
}

template <typename T, typename Alloc>
void list<T, Alloc>::clear()
{
	erase(begin(), end());
}



//---------------------------------------------------------------------------------------



// *** Operations ***
// entire list
template <typename T, typename Alloc>
void list<T, Alloc>::splice (iterator position, list& x)
{
	splice(position, x, x.begin(), x.end());
}


// single element
template <typename T, typename Alloc>
void list<T, Alloc>::splice (iterator position, list& x, iterator i)
{
	insert(position, *i);
	x.erase(i);
}


// element range
template <typename T, typename Alloc>
void list<T, Alloc>::splice (iterator position, list& x, iterator first, iterator last)
{
	insert(position, first, last);
	x.erase(first, last);
}

template <typename T, typename Alloc>
void list<T, Alloc>::remove (const value_type& val)
{
	iterator it = begin();
	while (it != end())
	{
		if (*it == val)
			it = erase(it);
		else
			it++;
	}	
}

template <typename T, typename Alloc> template <class Predicate>
void list<T, Alloc>::remove_if (Predicate pred)
{
	iterator it = begin();
	while (it != end())
	{
		if (pred(*it))
			it = erase(it);
		else
			it++;
	}
}

template <typename T, typename Alloc> 
void list<T, Alloc>::unique()
{
	iterator	prev = begin();
	iterator	next = ++begin();
	while (next != end())
	{
		if (*prev == *next)
		{
			erase(prev);
		}
		prev = next;
		++next;
	}
}


template <typename T, typename Alloc> template <class BinaryPredicate>
void list<T, Alloc>::unique (BinaryPredicate binary_pred)
{
	iterator	prev = begin();
	iterator	next = ++begin();
	while (next != end())
	{
		if (binary_pred(*next, *prev) == 1)
		{
			erase(next);
			prev = begin();
			next = ++begin();
		}
		else
		{
			prev = next;
			++next;
		}
	}
}

template <typename T, typename Alloc>
void list<T, Alloc>::merge (list& x)
{
	if (&x == this)
		return;
	merge(x, _less<value_type>());
}
	
template <typename T, typename Alloc> template <class Compare>
void list<T, Alloc>::merge (list& x, Compare comp)
{
	iterator 	startx = x.begin();
	iterator 	start = begin();

	while (startx != x.end() && start != end())
	{
		if (comp(*startx, *start))
		{
			splice(start, x, startx++);
		}
		else
			start++;
	}
	while (startx != x.end())
	{
		splice(end(), x, startx++);
	}
}

template <typename T, typename Alloc>
void list<T, Alloc>::sort()
{
	sort(_less<value_type>());
}

template <typename T, typename Alloc> template <class Compare>
void list<T, Alloc>::sort (Compare comp)
{
	iterator	prev = begin();
	iterator	next = ++begin();

	while (next != end())
	{
		if (*prev != *next && comp(*prev, *next) == false)
		{
			splice(prev, *this, next);
			prev = begin();
			next = ++begin();
		}
		else
		{
			prev = next;
			next++;
		}
	}
}

template <typename T, typename Alloc>
void list<T, Alloc>::reverse()
{
	list<value_type> nwlist;
	iterator it = begin();
	while (it != end())
	{
		nwlist.push_front(*(it));
		it++;
	}
		
	*this = nwlist;
}


//---------------------------------------------------------------------------------------


// *** Non-member function overloads ***

template <class T, class Alloc>
bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
    if (lhs.size() != rhs.size())
        return false;
	
    typename ft::list<T>::const_iterator	it_lhs = lhs.begin();
	typename ft::list<T>::const_iterator	it_rhs = rhs.begin();
    while (it_lhs != lhs.end())
    {
		
		if (*it_lhs != *it_rhs)
			return false;
        ++it_lhs; 
        ++it_rhs;
    }
    return true;
}

template <class T, class Alloc>
bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{ return (!(lhs == rhs)); }

template <class T, class Alloc>
bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
    typename ft::list<T>::const_iterator	it_lhs = lhs.begin();
	typename ft::list<T>::const_iterator	it_rhs = rhs.begin();

    while (it_lhs != lhs.end() && it_rhs != rhs.end() && *it_lhs == *it_rhs)
    {
        ++it_lhs; 
        ++it_rhs;
    }
    if (it_lhs == lhs.end())
        return (it_rhs != rhs.end());
    else if (it_rhs == rhs.end())
        return (false);
    return (*it_lhs < *it_rhs);
}

template <class T, class Alloc>
bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return (true);
	return (lhs < rhs);
}

template <class T, class Alloc>
bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return (false);
	return (!(lhs < rhs));
}

template <class T, class Alloc>
bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return (true);
	return (!(lhs < rhs));
}

template <class T, class Alloc>
void swap (list<T,Alloc>& x, list<T,Alloc>& y)
{ x.swap(y); };



}; //-------------------end Namespace ft

#endif

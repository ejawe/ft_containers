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
{ return reverse_iterator(_node); }


template <typename T, typename Alloc>
typename list<T, Alloc>::const_reverse_iterator list<T, Alloc>::rbegin() const
{ return const_reverse_iterator(_node); }

template <typename T, typename Alloc>
typename list<T, Alloc>::reverse_iterator list<T, Alloc>::rend()
{ return reverse_iterator(begin()); } // a verifier


template <typename T, typename Alloc>
typename list<T, Alloc>::const_reverse_iterator list<T, Alloc>::rend() const
{ return const_reverse_iterator(begin()); } // a verifier


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
{ return (std::numeric_limits<difference_type>::max() / (sizeof(Node<T>) / 2 ?: 1)); } // a verifier


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
	Node<T> *tmp = _node->next;
	
	_node->next = _node->next->next;
	delete tmp;
	_size--;
}

template <typename T, typename Alloc>
void list<T, Alloc>::push_back (const value_type& val)
{

	Node<T> *newnode = new Node<T>;

	newnode->next = _node;
	newnode->prev = _node->prev;
	new_node->val = val;

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

	element->prev->next = element->next;
	element->next->prev = element->prev;
	delete element;
	_size--;
	return (position);
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
}

template <typename T, typename Alloc>
void list<T, Alloc>::resize (size_type n, value_type val = value_type())
{
	if (n < size())
	{
		iterator it = begin();
		for (size_t i = 0; i < n; i++)
			++it;
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
		if (*it == value)
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

// template <typename T, typename Alloc>
// void list<T, Alloc>::merge (list& x)
// {

// }
	
// template <typename T, typename Alloc> template <class Compare>
// void list<T, Alloc>::merge (list& x, Compare comp);










}; //-------------------end Namespace ft

#endif

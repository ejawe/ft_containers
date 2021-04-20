#ifndef VECTOR_IMPL_HPP
# define VECTOR_IMPL_HPP

#include "../utils.hpp"
#include "vector_class.hpp"

namespace ft
{

// *** Constructors ***
// default
template <typename T, typename Alloc>
vector<T, Alloc>::vector(const allocator_type &alloc) :
_data(NULL),
_alloc(alloc),
_size(0),
_capacity(0)
{ }

// fill
template <typename T, typename Alloc>
vector<T, Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc) :
_data(NULL),
_alloc(alloc),
_size(0),
_capacity(0)
{
    for (size_type i = 0; i < n; i++)
        push_back(val);
}

// range
template <typename T, typename Alloc> template <class InputIterator>
vector<T, Alloc>::vector(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const allocator_type& alloc) :
_data(NULL),
_alloc(alloc),
_size(0),
_capacity(0)
{
    while (first != last)
    {
        push_back(*first);
        first++;
    }
}

// copy
template <typename T, typename Alloc>
vector<T, Alloc>::vector (const vector& x) :
_data(NULL),
_alloc(x._alloc),
_size(0),
_capacity(0)
{
    *this = x;
}

// operator=
template <typename T, typename Alloc>
vector<T, Alloc> &vector<T, Alloc>::operator=(const vector& x)
{
    clear();
    for (const_iterator it = x.begin(); it != x.end(); it++)
		push_back(*it);
    _size = x._size;
    _capacity = x._capacity;
    return (*this);
}

// *** Destructors ***
template <typename T, typename Alloc>
vector<T, Alloc>::~vector()
{
    clear();
}



//---------------------------------------------------------------------------------------



// *** Iterator ***
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator  vector<T, Alloc>::begin()
{ return iterator(_data); }

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator  vector<T, Alloc>::begin() const
{ return const_iterator(_data); }

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator  vector<T, Alloc>::end()
{ return iterator(_data + _size); }

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_iterator  vector<T, Alloc>::end() const
{ return const_iterator(_data + _size); }

template <typename T, typename Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin()
{ return reverse_iterator(end() - 1); }

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const
{ return const_reverse_iterator(end() - 1); }

template <typename T, typename Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend()
{ return reverse_iterator(begin() - 1); }

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const
{ return const_reverse_iterator(begin() - 1); }


//---------------------------------------------------------------------------------------


// *** Capacity ***
template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type   vector<T, Alloc>::size() const
{ return (_size); }

template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type    vector<T, Alloc>::max_size() const
{ return(_alloc.max_size()); }

template <typename T, typename Alloc>
void    vector<T, Alloc>::resize(size_type n, value_type val)
{
    if (n < _size)
    {
        for (size_type i = n + 1; i < _size; i++)
            _alloc.destroy(&_data[i]);
    }
    else if (n > _size)
    {
        for (size_type i = _size; i < n; i++)
            push_back(val);
    }
    _size = n;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::capacity() const
{ return (_capacity); }

template <typename T, typename Alloc>
bool		vector<T, Alloc>::empty() const
{
    if (_size == 0)
        return true;
    return false;
}

template <typename T, typename Alloc>
void 		vector<T, Alloc>::reserve (size_type n)
{
    if (n > max_size()) 
		throw std::length_error("lenght error");
    if (n > _capacity)
    {
        value_type *newdata;
        newdata = _alloc.allocate(n);
        for (size_type i = 0; i < _size; i++)
        {
            _alloc.construct(&newdata[i], _data[i]);
            _alloc.destroy(&_data[i]);
        }
        _alloc.deallocate(_data, _capacity);
        _data = newdata;
        _capacity = n;
    }
    return;
}



//---------------------------------------------------------------------------------------



// *** Element acces ***
template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::operator[] (size_type n)
{ return _data[n]; }

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[] (size_type n) const
{ return _data[n]; }

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n)
{
    if (n >= _size)
        throw std::out_of_range("Error: Out of range.");
    return _data[n];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const
{
    if (n >= _size)
        throw std::out_of_range("Error: Out of range.");
    return _data[n];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::front()
{ return _data[0]; }

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const
{ return _data[0]; }

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::back()
{ return _data[_size - 1]; }

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const
{ return _data[_size - 1]; }



//---------------------------------------------------------------------------------------


// *** Modifiers ***


template <typename T, typename Alloc> template <class InputIterator>
void vector<T, Alloc>::assign(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
{
    if (empty() == false)
        clear();
    while (first != last)
    {
        push_back(*first);
        first++;
    }
}

template <typename T, typename Alloc>
void    vector<T, Alloc>::assign (size_type n, const value_type& val)
{
    if (empty() == false)
        clear();
    for (size_type i = 0; i < n; i++)
        push_back(val);
}

template <typename T, typename Alloc>
void    vector<T, Alloc>::push_back (const value_type& val)
{
    if (_size == _capacity)
    {
        if (_size == 0)
            reserve(1);
        else
            reserve(_capacity * 2);
    }
    _data[_size] = val;
    _size++;
}

template <typename T, typename Alloc>
void    vector<T, Alloc>::pop_back()
{
    if (_size > 0)
    {
        _alloc.destroy(&_data[_size - 1]);
        _size--;
    }
}

// single element
template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator    vector<T, Alloc>::insert(iterator position, const value_type& val)
{
    insert(position, 1, val);
    return position;
}

// fill
template <typename T, typename Alloc>
void    vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
{
    iterator it = begin();
    if (_size + n >= _capacity)
        reserve(_size + n);
    size_type pos = 0;
    while (it != position)
    {
        it++;
        pos++;
    }
    if (_size)
    {
        ft::vector<T> newvec(begin(), end());
        size_type i = pos + n;
        size_type j = 0 + pos;
        while (i < _size + n)
        {
            _alloc.construct(&_data[i], newvec._data[j]);
            j++;
            i++;
        }
        i = pos;
        while (i < pos + n)
        {
            _alloc.destroy(&_data[i]);
            _alloc.construct(&_data[i], val);
            i++;
        }
    }
    else
    {
        for (size_type i = 0; i < n; ++i)
            _alloc.construct(&_data[i], val);
    }
    _size += n;
}

// range

template <typename T, typename Alloc> template <class InputIterator>
void 	 vector<T, Alloc>::insert(iterator position, InputIterator first, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type last)
{
    size_type n = last - first;
    iterator it = begin();
    if (_size + n >= _capacity)
        reserve(_size + n);
    size_type pos = 0;
    while (it != position)
    {
        it++;
        pos++;
    }
    if (_size)
    {
        ft::vector<T> newvec(begin(), end());
        size_type i = pos + n;
        size_type j = 0 + pos;
        while (i < _size + n)
        {
            _alloc.construct(&_data[i], newvec._data[j]);
            j++;
            i++;
        }
        i = pos;
        while (i < pos + n)
        {
            _alloc.destroy(&_data[i]);
            _alloc.construct(&_data[i], *first);
            i++;
            first++;
        }
    }
    else
    {
        for (size_type i = 0; i < n; i++, first++)
            _alloc.construct(&_data[i], *first);
    }
    _size += n;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator position)
{
    return erase(position, position + 1);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last)
{
    iterator it;
    size_type n = last - first;
    for (it = first; it != last; ++it) 
    {
        _alloc.destroy(&*it);
    }
    if (last < end())
    {
        for (it = first; last != end(); ++it, ++last)
        {
            _alloc.construct(&*it, *last);
            _alloc.destroy(&*last);
        }
    }
    _size -= n;
    return (first);
}

template <typename T, typename Alloc>
void vector<T, Alloc>::swap (vector& x)
{
    ft::swap(_alloc, x._alloc);
    ft::swap(_capacity, x._capacity);
    ft::swap(_size, x._size);
    ft::swap(_data, x._data);
}

template <typename T, typename Alloc>
void    vector<T, Alloc>::clear()
{
    if (!_data)
        return;
    if (_size > 0)
    {
        for (size_type i = 0; i < _size; i++)
            _alloc.destroy(&_data[i]);

    }
    _alloc.deallocate(_data, _capacity);
    _data = NULL;
    _size = 0;
    _capacity = 0;
}

//---------------------------------------------------------------------------------------


// *** Non-member function overloads ***



template <class T, class Alloc>
bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    for (size_t i = 0; i < lhs.size(); i++)
    {
        if (lhs[i] != rhs[i])
            return false;
    }
    return true;
}

template <class T, class Alloc>
bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{ return (!(lhs == rhs)); }

template <class T, class Alloc>
bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
    typename ft::vector<T>::const_iterator	it_lhs = lhs.begin();
	typename ft::vector<T>::const_iterator	it_rhs = rhs.begin();

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
bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return (true);
	return (lhs < rhs);
}

template <class T, class Alloc>
bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return (false);
	return (!(lhs < rhs));
}

template <class T, class Alloc>
bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return (true);
	return (!(lhs < rhs));
}

template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) 
{ x.swap(y); };

}; //-------------------end Namespace ft

#endif
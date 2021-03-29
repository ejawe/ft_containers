#ifndef VECTOR_IMPL_HPP
# define VECTOR_IMPL_HPP

#include <iostream>
#include <stdexcept>
#include <memory>
#include "enable_if.hpp"
#include "vector_class.hpp"
#include "Iterator.hpp"

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
template <typename T, typename Alloc>
template <class InputIterator>
vector<T, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type& alloc) :
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
_size(x._size),
_capacity(x._capacity)
{
    reserve(_capacity);
    if (x._data)
    {
        for (size_type i = 0; i < x._size; i++)
            push_back(x._data[i]);
    }
}

// operator=
template <typename T, typename Alloc>
vector<T, Alloc> &vector<T, Alloc>::operator=(const vector& x)
{
    clear();
    if (!x._data)
        return;
    reserve(x.capacity)
    for (iterator it = x.begin(); it != x.end(); it++)
		push_back(*it);
    _size = x._size;
    _capacity = x._capacity;
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
typename vector<T, Alloc>::iterator  vector<T, Alloc>::iterator begin()
{
    return iterator(this->_data);
}



typename vector<T, Alloc>::iterator  vector<T, Alloc>:: end()
{
    return iterator(this->_data + this->_size);
}


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
    false;
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
        _alloc.desallocate(_data, _capacity);
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
void    vector<T, Alloc>::assign(InputIterator first, InputIterator last, typename ft::enable_if<std::numeric_limits<InputIterator>::is_integer, InputIterator>::type = NULL) 
{
    if (empty() == false)
        clear();
    while (fisrt != last)
    {
        push_back(*first);
        fisrt++;
    }
}

template <typename T, typename Alloc>
void assign (size_type n, const value_type& val)
{
    if (empty() == false)
        clear();
    while (size_type i = 0; i < n; i++)
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
            reserve(_capacity);
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
        size_type i = pos + n;
        size_type j = 0;
        while (i < _size + n)
        {
            _alloc.construct(&_data[i], _data[pos + j]);
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
template <class InputIterator>
void 	 vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<std::numeric_limits<InputIterator>::is_integer, InputIterator>::type = NULL)
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
        size_type i = pos + n;
        size_type j = 0;
        while (i < _size + n)
        {
            _alloc.construct(&_data[i], _data[pos + j]);
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
    size_type n = first, last;

    for (it = first; it != last; ++it) 
    {
        _allocator.destroy(&*it);
    }
    if (last < end())
    {
        for (it = first; last != end(); ++it, ++last)
        {
            _allocator.construct(&*it, *last);
            _allocator.destroy(&*last);
        }
    }
    _size -= n;
    return (first);
}

template <typename T, typename Alloc>
void vector<T, Alloc>::swap (vector& x)
{
    std::swap(_alloc, x._alloc);
    std::swap(_capacity, x._capacity);
    std::swap(_size, x._size);
    std::swap(_data, x._data);
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
        _alloc.deallocate(_data, _capacity);
        _data = NULL;
        _size = 0;
        _capacity = 0;
    }
}


}; //-------------------end Namespace ft

#endif
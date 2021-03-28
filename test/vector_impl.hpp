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
template <typename T, typename Alloc>
vector<T, Alloc>::vector(const allocator_type &alloc) :
_data(NULL),
_alloc(alloc),
_size(0),
_capacity(0)
{
    return;
}

template <typename T, typename Alloc>
vector<T, Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc) :
_data(NULL),
_alloc(alloc),
_size(0),
_capacity(0)
{
    this->create_data(n, val);
    return;
}

template <typename T, typename Alloc>
vector<T, Alloc>::vector (const vector& x) :
{
    this->_data = NULL;
    this->_alloc = allocator_type();
    this->_size = 0;
    this->_capacity = 0;
    *this = src;
    return;
}


// *** Destructors ***
template <typename T, typename Alloc>
vector<T, Alloc>::~vector()
{
    this->destroy_data();
    return;
}


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




// *** Capacity ***
template <typename T, typename Alloc>
typename iterator begin();size_type   vector<T, Alloc>::size() const
{
    return (this->_size);
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const
{
    return(this->_alloc.max_size());
}

template <typename T, typename Alloc>
void    vector<T, Alloc>::resize(size_type n, value_type val)
{
    if (n < this->_size)
    {
        for (size_type i = n + 1; i < this->_size; i++)
            this->_alloc.destroy(&this->_data[i]);
    }
    else if (n > this->_size)
    {
        for (size_t i = this->_size; i < n; i++)
            // push_back(val)
    }
    this->_size = n;
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::capacity() const
{
    return (this->_capacity);
}

template <typename T, typename Alloc>
bool		vector<T, Alloc>::empty() const
{
    if (this->_size == 0)
        return true;
    false;
}

template <typename T, typename Alloc>
void 		vector<T, Alloc>::reserve (size_type n)
{
    if (n > this->_capacity)
    {
        value_type *newdata;
        newdata = this->_alloc.allocate(n);
        for (size_type i = 0; i < this->_size; i++)
        {
            this->_alloc>construct(&newdata[i], this->_data[i]);
            this->_alloc>destroy(&this->_data[i]);
        }
        this->_alloc.desallocate(this->_data, this->_capacity);
        this->_data = newdata;
        this->_capacity = n;
    }
    return;
}


// *** Element acces ***
template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::operator[] (size_type n)
{
    return this->_data[n];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[] (size_type n) const
{
    return this->_data[n];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n)
{
    if (n >= this->_capacity)
        throw std::out_of_range("Error: Out of range.");
    return this->_data[n];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const
{
    if (n >= this->_capacity)
        throw std::out_of_range("Error: Out of range.");
    return this->_data[n];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::front()
{
    return this->_data[0];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const
{
    return this->_data[0];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::back()
{
    return this->_data[this->_size - 1];
}

template <typename T, typename Alloc>
typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const
{
    return this->_data[this->_size - 1];
}





// *** Modifiers ***
template <typename T, typename Alloc>
template <class InputIterator> // ????????????
void    vector<T, Alloc>::assign(InputIterator first, InputIterator last, 
typename ft::enable_if<InputIterator::is_iterator, InputIterator>::type = NULL) 
{
    if (empty() == 0)
        clear();
    while (fisrt < last)
    {
        push_back(*first);
        fisrt++; // Iterator a faire
    }
}

template <typename T, typename Alloc>
void assign (size_type n, const value_type& val)
{
    if (empty() == 0)
        clear();
    while (size_type i = 0; i < n; i++)
        push_back(first);
}

template <typename T, typename Alloc>
void    vector<T, Alloc>::push_back (const value_type& val)
{
    if (this->_size == this->_capacity)
    {
        if (this->_size == 0)
            reserve(1);
        else
            reserve(this->_capacity * 2);
    }
    this->_data[this->_size] = val;
    this->_size++;
}

template <typename T, typename Alloc>
void    vector<T, Alloc>::pop_back()
{
    if (this->_size > 0)
    {
        this->_alloc>destroy(&this->_data[this->_size]);
        this->_size--;
    }
}

template <typename T, typename Alloc>
iterator    vector<T, Alloc>::insert (iterator position, const value_type& val)
{


}

template <typename T, typename Alloc>
void    vector<T, Alloc>::insert (iterator position, size_type n, const value_type& val)
{
    //size_type diff = (this->begin() - position);
    
}

// *** Private ***
template <typename T, typename Alloc>
void    vector<T, Alloc>::create_data(size_type size, const value_type &val)
{
    this->destroy_data();
    this->_data = this->_alloc.allocate(size);
    for (size_type i = 0; i < size; i++)
        this->_alloc.construct(&this->_data[i], val);
    this->_size = size;
    this->_capacity = size;
    return;
}

template <typename T, typename Alloc>
void    vector<T, Alloc>::destroy_data()
{
    if (!this->_data)
        return;
    while (this->_size > 0)
        this->_alloc.destroy(&this->_data[--this->_size]);
    this->_alloc.deallocate(this->_data, this->_capacity);
    this->_data = NULL;
    this->_size = 0;
    this->_capacity = 0;
    return;
}

}; //-------------------end Namespace ft

#endif
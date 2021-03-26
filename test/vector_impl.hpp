#ifndef VECTOR_IMPL_HPP
# define VECTOR_IMPL_HPP

#include <iostream>
#include "vector_class.hpp"
#include "memory"

namespace ft 
{

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
}

template <typename T, typename Alloc>
vector<T, Alloc>::~vector()
{
    this->destroy_data();
    return;
}





// *** Private ***
template <typename T, typename Alloc>
void    vector<T, Alloc>::create_data(size_type size, const value_type &val)
{
    this->destroy_data();
    this->_data = this->_alloc.allocate(size);
    for (size_type i = 0; i < size; i++)
        this->_alloc.construc(&this->_data[i], val);
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
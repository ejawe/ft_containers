#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "enable_if.hpp"

template <typename T>
class Iterator
{

public:

    // ******** Member type ********
    typedef     T                   value_type;
    typedef     std::ptrdiff_t      difference_type;
    typedef     value_type*         pointer;
    typedef     const value_type*   const_pointer;
    typedef     value_type&         reference;
    typedef     const value_type&   const_reference;
    static const bool               is_iterator = true;

    Iterator() { }
    Iterator(pointer ptr) : _ptr(ptr) { }
    Iterator(const Iterator& src) : _ptr(src._ptr) { }
    Iterator &operator=(Iterator const &src)
    {
        this->_ptr = src.operator->();
        return *this;
    }

    // *** Bool Operators ***
    bool	operator==(Iterator const& src) const { 
        return (this->_ptr == src._ptr);
    };
    bool	operator!=(Iterator const& src) const {
        return (this->_ptr != src._ptr); 
    };
    bool	operator>(Iterator const& src) const { 
        return (this->_ptr > src._ptr); 
    };
    bool	operator>=(Iterator const& src) const { 
        return (this->_ptr >= src._ptr); 
    };
    bool	operator<(Iterator const& src) const { 
        return (this->_ptr < src._ptr); 
    };
    bool	operator<=(Iterator const& src) const { 
        return (this->_ptr <= src._ptr); 
    };

    // *** Arithmetic Operators ***
    Iterator	        operator+(difference_type src) {
        return (Iterator(this->_ptr + src));
    };
    Iterator	        operator-(difference_type src) {
        return (Iterator(this->_ptr - src));
    };
    difference_type	    operator+(Iterator src) {
        return (this->_ptr + src._ptr);
    };
    difference_type		operator-(Iterator src) {
        return (this->_ptr - src._ptr);
    };
    Iterator operator++()
    {
        this->_ptr++;
        return *this;
    }
    Iterator operator++(int)
    {
        Iterator iterator = *this;
        ++(*this);
        return iterator;
    }
    Iterator operator--()
    {
        this->_ptr--;
        return *this;
    }
    Iterator operator--(int)
    {
        Iterator iterator = *this;
        --(*this);
        return iterator;
    }
    void    operator+=(difference_type src)
    {
        this->_ptr += src;
    }
    void    operator-=(difference_type src)
    {
        this->_ptr -= src;
    }

    // *** Dereferencing Operators ***
    pointer&		operator*() {
        return *this->_ptr;
    };
    const pointer*  operator*() const {
        return *this->_ptr;
    };
    pointer&		operator[](difference_type src) {
        return (*(this->_ptr + src));
    };
    const pointer& operator[](difference_type src) const {
        return (*(this->_ptr + src));
    };
    pointer*		operator->() {
        return (this->_ptr);
    };
    pointer*		operator->() const {
        return (this->_ptr); 
    };

private:
    pointer _ptr;

};

#endif
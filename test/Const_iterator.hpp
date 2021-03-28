#ifndef CONST_ITERATOR_HPP
# define CONST_ITERATOR_HPP

#include "enable_if.hpp"

template <typename T>
class Const_Iterator
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

    Const_Iterator() { }
    Const_Iterator(const pointer ptr) : _ptr(ptr) { }
    Const_Iterator(const Const_Iterator& src) : _ptr(src._ptr) { }
    Const_Iterator &operator=(Const_Iterator const &src)
    {
        this->_ptr = src.operator->();
        return *this;
    }

    // *** Bool Operators ***
    bool	operator==(Const_Iterator const& src) const { 
        return (this->_ptr == src._ptr);
    };
    bool	operator!=(Const_Iterator const& src) const {
        return (this->_ptr != src._ptr); 
    };
    bool	operator>(Const_Iterator const& src) const { 
        return (this->_ptr > src._ptr); 
    };
    bool	operator>=(Const_Iterator const& src) const { 
        return (this->_ptr >= src._ptr); 
    };
    bool	operator<(Const_Iterator const& src) const { 
        return (this->_ptr < src._ptr); 
    };
    bool	operator<=(Const_Iterator const& src) const { 
        return (this->_ptr <= src._ptr); 
    };

    // *** Arithmetic Operators ***
    Const_Iterator	        operator+(difference_type src) {
        return (Const_Iterator(this->_ptr + src));
    };
    Const_Iterator	        operator-(difference_type src) {
        return (Const_Iterator(this->_ptr - src));
    };
    difference_type	    operator+(Const_Iterator src) {
        return (this->_ptr + src._ptr);
    };
    difference_type		operator-(Const_Iterator src) {
        return (this->_ptr - src._ptr);
    };
    Const_Iterator operator++()
    {
        this->_ptr++;
        return *this;
    }
    Const_Iterator operator++(int)
    {
        Iterator iterator = *this;
        ++(*this);
        return iterator;
    }
    Const_Iterator operator--()
    {
        this->_ptr--;
        return *this;
    }
    Const_Iterator operator--(int)
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
#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "enable_if.hpp"

namespace ft
{
    template <typename T>
    class Iterator
    {

    public:

        // ******** Member type ********
        typedef     T                   value_type;
        typedef     std::ptrdiff_t      difference_type;
        // typedef     value_type*         pointer;
        // typedef     const value_type*   const_pointer;
        // typedef     value_type&         reference;
        // typedef     const value_type&   const_reference;

        Iterator() : _ptr(NULL) {}
        Iterator(value_type *ptr) : _ptr(ptr) {}
        Iterator(Iterator const &src) : _ptr(src._ptr) {}
        ~Iterator() { };
        Iterator &operator=(Iterator const &src)
        { _ptr = src.p; return *this; }



        // *** Bool Operators ***
        bool	operator==(Iterator const& src) const { return (_ptr == src._ptr); };
        bool	operator!=(Iterator const& src) const { return (_ptr != src._ptr); };
        bool	operator>(Iterator const& src) const { return (_ptr > src._ptr); };
        bool	operator>=(Iterator const& src) const { return (_ptr >= src._ptr); };
        bool	operator<(Iterator const& src) const { return (_ptr < src._ptr); };
        bool	operator<=(Iterator const& src) const { return (this->_ptr <= src._ptr); };



        // *** Arithmetic Operators ***
        Iterator        operator+(difference_type src) { return (Iterator(_ptr + src)); };
        Iterator        operator-(difference_type src) { return (Iterator(_ptr - src)); };
        Iterator        &operator++() { _ptr++; return *this; }
        Iterator        operator++(int) { Iterator it = *this; this->_ptr++; return it; }
        Iterator        &operator--() { _ptr--; return *this; }
        Iterator        operator--(int) { Iterator it = *this; this->_ptr--; return it; }
        Iterator        &operator+=(difference_type src) { _ptr += src; return (*this); };
        Iterator        &operator-=(difference_type src) { _ptr -= src; return (*this); };
        difference_type operator-(Iterator &src) { return (_ptr - src._ptr);}
        difference_type operator+(Iterator &src) { return (_ptr + src._ptr);}



        // *** Dereferencing Operators ***
        value_type&		operator*() { return *this->_ptr; };
        value_type&		operator[](difference_type src) { return (*(this->_ptr + src)); };
        value_type*		operator->() { return (this->_ptr); };

    private:
        value_type _ptr;

};

};

#endif
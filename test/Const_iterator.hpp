#ifndef CONST_ITERATOR_HPP
# define CONST_ITERATOR_HPP

#include "Iterator.hpp"

namespace ft
{
    template <typename T>
    class Const_Iterator
    {
    public:


        // ******** Member type ********
        typedef     T                   value_type;
        typedef     std::ptrdiff_t      difference_type;


        Const_Iterator() : _ptr(NULL) {}
        Const_Iterator(value_type *ptr) : _ptr(ptr) {}
        Const_Iterator(Const_Iterator const &src) : _ptr(src._ptr) {}
        ~Const_Iterator() { };
        Const_Iterator &operator=(Const_Iterator const &src)
        { _ptr = src.p; return *this; }



        // *** Bool Operators ***
        bool	operator==(Const_Iterator const& src) const { return (_ptr == src._ptr); };
        bool	operator!=(Const_Iterator const& src) const { return (_ptr != src._ptr); };
        bool	operator>(Const_Iterator const& src) const { return (_ptr > src._ptr); };
        bool	operator>=(Const_Iterator const& src) const { return (_ptr >= src._ptr); };
        bool	operator<(Const_Iterator const& src) const { return (_ptr < src._ptr); };
        bool	operator<=(Const_Iterator const& src) const { return (this->_ptr <= src._ptr); };



        // *** Arithmetic Operators ***
        Const_Iterator        operator+(difference_type src) { return (Const_Iterator(_ptr + src)); };
        Const_Iterator        operator-(difference_type src) { return (Const_Iterator(_ptr - src)); };
        Const_Iterator        &operator++() { _ptr++; return *this; }
        Const_Iterator        operator++(int) { Const_Iterator it = *this; this->_ptr++; return it; }
        Const_Iterator        &operator--() { _ptr--; return *this; }
        Const_Iterator        operator--(int) { Const_Iterator it = *this; this->_ptr--; return it; }
        Const_Iterator        &operator+=(difference_type src) { _ptr += src; return (*this); };
        Const_Iterator        &operator-=(difference_type src) { _ptr -= src; return (*this); };
        difference_type operator-(Const_Iterator &src) { return (_ptr - src._ptr);}
        difference_type operator+(Const_Iterator &src) { return (_ptr + src._ptr);}



        // *** Dereferencing Operators ***
        const value_type&		operator*() { return *this->_ptr; };
        const value_type&		operator[](difference_type src) { return (*(this->_ptr + src)); };
        const value_type*		operator->() { return (this->_ptr); };

    private:
        value_type _ptr;

};

};

#endif
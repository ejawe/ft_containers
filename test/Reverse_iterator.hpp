#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "Iterator.hpp"

namespace ft
{
    template <typename T>
    class Reverse_Iterator
    {
    public:


        // ******** Member type ********
        typedef     T                   value_type;
        typedef     std::ptrdiff_t      difference_type;


        Reverse_Iterator() : _ptr(NULL) {}
        Reverse_Iterator(value_type *ptr) : _ptr(ptr) {}
        Reverse_Iterator(Reverse_Iterator const &src) : _ptr(src._ptr) {}
        ~Reverse_Iterator() { };
        Reverse_Iterator &operator=(Reverse_Iterator const &src)
        { _ptr = src.p; return *this; }



        // *** Bool Operators ***
        bool	operator==(Reverse_Iterator const& src) const { return (_ptr == src._ptr); };
        bool	operator!=(Reverse_Iterator const& src) const { return (_ptr != src._ptr); };
        bool	operator>(Reverse_Iterator const& src) const { return (_ptr < src._ptr); };
        bool	operator>=(Reverse_Iterator const& src) const { return (_ptr <= src._ptr); };
        bool	operator<(Reverse_Iterator const& src) const { return (_ptr > src._ptr); };
        bool	operator<=(Reverse_Iterator const& src) const { return (this->_ptr >= src._ptr); };



        // *** Arithmetic Operators ***
        Reverse_Iterator        operator+(difference_type src) { return (Reverse_Iterator(_ptr - src)); };
        Reverse_Iterator        operator-(difference_type src) { return (Reverse_Iterator(_ptr + src)); };
        Reverse_Iterator        &operator++() { _ptr--; return *this; }
        Reverse_Iterator        operator++(int) { Reverse_Iterator it = *this; this->_ptr--; return it; }
        Reverse_Iterator        &operator--() { _ptr++; return *this; }
        Reverse_Iterator        operator--(int) { Reverse_Iterator it = *this; this->_ptr++; return it; }
        Reverse_Iterator        &operator+=(difference_type src) { _ptr -= src; return (*this); };
        Reverse_Iterator        &operator-=(difference_type src) { _ptr += src; return (*this); };
        difference_type 		operator-(Reverse_Iterator &src) { return (_ptr + src._ptr);}
        difference_type 		operator+(Reverse_Iterator &src) { return (_ptr - src._ptr);}



        // *** Dereferencing Operators ***
        const value_type&		operator*() { return *this->_ptr; };
        const value_type&		operator[](difference_type src) { return (*(this->_ptr + src)); };
        const value_type*		operator->() { return (this->_ptr); };

    private:
        value_type _ptr;

};

};

#endif
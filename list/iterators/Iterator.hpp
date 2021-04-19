#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "../list_class.hpp"

namespace ft
{
    template <typename T, typename node>
    class Iterator
    {

    public:

        // ******** Member type ********
        typedef     T                   value_type;
        typedef     std::ptrdiff_t      difference_type;
        typedef     node*               pointer;

        // ******** Constructors ********
        Iterator() : _ptr(NULL) {}
        Iterator(pointer ptr) { _ptr = ptr; } // X a;
        Iterator(Iterator const &src) { *this = src; } // X b(a);
        ~Iterator() { };
        Iterator &operator=(Iterator const &src) // b = a;
        { _ptr = src._ptr; return *this; }

        // *** Bool Operators ***
        bool	operator==(Iterator const& src) const { return (_ptr == src._ptr); }; // a == b
        bool	operator!=(Iterator const& src) const { return (_ptr != src._ptr); }; // a != 

        // *** Arithmetic Operators ***
        Iterator        &operator++() { _ptr = _ptr->next; return *this; } // ++a
        Iterator        operator++(int) { Iterator it = *this; ++(*this); return it; } // a++
        Iterator        &operator--() { _ptr = _ptr->prev; return *this; } // --a
        Iterator        operator--(int) { Iterator it = *this; --(*this); return it; } // a--

        // *** Dereferencing Operators ***
        value_type&             operator*() { return _ptr->val; };  // *a
        pointer                 operator->() { return _ptr; };  // a->m
        pointer                 operator ->() const { return (_ptr); };	
        
    private:
        pointer _ptr;

    };

};

#endif
#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "Iterator.hpp"

namespace ft
{
    template <typename iterator, typename node>
    class Reverse_Iterator
    {
    public:

        // ******** Member type ********
        typedef     typename iterator::value_type                   value_type;
        typedef     typename iterator::difference_type              difference_type;
        typedef     typename iterator::pointer			            pointer;

        // ******** Constructors ********
        Reverse_Iterator() {}
        Reverse_Iterator(pointer ptr) {_ptr = ptr; }
        Reverse_Iterator(Iterator<value_type, node> const &src) { _ptr = src.operator->(); } ;
        Reverse_Iterator(Reverse_Iterator const &src) { *this = src; } ;
        ~Reverse_Iterator() { };
        Reverse_Iterator &operator=(Reverse_Iterator const &src)
        { _ptr = src._ptr; return *this; }

        // *** Bool Operators ***
        bool	operator==(Reverse_Iterator const& src) const { return (_ptr == src._ptr); };
        bool	operator!=(Reverse_Iterator const& src) const { return (_ptr != src._ptr); };

        // *** Arithmetic Operators ***
        Reverse_Iterator        &operator++() {_ptr = _ptr->prev; return *this; }
        Reverse_Iterator        operator++(int) { Reverse_Iterator it = *this; --(*this); return it; }
        Reverse_Iterator        &operator--() { _ptr = _ptr->next; return *this; }
        Reverse_Iterator        operator--(int) { Reverse_Iterator it = *this; ++(*this); return it; }


        // *** Dereferencing Operators ***
        value_type&		operator*() { return _ptr->val; };
        pointer		    operator->() { return (_ptr); };
        pointer         operator ->() const { return (_ptr); };

    private:
        pointer _ptr;

    };
};

#endif
#ifndef CONST_ITERATOR_HPP
# define CONST_ITERATOR_HPP


namespace ft
{
    template <typename T, typename node>
    class Const_Iterator
    {

    public:

        // ******** Member type ********
        typedef     T                   value_type;
        typedef     std::ptrdiff_t      difference_type;
        typedef     node*               pointer;

		// ******** Constructors ********
        Const_Iterator() : _ptr(NULL) {}
        Const_Iterator(pointer ptr) { _ptr = ptr; }  // X a;
        Const_Iterator(Const_Iterator const &src) { *this = src; } // X b(a);
        ~Const_Iterator() {};
        Const_Iterator &operator=(Const_Iterator const &src) // b = a;
        { _ptr = src._ptr; return *this; }

        // *** Bool Operators ***
        bool	operator==(Const_Iterator const& src) const { return (_ptr == src._ptr); }; // a == b
        bool	operator!=(Const_Iterator const& src) const { return (_ptr != src._ptr); }; // a != b

        // *** Arithmetic Operators ***
        Const_Iterator        &operator++() { _ptr = _ptr->next; return *this; } // ++a
        Const_Iterator        operator++(int) { Const_Iterator it = *this; ++(*this); return it; } // a++
        Const_Iterator        &operator--() { _ptr = _ptr->prev; return *this; } // --a
        Const_Iterator        operator--(int) { Const_Iterator it = *this; --(*this); return it; } // a--

        // *** Dereferencing Operators ***
        const value_type&		operator*() { return _ptr->val; };  // *a
        const pointer   		operator->() { return _ptr; };  // a->m

    private:
        pointer _ptr;

    };

};

#endif
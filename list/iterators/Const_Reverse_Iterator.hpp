#ifndef CONST_REVERSE_ITERATOR_HPP
# define CONST_REVERSE_ITERATOR_HPP


namespace ft
{
    template <typename iterator, typename node>
    class Const_Reverse_Iterator
    {
    public:


        // ******** Member type ********
        typedef     typename iterator::value_type                   value_type;
        typedef     typename iterator::difference_type              difference_type;
        typedef     typename iterator::pointer			            pointer;


        // ******** Constructors ********
        Const_Reverse_Iterator() {}
        Const_Reverse_Iterator(pointer ptr) {_ptr = ptr; }
        Const_Reverse_Iterator(Iterator<value_type, node> const &src) { _ptr = src.operator->(); } ;
        Const_Reverse_Iterator(Const_Reverse_Iterator const &src) { *this = src; } ;
        ~Const_Reverse_Iterator() { };
        Const_Reverse_Iterator &operator=(Const_Reverse_Iterator const &src)
        { _ptr = src._ptr; return *this; }



        // *** Bool Operators ***
        bool	operator==(Const_Reverse_Iterator const& src) const { return (_ptr == src._ptr); };
        bool	operator!=(Const_Reverse_Iterator const& src) const { return (_ptr != src._ptr); };

        // *** Arithmetic Operators ***
        Const_Reverse_Iterator      &operator++() { _ptr = _ptr->prev; return *this; }
        Const_Reverse_Iterator      operator++(int) { Const_Reverse_Iterator it = *this; --(*this); return it; }
        Const_Reverse_Iterator      &operator--() { _ptr = _ptr->next; return *this; }
        Const_Reverse_Iterator      operator--(int) { Const_Reverse_Iterator it = *this; ++(*this); return it; }

        // *** Dereferencing Operators ***
        const value_type&		operator*() { return _ptr->val; };
        const pointer		    operator->() { return (_ptr); };
        const pointer           operator ->() const { return (_ptr); };

    private:
        pointer _ptr;

    };
};

#endif
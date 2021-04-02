#ifndef CONST_REVERSE_ITERATOR_HPP
# define CONST_REVERSE_ITERATOR_HPP


namespace ft
{
    template <typename iterator>
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
        Const_Reverse_Iterator(Iterator<value_type> const &src) { _ptr = src.operator->(); } ;
        Const_Reverse_Iterator(Const_Reverse_Iterator const &src) { *this = src; } ;
        ~Const_Reverse_Iterator() { };
        Const_Reverse_Iterator &operator=(Const_Reverse_Iterator const &src)
        { _ptr = src._ptr; return *this; }



        // *** Bool Operators ***
        bool	operator==(Const_Reverse_Iterator const& src) const { return (_ptr == src._ptr); };
        bool	operator!=(Const_Reverse_Iterator const& src) const { return (_ptr != src._ptr); };
        bool	operator>(Const_Reverse_Iterator const& src) const { return (_ptr < src._ptr); };
        bool	operator>=(Const_Reverse_Iterator const& src) const { return (_ptr <= src._ptr); };
        bool	operator<(Const_Reverse_Iterator const& src) const { return (_ptr > src._ptr); };
        bool	operator<=(Const_Reverse_Iterator const& src) const { return (this->_ptr >= src._ptr); };



        // *** Arithmetic Operators ***
        Const_Reverse_Iterator      operator+(difference_type src) { return (Const_Reverse_Iterator(_ptr - src)); };
        Const_Reverse_Iterator      operator-(difference_type src) { return (Const_Reverse_Iterator(_ptr + src)); };
        difference_type             operator-(Const_Reverse_Iterator &src) { return (_ptr + src._ptr);}
        difference_type             operator+(Const_Reverse_Iterator &src) { return (_ptr - src._ptr);}
        Const_Reverse_Iterator      &operator++() { _ptr--; return *this; }
        Const_Reverse_Iterator      operator++(int) { Const_Reverse_Iterator it = *this; this->_ptr--; return it; }
        Const_Reverse_Iterator      &operator--() { _ptr++; return *this; }
        Const_Reverse_Iterator      operator--(int) { Const_Reverse_Iterator it = *this; this->_ptr++; return it; }
        Const_Reverse_Iterator      &operator+=(difference_type src) { _ptr -= src; return (*this); };
        Const_Reverse_Iterator      &operator-=(difference_type src) { _ptr += src; return (*this); };




        // *** Dereferencing Operators ***
        const value_type&		operator*() { return *this->_ptr; };
        const value_type&		operator[](difference_type src) { return (*(this->_ptr + src)); };
        const value_type*		operator->() { return (this->_ptr); };
        const value_type*       operator ->() const { return (_ptr); };

    private:
        pointer _ptr;

    };
};

#endif
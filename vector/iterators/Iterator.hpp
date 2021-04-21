#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
    template <typename T>
    class Iterator
    {

    public:

        // ******** Member type ********
        typedef     T                   value_type;
        typedef     std::ptrdiff_t      difference_type;
        typedef     value_type*         pointer;


        // ******** Constructors ********
        Iterator() : _ptr(NULL) {}
        Iterator(value_type *ptr) : _ptr(ptr) {} // X a;
        Iterator(Iterator const &src) : _ptr(src._ptr) {} // X b(a);
        ~Iterator() { };
        Iterator &operator=(Iterator const &src) // b = a;
        { _ptr = src._ptr; return *this; }



        // *** Bool Operators ***
        bool	operator==(Iterator const& src) const { return (_ptr == src._ptr); }; // a == b
        bool	operator!=(Iterator const& src) const { return (_ptr != src._ptr); }; // a != b
        bool	operator<(Iterator const& src) const { return (_ptr < src._ptr); }; // a < b
        bool	operator>(Iterator const& src) const { return (_ptr > src._ptr); }; // a > b
        bool	operator<=(Iterator const& src) const { return (_ptr <= src._ptr); }; // a <= b
        bool	operator>=(Iterator const& src) const { return (_ptr >= src._ptr); }; // a >= b



        // *** Arithmetic Operators ***
        Iterator        operator+(difference_type src) { return (Iterator(_ptr + src)); }; // a + n
        Iterator        operator-(difference_type src) { return (Iterator(_ptr - src)); }; // a - n
        difference_type operator-(Iterator &src) { return (_ptr - src._ptr);} // a - b
        difference_type operator+(Iterator &src) { return (_ptr + src._ptr);} // a + b
        Iterator        &operator++() { _ptr++; return *this; } // ++a
        Iterator        operator++(int) { Iterator it = *this; this->_ptr++; return it; } // a++

        Iterator        &operator--() { _ptr--; return *this; } // --a
        Iterator        operator--(int) { Iterator it = *this; this->_ptr--; return it; } // a--
        Iterator        &operator+=(difference_type src) { _ptr += src; return (*this); }; // a += n
        Iterator        &operator-=(difference_type src) { _ptr -= src; return (*this); }; // a -= n



        // *** Dereferencing Operators ***
        value_type&             operator*() { return *this->_ptr; };  // *a
        value_type&             operator[](difference_type src) { return (*(this->_ptr + src)); }; // a[n]
        value_type*             operator->() { return this->_ptr; };  // a->m
        value_type*             operator ->() const { return (_ptr); };	
        
    private:
        value_type *_ptr;

    };

};

#endif
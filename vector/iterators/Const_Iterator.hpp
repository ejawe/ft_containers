/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Const_Iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:09:39 by ejawe             #+#    #+#             */
/*   Updated: 2021/04/24 18:09:41 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_ITERATOR_HPP
# define CONST_ITERATOR_HPP


namespace ft
{
    template <typename T>
    class Const_Iterator
    {

    public:

        // ******** Member type ********
        typedef     T                   value_type;
        typedef     std::ptrdiff_t      difference_type;



		// ******** Constructors ********
        Const_Iterator() : _ptr(NULL) {}
        Const_Iterator(value_type *ptr) : _ptr(ptr) {} // X a;
        Const_Iterator(Const_Iterator const &src) : _ptr(src._ptr) {} // X b(a);
        ~Const_Iterator() {};
        Const_Iterator &operator=(Const_Iterator const &src) // b = a;
        { _ptr = src._ptr; return *this; }



        // *** Bool Operators ***
        bool	operator==(Const_Iterator const& src) const { return (_ptr == src._ptr); }; // a == b
        bool	operator!=(Const_Iterator const& src) const { return (_ptr != src._ptr); }; // a != b
        bool	operator<(Const_Iterator const& src) const { return (_ptr < src._ptr); }; // a < b
        bool	operator>(Const_Iterator const& src) const { return (_ptr > src._ptr); }; // a > b
        bool	operator<=(Const_Iterator const& src) const { return (_ptr <= src._ptr); }; // a <= b
        bool	operator>=(Const_Iterator const& src) const { return (_ptr >= src._ptr); }; // a >= b



        // *** Arithmetic Operators ***
        Const_Iterator        operator+(difference_type src) { return (Const_Iterator(_ptr + src)); }; // a + n
        Const_Iterator        operator-(difference_type src) { return (Const_Iterator(_ptr - src)); }; // a - n
        difference_type operator-(Const_Iterator &src) { return (_ptr - src._ptr);} // a - b
        difference_type operator+(Const_Iterator &src) { return (_ptr + src._ptr);} // a + b
        Const_Iterator        &operator++() { _ptr++; return *this; } // ++a
        Const_Iterator        operator++(int) { Const_Iterator it = *this; this->_ptr++; return it; } // a++

        Const_Iterator        &operator--() { _ptr--; return *this; } // --a
        Const_Iterator        operator--(int) { Const_Iterator it = *this; this->_ptr--; return it; } // a--
        Const_Iterator        &operator+=(difference_type src) { _ptr += src; return (*this); }; // a += n
        Const_Iterator        &operator-=(difference_type src) { _ptr -= src; return (*this); }; // a -= n



        // *** Dereferencing Operators ***
        const value_type&		operator*() { return *this->_ptr; };  // *a
        const value_type&		operator[](difference_type src) { return (*(this->_ptr + src)); }; // a[n]
        const value_type*		operator->() { return this->_ptr; };  // a->m

    private:
        value_type *_ptr;

    };

};

#endif
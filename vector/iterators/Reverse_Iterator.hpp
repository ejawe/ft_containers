/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse_Iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:10:20 by ejawe             #+#    #+#             */
/*   Updated: 2021/04/27 16:33:11 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "Iterator.hpp"

namespace ft
{
    template <typename iterator>
    class Reverse_Iterator
    {
    public:


        // ******** Member type ********
        typedef     typename iterator::value_type                   value_type;
        typedef     typename iterator::difference_type              difference_type;

        // ******** Constructors ********
        Reverse_Iterator() { };
        Reverse_Iterator(value_type* ptr) {_ptr = ptr; };
        Reverse_Iterator(Iterator<value_type> const &src) { _ptr = src.operator->(); };
        Reverse_Iterator(Reverse_Iterator const &src) { *this = src; }; 
        ~Reverse_Iterator() { };
        Reverse_Iterator &operator=(Reverse_Iterator const &src)
        { _ptr = src._ptr; return *this; };



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
        difference_type 		operator-(Reverse_Iterator &src) { return (_ptr + src._ptr); };
        difference_type 		operator+(Reverse_Iterator &src) { return (_ptr - src._ptr); };
        Reverse_Iterator        &operator++() { _ptr--; return *this; };
        Reverse_Iterator        operator++(int) { Reverse_Iterator it = *this; this->_ptr--; return it; };
        Reverse_Iterator        &operator--() { _ptr++; return *this; };
        Reverse_Iterator        operator--(int) { Reverse_Iterator it = *this; this->_ptr++; return it; };
        Reverse_Iterator        &operator+=(difference_type src) { _ptr -= src; return (*this); };
        Reverse_Iterator        &operator-=(difference_type src) { _ptr += src; return (*this); };




        // *** Dereferencing Operators ***
        value_type&		operator*() { return *this->_ptr; };
        value_type&		operator[](difference_type src) { return (*(this->_ptr + src)); };
        value_type*		operator->() { return (this->_ptr); };
        value_type*     operator ->() const { return (_ptr); };

    private:
        value_type* _ptr;

    };
};

#endif
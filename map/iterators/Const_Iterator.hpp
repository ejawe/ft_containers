/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Const_Iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:07:09 by ejawe             #+#    #+#             */
/*   Updated: 2021/04/24 20:29:01 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_ITERATOR_HPP
# define CONST_ITERATOR_HPP

namespace ft
{
    template <typename iterator, typename node>
    class Const_Iterator
    {

    public:

        // ******** Member type ********
        typedef     typename iterator::value_type                   value_type;
        typedef     typename iterator::difference_type              difference_type;
        typedef     typename iterator::pointer			            pointer;

		// ******** Constructors ********
        Const_Iterator() : _ptr(NULL) {}
        Const_Iterator(node *ptr) { _ptr = ptr; }  // X a;
        Const_Iterator(iterator const &src) { _ptr = src.get_ptr(); } // X b(a);
        Const_Iterator(Const_Iterator const &src) { *this = src; } // X b(a);
        ~Const_Iterator() {};
        Const_Iterator &operator=(Const_Iterator const &src) // b = a;
        { _ptr = src._ptr; return *this; }

        // *** Bool Operators ***
        bool	operator==(Const_Iterator const& src) const { return (_ptr == src._ptr); }; // a == b
        bool	operator!=(Const_Iterator const& src) const { return (_ptr != src._ptr); }; // a != b

        // *** Arithmetic Operators ***
        Const_Iterator        &operator++() 
        {
            if (_ptr->right != NULL)
            {
                _ptr = _ptr->right;
                while (_ptr->left != NULL)
                    _ptr = _ptr->left;
            }
            else
            {
                node *child = _ptr;
                _ptr = _ptr->parent;
                while (_ptr->right == child)
                {
                    child = _ptr;
                    _ptr = _ptr->parent;
                }
            }
            return (*this);
        }
        Const_Iterator        operator++(int) { Const_Iterator it = *this; ++(*this); return it; } // a++
        Const_Iterator        &operator--() 
        {
            if (_ptr->left != NULL)
            {
                _ptr = _ptr->left;
                while (_ptr->right != NULL)
                    _ptr = _ptr->right;
            }
            else
            {
                node *child = _ptr;
                _ptr = _ptr->parent;
                while (_ptr && child == _ptr->left)
                {
                    child = _ptr;
                    _ptr = _ptr->parent;
                }
            }
            return (*this);
        }
        Const_Iterator        operator--(int) { Const_Iterator it = *this; --(*this); return it; } // a--

        // *** Dereferencing Operators ***
        const value_type&		operator*() { return _ptr->data; };  // *a
        const pointer   		operator->() { return &_ptr->data; };  // a->m

    private:
        node *_ptr;

    };

};

#endif
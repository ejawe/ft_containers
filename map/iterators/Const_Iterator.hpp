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
        typedef     value_type*         pointer;

		// ******** Constructors ********
        Const_Iterator() : _ptr(NULL) {}
        Const_Iterator(node *ptr) { _ptr = ptr; }  // X a;
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
#ifndef ITERATOR_HPP
# define ITERATOR_HPP


namespace ft
{
    template <typename T, typename node>
    class Iterator
    {

    public:

        // ******** Member type ********
        typedef     T                   value_type;
        typedef     std::ptrdiff_t      difference_type;
        typedef     value_type*         pointer;

        // ******** Constructors ********
        Iterator() : _ptr(NULL) {}
        Iterator(node *ptr) { _ptr = ptr; } // X a;
        Iterator(Iterator const &src) { *this = src; } // X b(a);
        ~Iterator() { };
        Iterator &operator=(Iterator const &src) // b = a;
        { _ptr = src._ptr; return *this; }

        // *** Bool Operators ***
        bool	operator==(Iterator const& src) const { return (_ptr == src._ptr); }; // a == b
        bool	operator!=(Iterator const& src) const { return (_ptr != src._ptr); }; // a != 

        // *** Arithmetic Operators ***
        Iterator        &operator++()  // ++a
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
        Iterator        operator++(int) { Iterator it = *this; ++(*this); return it; } // a++
        Iterator        &operator--() // --a
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
        Iterator        operator--(int) { Iterator it = *this; --(*this); return it; } // a--

        // *** Dereferencing Operators ***
        value_type&             operator*() { return _ptr->data; };  // *a
        pointer                 operator->() { return &_ptr->data; };  // a->m
        pointer                 operator ->() const { return &_ptr->data; };


        node               *get_ptr(void) const { return (_ptr); };
        
    private:
        node *_ptr;

    };

};

#endif
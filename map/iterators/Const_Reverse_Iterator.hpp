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
        Const_Reverse_Iterator      &operator++() 
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
        Const_Reverse_Iterator      operator++(int) { Const_Reverse_Iterator it = *this; ++(*this); return it; }
        Const_Reverse_Iterator      &operator--() 
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
        Const_Reverse_Iterator      operator--(int) { Const_Reverse_Iterator it = *this; --(*this); return it; }

        // *** Dereferencing Operators ***
        const value_type&		operator*() { return _ptr->data; };
        const pointer		    operator->() { return &_ptr->data; };
        const pointer           operator ->() const { return &_ptr->data; };

    private:
        node *_ptr;

    };
};

#endif
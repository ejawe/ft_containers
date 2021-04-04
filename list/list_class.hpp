#ifndef LIST_CLASS_HPP
# define LIST_CLASS_HPP

#include <iostream>
#include <memory>
#include <limits>
#include "../utils.hpp"
#include "iterators/Iterator.hpp"
#include "iterators/Const_Iterator.hpp"
#include "iterators/Reverse_Iterator.hpp"
#include "iterators/Const_Reverse_Iterator.hpp"

template <typename T>
struct Node
{
	Node	*prev;
	Node	*next;
	T		val;
};

namespace ft 
{

template < typename T, typename Alloc = std::allocator<T> >
class list 
{

public:

	// ******** Member type ********

	typedef				T										value_type;
	typedef				Alloc									allocator_type;
	typedef typename	allocator_type::reference				reference;
	typedef typename	allocator_type::const_reference			const_reference;
	typedef typename	allocator_type::pointer					pointer;
	typedef typename	allocator_type::const_pointer			const_pointer;
	typedef typename	ft::Iterator<T>							iterator;
	typedef typename	ft::Const_Iterator<T>					const_iterator;
	typedef typename	ft::Reverse_Iterator<iterator>			reverse_iterator;
	typedef typename	ft::Const_Reverse_Iterator<iterator>	const_reverse_iterator;
	typedef				std::ptrdiff_t							difference_type;
	typedef				size_t									size_type; 
	
	// ******** Member function ********

	// *** Constructors ***

	explicit list (const allocator_type& alloc = allocator_type());
	explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
	template <class InputIterator>
	list (typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type());
	list (const list& x);
	list& operator= (const list& x);


	// *** Destructors ***
	virtual ~list();

private:
	allocator_type	_alloc;
	size_type		_size;
	Node<T>			*_node;

}; //-------------------end List Class 


}; //-------------------end Namespace ft


#endif
#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

namespace ft {

template <typename T, typename Alloc = std::allocator<T>>
class vector {

public:

	// ******** Member type ********

	typedef 		 T									value_type;
	typedef 		 Alloc								allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	// iterator

	typedef 		 std::ptrdiff_t 					difference_type;
	typedef			 size_t								size_type; // ou typedef unsigned long size_type;


	// ******** Member function ********

	explicit vector (const allocator_type& alloc = allocator_type());


	// explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
	// template <class InputIterator>
    // vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
	// vector (const vector& x);


}; //-------------------end Vector Class 


}; //-------------------end Namespace ft

#endif 
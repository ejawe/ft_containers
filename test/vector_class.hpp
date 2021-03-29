#ifndef VECTOR_CLASS_HPP
# define VECTOR_CLASS_HPP

#include <iostream>
#include "enable_if.hpp"

namespace ft 
{

template < typename T, typename Alloc = std::allocator<T> >
class vector 
{

public:

	// ******** Member type ********

	typedef 		 T									value_type;
	typedef 		 Alloc								allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef typename ft::Iterator<T>					iterator;
	typedef typename ft::Const_iterator<T>				const_iterator;
	typedef typename ft::reverse_iterator<T>			reverse_iterator;
	typedef typename ft::const_reverse_iterator<T>		const_reverse_iterator;
	typedef 		 std::ptrdiff_t 					difference_type;
	typedef			 size_t								size_type; 

	// ******** Member function ********

	// *** Constructors ***
	explicit vector (const allocator_type& alloc = allocator_type());
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
	template <class InputIterator>
    vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
	vector (const vector& x);
	vector& operator= (const vector& x);

	// *** Destructors ***
	virtual ~vector();

	// *** Iterator ***
	iterator begin();
	iterator end();

	// *** Capacity ***
	size_type 	size() const;
	size_type 	max_size() const;
	void 		resize(size_type n, value_type val = value_type());
	size_type	capacity() const;
	bool		empty() const;
	void 		reserve (size_type n);

	// *** Element acces ***
    reference 		operator[] (size_type n);
	const_reference operator[] (size_type n) const;
	reference 		at(size_type n);
	const_reference at(size_type n) const;
	reference 		front();
	const_reference front() const;
	reference 		back();
	const_reference back() const;

	// *** Modifiers ***
	template <class InputIterator>
	void 		assign(InputIterator first, InputIterator last, typename ft::enable_if<std::numeric_limits<InputIterator>::is_integer, InputIterator>::type = NULL);
	void 		assign(size_type n, const value_type& val);
	void 		push_back (const value_type& val);
	void 		pop_back();
	iterator 	insert(iterator position, const value_type& val);
	void 		insert(iterator position, size_type n, const value_type& val);
	template <class InputIterator>
    void 		insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<std::numeric_limits<InputIterator>::is_integer, InputIterator>::type = NULL);
	iterator 	erase(iterator position);
	iterator 	erase(iterator first, iterator last);
	void		swap (vector& x);
	void		clear();
private:
	value_type		*_data;
	allocator_type	_alloc;
	size_type		_size;
	size_type		_capacity;
	
}; //-------------------end Vector Class 


}; //-------------------end Namespace ft

#endif 
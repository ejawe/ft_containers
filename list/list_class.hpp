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
	typedef				Node<T>									node;
	typedef typename	ft::Iterator<T, node>					iterator;
	typedef typename	ft::Const_Iterator<T, node>				const_iterator;
	typedef typename	ft::Reverse_Iterator<iterator, node>	reverse_iterator;
	typedef typename	ft::Const_Reverse_Iterator<iterator, node>	const_reverse_iterator;
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

	// *** Iterator ***
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	// *** Capacity ***
	bool empty() const;
	size_type size() const;
	size_type max_size() const;

	// *** Element acces ***
	reference front();
	const_reference front() const;
	reference back();
	const_reference back() const;

	// *** Modifiers ***
	template <class InputIterator>
	void assign (typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last);	
	void assign (size_type n, const value_type& val);
	void push_front (const value_type& val);
	void pop_front();
	void push_back (const value_type& val);
	void pop_back();	
	iterator insert (iterator position, const value_type& val);
	void insert (iterator position, size_type n, const value_type& val);	
	template <class InputIterator>
	void insert (iterator position, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last);
	iterator erase (iterator position);
	iterator erase (iterator first, iterator last);
	void swap (list& x);
	void resize (size_type n, value_type val = value_type());
	void clear();

	// *** Operations ***
	void splice (iterator position, list& x);
	void splice (iterator position, list& x, iterator i);
	void splice (iterator position, list& x, iterator first, iterator last);
	void remove (const value_type& val);
	template <class Predicate>
	void remove_if (Predicate pred);
	void unique();
	template <class BinaryPredicate>
	void unique (BinaryPredicate binary_pred);
	void merge (list& x);
	template <class Compare>
	void merge (list& x, Compare comp);
	void sort();
	template <class Compare>
	void sort (Compare comp);
	void reverse();

private:
	size_type		_size;
	allocator_type	_alloc;
	Node<T>			*_node;
	// prev : dernier node, next : premier node

	template <typename T1>
	struct _less 
	{
		bool operator()(const T1 &x, const T1 &y)
		{
			return x > y;
		};
	};

}; //-------------------end List Class 


}; //-------------------end Namespace ft


#endif
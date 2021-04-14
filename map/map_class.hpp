#ifndef MAP_CLASS_HPP
# define MAP_CLASS_HPP

#include <iostream>
#include <memory>
#include <limits>
#include "../utils.hpp"
#include "iterators/Iterator.hpp"
#include "iterators/Const_Iterator.hpp"
#include "iterators/Reverse_Iterator.hpp"
#include "iterators/Const_Reverse_Iterator.hpp"

namespace ft 
{


// ******** Compare default value ********
template <typename T1>
struct s_less 
{
	bool operator()(const T1 &x, const T1 &y)
	{
		return x < y;
	};
};



//---------------------------------------------------------------------------------------



// ******** Structure Pair ********
template <class T1, class T2> 
struct pair
{
	typedef T1		first_type;
	typedef T2		second_type;

	// ******** Data ********
	first_type	_first;
	second_type _second;

	// ******** Member function ********

	pair() { };
	template<class U, class V>
	pair (const pair<U, V> &pr) : _first(pr.first), _second(pr.second) { };
	pair (const first_type& a, const second_type& b) : _first(a), _second(b) { };
	~pair() { };

	pair& operator= (const pair& pr)
	{
		if (this != &pr)
		{
			_first = pr.first;
			_second = pr.second;
		}
		return *this;
	}

};

// ******** Non-member function overloads - Pair ********

template <class T1, class T2>
bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return (lhs.first == rhs.first && lhs.second == rhs.second); }

template <class T1, class T2>
bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs == rhs); }

template <class T1, class T2>
bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

template <class T1, class T2>
bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(rhs < lhs); }

template <class T1, class T2>
bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs < lhs; }

template <class T1, class T2>
bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs < rhs); }



//---------------------------------------------------------------------------------------



// ******** Structure Node ********
template <typename T>
struct Node
{
	Node	*left;
	Node	*right;
	Node	*parent;
	T		data;
};

template <typename T>
Node<T>	*last_right(Node<T> *node) {
	while (node->right != NULL)
		node = node->right;
	return (node);
}

template <typename T>
Node<T>	*first_left(Node<T> *node) {
	while (node->left != NULL)
		node = node->left;
	return (node);
}

template <typename T>
Node<T>	*get_right(Node<T> *node) {
	return (node->right);
}

template <typename T>
Node<T>	*get_left(Node<T> *node) {
	return (node->left);
}

template <typename T>
Node<T>	*get_parent(Node<T> *node) {
	return (node->parent);
}




//---------------------------------------------------------------------------------------




template <  class Key,
			class T,
			class Compare = ft::s_less<Key>,
			class Alloc = std::allocator<pair<const Key,T> >
		 >
class map
{

public:

	// ******** Member type ********

	typedef				Key											key_type;
	typedef				T											mapped_type;
	typedef				ft::pair<const key_type,mapped_type>		value_type;
	typedef				Compare										key_compare;
	class 															value_compare;
	typedef				Alloc										allocator_type;
	typedef typename	allocator_type::reference					reference;
	typedef typename	allocator_type::const_reference				const_reference;
	typedef typename	allocator_type::pointer						pointer;
	typedef typename	allocator_type::const_pointer				const_pointer;
	typedef				Node<value_type>							node_type;
	typedef typename	ft::Iterator<value_type, node>				iterator;
	typedef typename	ft::Const_Iterator<value_type, node>		const_iterator;
	typedef typename	ft::Reverse_Iterator<iterator, node>		reverse_iterator;
	typedef typename	ft::Const_Reverse_Iterator<iterator, node>	const_reverse_iterator;
	typedef				std::ptrdiff_t								difference_type;
	typedef				size_t										size_type; 


	// ******** Member function ********

	// *** Constructors ***
	explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	template <class InputIterator>
	map (typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first,
	InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	map (const map& x);
	map& operator= (const map& x);

	// *** Destructors ***
	~map();

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
	mapped_type& operator[] (const key_type& k);

	// *** Modifiers ***
	pair<iterator,bool> insert (const value_type& val);
	iterator insert (iterator position, const value_type& val);
	template <class InputIterator>
	void insert (typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last);
	void erase (iterator position);
	size_type erase (const key_type& k);
    void erase (iterator first, iterator last);
	void swap (map& x);
	void clear();

	// *** Observer ***
	key_compare key_comp() const;
	value_compare value_comp() const;

	// *** Operations ***
	iterator find (const key_type& k);
	const_iterator find (const key_type& k) const;
	size_type count (const key_type& k) const;
	iterator lower_bound (const key_type& k);
	const_iterator lower_bound (const key_type& k) const;
	iterator upper_bound (const key_type& k);
	const_iterator upper_bound (const key_type& k) const;
	pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
	pair<iterator,iterator> equal_range (const key_type& k);
	
private:
	size_type			_size;
	allocator_type		_alloc;
	node_type			*_node;
	key_compare			_key_comp;

	void add_node(node_type newNode);

}; //-------------------end Map Class 


}; //-------------------end Namespace ft

#endif 
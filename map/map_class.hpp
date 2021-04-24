/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:08:00 by ejawe             #+#    #+#             */
/*   Updated: 2021/04/24 18:08:01 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CLASS_HPP
# define MAP_CLASS_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <limits>
#include <cstddef> 
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
	bool operator()(const T1 &x, const T1 &y) const
	{
		return x < y;
	}
};



//---------------------------------------------------------------------------------------



// ******** class Pair ********
template <typename T1, typename T2> 
class pair
{
public:

	// ******** Data ********
	T1		first;
	T2		second;

	// ******** Member function ********

	pair() : first(), second() { };
	template<class U, class V>
	pair (const pair<U, V> &pr) : first(pr.first), second(pr.second) { };
	pair (const T1& a, const T2& b) : first(a), second(b) { };
	~pair() { };

	pair& operator= (const pair& pr)
	{
		if (this != &pr)
		{
			first = pr.first;
			second = pr.second;
		}
		return *this;
	};

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
Node<T>	*last_right(Node<T> *node) 
{
	if (node == NULL)
		return NULL;
	while (node->right != NULL)
		node = node->right;
	return (node);
}

template <typename T>
Node<T>	*first_left(Node<T> *node) 
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

template <typename T>
bool is_leaf(Node<T> *node) 
{
	if (node->left == NULL && node->right == NULL)
		return true;
	return false;
}

template <typename T>
bool one_child(Node<T> *node) 
{
	if ((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL))
		return true;
	return false;
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

	typedef				Key												key_type;
	typedef				T												mapped_type;
	typedef				ft::pair<key_type,mapped_type>					value_type;
	typedef				Compare											key_compare;
	class 				value_compare 
	{
	public:
		Compare comp;
		value_compare(Compare c) : comp(c) { };

		typedef bool		result_type;
		typedef value_type	first_argument_type;
		typedef value_type	second_argument_type;

		bool	operator()(const value_type &x, const value_type &y) const 
		{ return comp(x.first, y.first); }
	};
	typedef				Alloc											allocator_type;
	typedef 			value_type&										reference;
	typedef				const value_type&								const_reference;
	typedef 			value_type*										pointer;
	typedef				const value_type*								const_pointer;
	typedef				Node<value_type>								node_type;
	typedef				ft::Iterator<value_type, node_type>				iterator;
	typedef				ft::Const_Iterator<value_type, node_type>		const_iterator;
	typedef				ft::Reverse_Iterator<iterator, node_type>		reverse_iterator;
	typedef				ft::Const_Reverse_Iterator<iterator, node_type>	const_reverse_iterator;
	typedef				std::ptrdiff_t									difference_type;
	typedef				size_t											size_type; 


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
	node_type			*_end_tree;
	node_type			*_begin_tree;
	key_compare			_key_comp;

	void add_node(node_type *newNode);
	node_type *search_by_key(key_type k, node_type *root);
	void delete_node(key_type val, node_type **root);

}; //-------------------end Map Class 


}; //-------------------end Namespace ft

#endif 
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_impl.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:08:08 by ejawe             #+#    #+#             */
/*   Updated: 2021/04/24 18:08:09 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_IMPL_HPP
# define MAP_IMPL_HPP

#include "map_class.hpp"

namespace ft 
{


// *** Constructors ***

// empty
template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::map (const key_compare& comp, const allocator_type& alloc) :
_size(0), _alloc(alloc), _key_comp(comp)
{
	_node = NULL;
	_begin_tree = NULL;
	_begin_tree = new node_type();
	_end_tree = NULL;
	_end_tree = new node_type();

	_begin_tree->left = NULL;
	_begin_tree->right = NULL;
	_begin_tree->parent = NULL;

	_end_tree->left = NULL;
	_end_tree->right = NULL;
	_end_tree->parent = NULL;
}

// range
template <class Key, class T, class Compare, class Alloc> template <class InputIterator>
map<Key, T, Compare, Alloc>::map (typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, 
InputIterator last, const key_compare& comp, const allocator_type& alloc) :
_size(0), _alloc(alloc), _key_comp(comp)
{
	_node = NULL;
	_begin_tree = NULL;
	_begin_tree = new node_type();
	_end_tree = NULL;
	_end_tree = new node_type();

	_begin_tree->left = NULL;
	_begin_tree->right = NULL;
	_begin_tree->parent = NULL;

	_end_tree->left = NULL;
	_end_tree->right = NULL;
	_end_tree->parent = NULL;

	insert(first, last);
}

// copy
template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::map (const map& x) :
_size(0),
_alloc(x._alloc),
_key_comp(x._key_comp)
{
	_node = NULL;
	_begin_tree = NULL;
	_begin_tree = new node_type();
	_end_tree = NULL;
	_end_tree = new node_type();

	_begin_tree->left = NULL;
	_begin_tree->right = NULL;
	_begin_tree->parent = NULL;

	_end_tree->left = NULL;
	_end_tree->right = NULL;
	_end_tree->parent = NULL;
	insert(x.begin(), x.end());	
}

// operator=
template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>& map<Key, T, Compare, Alloc>::operator= (const map& x)
{
	if (_size)
		clear();
	if (x.size())
		this->insert(x.begin(), x.end());
	return (*this);
}

// *** Destructors ***

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::~map()
{
	if (_size == 0)
	{
		delete _end_tree;
		delete _begin_tree;
		return;
	}
	clear();
	delete _end_tree;
	delete _begin_tree;
}



//---------------------------------------------------------------------------------------



// *** Iterator ***

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::begin()
{ return (iterator(first_left(_node)->parent)); }

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator 
map<Key, T, Compare, Alloc>::begin() const
{ return (const_iterator(first_left(_node)->parent)); }

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator 
map<Key, T, Compare, Alloc>::end()
{ return (iterator(_end_tree)); }

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator 
map<Key, T, Compare, Alloc>::end() const
{ return (const_iterator(_end_tree)); }

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::reverse_iterator
map<Key, T, Compare, Alloc>::rbegin()
{ return reverse_iterator(last_right(_node)->parent); }

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_reverse_iterator
map<Key, T, Compare, Alloc>::rbegin() const
{ return const_reverse_iterator(last_right(_node)->parent); }

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::reverse_iterator
map<Key, T, Compare, Alloc>::rend()
{ return reverse_iterator(first_left(_node)); }

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_reverse_iterator
map<Key, T, Compare, Alloc>::rend() const
{ return const_reverse_iterator(first_left(_node)); }


//---------------------------------------------------------------------------------------


// *** Capacity ***

template<class Key, class T, class Compare, class Alloc>
bool map<Key, T, Compare, Alloc>::empty() const
{
    if (_size == 0)
        return true;
    return false;
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::size() const
{ return (_size); }

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::max_size() const
{ return (std::numeric_limits<difference_type>::max() / (sizeof(node_type) / 2 ?: 1)); } 


//---------------------------------------------------------------------------------------


// *** Element acces ***
template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::mapped_type& 
map<Key, T, Compare, Alloc>::operator[] (const key_type& k)
{
	iterator it = find(k);
	if (it != end())
		return ((*it).second);
	return ((insert(value_type(k, mapped_type()))).first->second);
}


//---------------------------------------------------------------------------------------


// *** Modifiers ***

// single element
template<class Key, class T, class Compare, class Alloc>
ft::pair<typename map<Key, T, Compare, Alloc>::iterator,bool> 
map<Key, T, Compare, Alloc>::insert (const value_type& val)
{
	ft::pair<iterator, bool> res;
	
	// count : return 1 si element trouvé
	// fisrt : it element deja existant ou nouvel element
	// second : false si exist dejà, true otherwise
	if (count(val.first) == 1)
		res.second = false;
	else
		res.second = true;
	if (res.second == true)
	{
		value_type newpair(val);
		node_type *newnode = new node_type();
		newnode->left = NULL;
		newnode->right = NULL;
		newnode->parent = NULL;
		newnode->data = newpair;
		add_node(newnode);
	}
	res.first = find(val.first);
	return (res);
}




// with hint
template<class Key, class T, class Compare, class Alloc>	
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::insert (iterator position, const value_type& val)
{
	static_cast<void>(position);
	return (insert(val).first);
}



// range
template<class Key, class T, class Compare, class Alloc> template <class InputIterator>
void
map<Key, T, Compare, Alloc>::insert (typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
{
	while (first != last)
	{
		insert(*first);
		first++;
	}
}


template<class Key, class T, class Compare, class Alloc>
void
map<Key, T, Compare, Alloc>::erase (iterator position)
{ erase((*position).first); }


template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::erase (const key_type& k)
{
	iterator it = find(k);
	if (it == end())
		return 0;
	delete_node(k, &_node);
	return (1);
}



template<class Key, class T, class Compare, class Alloc>
void
map<Key, T, Compare, Alloc>::erase (iterator first, iterator last)
{
	while (first != last)
        erase(first++);
}

template<class Key, class T, class Compare, class Alloc>
void
map<Key, T, Compare, Alloc>::swap (map& x)
{
    ft::swap(_node, x._node);
    ft::swap(_alloc, x._alloc);
    ft::swap(_size, x._size);
    ft::swap(_end_tree, x._end_tree);
	ft::swap(_begin_tree, x._begin_tree);
	ft::swap(_key_comp, x._key_comp);
}

template<class Key, class T, class Compare, class Alloc>
void
map<Key, T, Compare, Alloc>::clear()
{
	while (_size)
		erase(begin());
}

//---------------------------------------------------------------------------------------


// *** Observer ***
template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::key_compare
map<Key, T, Compare, Alloc>::key_comp() const
{ return key_compare(); }

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::value_compare
map<Key, T, Compare, Alloc>::value_comp() const
{ return value_compare(key_compare()); }



//---------------------------------------------------------------------------------------


// *** Operations ***
template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::find (const key_type& k)
{
	if (_node == NULL)
		return _end_tree;
	iterator it = begin();
	iterator ite = end();
	while (it != ite)
	{
		if (!_key_comp((*it).first, k) && !_key_comp(k, (*it).first))
			break ;
		it++;
	}
	return (it);
}


template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::find (const key_type& k) const
{
	if (_node == NULL)
		return _end_tree;
	const_iterator it = begin();
	const_iterator ite = end();
	while (it != ite)
	{
		if (!_key_comp((*it).first, k) && !_key_comp(k, (*it).first))
			break ;
		it++;
	}
	return (it);
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::count (const key_type& k) const
{
	if (_size == 0)
		return 0;
	const_iterator it = begin();
	const_iterator ite = end();
	size_t nb = 0;
	while (it != ite)
	{
		if (!_key_comp((*it).first, k) && !_key_comp(k, (*it).first))
		{
			nb++;
			break ;
		}
		it++;
	}
	return (nb);
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::lower_bound (const key_type& k)
{
	if (_node == NULL)
		return _end_tree;
	iterator it = begin();
	iterator ite = end();
	while (it != ite)
	{
		if (!_key_comp((*it).first, k))
			break ;
		it++;
	}
	return (it);
}


template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::lower_bound (const key_type& k) const
{
	if (_node == NULL)
		return _end_tree;
	const_iterator it = begin();
	const_iterator ite = end();
	while (it != ite)
	{
		if (!_key_comp((*it).first, k))
			break ;
		it++;
	}
	return (it);
}

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::upper_bound (const key_type& k)
{
	if (_node == NULL)
		return _end_tree;
	iterator it = begin();
	iterator ite = end();
	while (it != ite)
	{
		if (_key_comp(k, (*it).first))
			break ;
		it++;
	}
	return (it);
}


template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::upper_bound (const key_type& k) const
{
	if (_node == NULL)
		return _end_tree;
	const_iterator it = begin();
	const_iterator ite = end();
	while (it != ite)
	{
		if (!_key_comp(k, (*it).first))
			break ;
		it++;
	}
	return (it);
}


template<class Key, class T, class Compare, class Alloc>
ft::pair<typename map<Key, T, Compare, Alloc>::const_iterator,typename map<Key, T, Compare, Alloc>::const_iterator>
map<Key, T, Compare, Alloc>::equal_range (const key_type& k) const
{
	pair <const_iterator, const_iterator>	res;
	res.first = lower_bound(k);
	res.second = upper_bound(k);
	return (res);
}


template<class Key, class T, class Compare, class Alloc>
ft::pair<typename map<Key, T, Compare, Alloc>::iterator,typename map<Key, T, Compare, Alloc>::iterator>
map<Key, T, Compare, Alloc>::equal_range (const key_type& k)
{
	pair <iterator, iterator>	res;
	res.first = lower_bound(k);
	res.second = upper_bound(k);
	return (res);
}



//---------------------------------------------------------------------------------------

// *** Relational operators ***

template <class Key, class T, class Compare, class Alloc>
bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{
    if (lhs.size() != rhs.size())
        return false;
	
    typename ft::map<Key,T,Compare,Alloc>::const_iterator	it_lhs = lhs.begin();
	typename ft::map<Key,T,Compare,Alloc>::const_iterator	it_rhs = rhs.begin();
    while (it_lhs != lhs.end())
    {
		
		if (*it_lhs != *it_rhs)
			return false;
        ++it_lhs; 
        ++it_rhs;
    }
    return true;
}

template <class Key, class T, class Compare, class Alloc>
bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{ return (!(lhs == rhs)); }

template <class Key, class T, class Compare, class Alloc>
bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{
    typename ft::map<Key,T,Compare,Alloc>::const_iterator	it_lhs = lhs.begin();
	typename ft::map<Key,T,Compare,Alloc>::const_iterator	it_rhs = rhs.begin();

    while (it_lhs != lhs.end() && it_rhs != rhs.end() && *it_lhs == *it_rhs)
    {
        ++it_lhs; 
        ++it_rhs;
    }
    if (it_lhs == lhs.end())
        return (it_rhs != rhs.end());
    else if (it_rhs == rhs.end())
        return (false);
    return (*it_lhs < *it_rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{
	if (lhs == rhs)
		return (true);
	return (lhs < rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{
	if (lhs == rhs)
		return (false);
	return (!(lhs < rhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{
	if (lhs == rhs)
		return (true);
	return (!(lhs < rhs));
}

template <class Key, class T, class Compare, class Alloc>
void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
{ x.swap(y); };





//---------------------------------------------------------------------------------------


// *** Private ***

template<class Key, class T, class Compare, class Alloc>
void
map<Key, T, Compare, Alloc>::add_node(node_type *newNode) 
{
	if (_size == 0)
	{
		_node = newNode;
		_end_tree->parent = _node;
		_begin_tree->parent = _node;
		_node->right = _end_tree;
		_node->left = _begin_tree;
		_size++;
		return;
	}
	
	node_type **parent = NULL;
	node_type **current = &_node;
	
	while (*current != NULL && *current != _end_tree && *current != _begin_tree)
	{
		parent = current;
		if (_key_comp(newNode->data.first, (*current)->data.first)) // return true if newnode key < currentnode key
			current = &(*current)->left;
		else
			current = &(*current)->right;
	}
	if (_key_comp(newNode->data.first, (*parent)->data.first)) // return true if newnode key < parentnode key
	{
		if ((*parent)->left == _begin_tree)
		{
			(*parent)->left = newNode;
			newNode->parent = _begin_tree->parent;
			_begin_tree->parent = newNode;
			newNode->left = _begin_tree;
		}
		else
		{
			(*parent)->left = newNode;
			newNode->parent = *parent;
		}
	}
	else
	{	
		if ((*parent)->right == _end_tree)
		{
			(*parent)->right = newNode;
			newNode->parent = _end_tree->parent;
			_end_tree->parent = newNode;
			newNode->right = _end_tree;
		}
		else
		{
			(*parent)->right = newNode;
			newNode->parent = *parent;
		}
	}
	_size++;
}


template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::node_type *
map<Key, T, Compare, Alloc>::search_by_key (key_type k, node_type *root)
{
	if (root == NULL)
		return NULL;
	if (root->data.first == k)
		return root;
	if (_key_comp(k, root->data.first))
		return search_by_key(k, root->left);
	if (!_key_comp(k, root->data.first) && root->data.first != k)
		return search_by_key(k, root->right);
	return (NULL);
}

template<class Key, class T, class Compare, class Alloc>
void map<Key, T, Compare, Alloc>::delete_node(key_type val, node_type **root)
{
	node_type *nodeX = search_by_key(val, *root);

	if (nodeX == NULL || nodeX == _end_tree || nodeX == _begin_tree || _size == 0)
		return;
	if (_size == 1)
	{
		delete _node;
		_node = NULL;
		_size--;
		return;
	}
	if (nodeX == _node)
	{
		if (nodeX->left == NULL || nodeX->left == _begin_tree)
		{
			node_type *f = first_left(nodeX->right);
			_node = nodeX->right;
			_begin_tree->parent = f;			
			f->left = _begin_tree;
		}
		delete nodeX;
		nodeX = NULL;
		_size--;
		return ;
	}
	if (is_leaf(nodeX))				// *** No child
	{
		if (nodeX->parent->left == nodeX)
			nodeX->parent->left = NULL;
		else if (nodeX->parent->right == nodeX)
			nodeX->parent->right = NULL;
		delete nodeX;
		_size--;
		return ;
	}
	else if (one_child(nodeX))		// *** One child
	{
		if (nodeX->parent->left == nodeX)
		{
			if (nodeX->left == NULL)
			{
				nodeX->parent->left = nodeX->right;
				nodeX->right->parent = nodeX->parent;
			}
			else if (nodeX->right == NULL)
			{
				nodeX->parent->left = nodeX->left;
				nodeX->left->parent = nodeX->parent;
			}
		}
		else if (nodeX->parent->right == nodeX)
		{
			if (nodeX->left == NULL)
			{
				nodeX->parent->right = nodeX->right;
				nodeX->right->parent = nodeX->parent;
			}
			else if (nodeX->right == NULL)
			{
				nodeX->parent->right = nodeX->left;
				nodeX->left->parent = nodeX->parent;
			}
		}
		delete nodeX;
		_size--;
		return ;
	}
	else							// *** Two child
	{
		node_type *tmp = first_left(nodeX->right);
		nodeX->data = tmp->data;
		delete_node(nodeX->data.first, &nodeX->right);
	}
}
//---------------------------------------------------------------------------------------


}; //-------------------end Namespace ft

#endif
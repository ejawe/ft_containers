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
	_node = new node_type();
	_node->left = NULL;
	_node->right = NULL;
	_node->parent = NULL;
}

// range
template <class Key, class T, class Compare, class Alloc> template <class InputIterator>
map<Key, T, Compare, Alloc>::map (typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, 
InputIterator last, const key_compare& comp, const allocator_type& alloc) :
_size(0), _alloc(alloc), _key_comp(comp)
{
	_node = new node_type();
	_node->left = NULL;
	_node->right = NULL;
	_node->parent = NULL;
	insert(first, last);
}

// copy
template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::map (const map& x) :
_size(0),
_alloc(x._alloc),
_key_comp(x._key_comp)
{
	_node = new node_type();
	_node->left = NULL;
	_node->right = NULL;
	_node->parent = NULL;
	*this = x;	
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
	clear();
}



//---------------------------------------------------------------------------------------



// *** Iterator ***

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::begin()
{ return (iterator(first_left(_node))); }

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator 
map<Key, T, Compare, Alloc>::begin() const
{ return (const_iterator(first_left(_node))); }

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator 
map<Key, T, Compare, Alloc>::end()
{ return (iterator(last_right(_node))); }

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator 
map<Key, T, Compare, Alloc>::end() const
{ return (const_iterator(last_right(_node))); }

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::reverse_iterator
map<Key, T, Compare, Alloc>::rbegin()
{ return reverse_iterator(end() - 1); }

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_reverse_iterator
map<Key, T, Compare, Alloc>::rbegin() const
{ return const_reverse_iterator(end() - 1); }

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::reverse_iterator
map<Key, T, Compare, Alloc>::rend()
{ return reverse_iterator(begin() - 1); }

template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_reverse_iterator
map<Key, T, Compare, Alloc>::rend() const
{ return const_reverse_iterator(begin() - 1); }


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
{
	erase((*position).first);
}


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
	node_type *tmpnode = _node;
	size_type tmpsize = _size;

	_node = x._node;
	x._node = tmpnode;
	_size = x._size;
	x._size = tmpsize;
}

template<class Key, class T, class Compare, class Alloc>
void
map<Key, T, Compare, Alloc>::clear()
{
	erase(begin(), end());
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
	iterator it = begin();
	iterator ite = end();
	while (it != ite)
	{
		if (!_key_comp(k, (*it).first))
			break ;
		it++;
	}
	return (it);
}


template<class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::upper_bound (const key_type& k) const
{
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


// *** Private ***

template<class Key, class T, class Compare, class Alloc>
void	map<Key, T, Compare, Alloc>::add_node(node_type *newNode) 
{
	node_type **parent = &_node;
	node_type **node = 	&_node;
	node_type *ghost = 	last_right(_node);
	bool 				side_left = -1;

	while (*node && *node != ghost) // node become null when it found the new emplacement of newnode
	{
		parent = node;
		side_left = _key_comp(newNode->data.first, (*node)->data.first); // return true if newnode key < currentnode key
		node = (side_left ? &(*node)->left : &(*node)->right); // if side_left = true, node = nodeleft, otherwise, noderigth
	}
	if (*node == NULL) // the new emplacement "node" is found, affectation : node is newnode
	{
		newNode->parent = (*parent);
		*node = newNode;
	}
	else // if (*node == ghost)
	{
		*node = newNode;
		newNode->parent = ghost->parent;
		ghost->parent = last_right(newNode);
		last_right(newNode)->right = ghost;
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

	if (nodeX == NULL)
		return;
	
	if (is_leaf(nodeX))				// *** No child
	{
			
		std::cout << "del_node" << std::endl;
		if (nodeX->parent->left == nodeX)
			nodeX->parent->left = NULL;
		else if (nodeX->parent->right == nodeX)
			nodeX->parent->right = NULL;
		else if (nodeX->parent == NULL) // root
			root = NULL;
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
		else if (nodeX->parent == NULL) // root
		{
			if (nodeX->left == NULL)
				root = &nodeX->right;
			else if(nodeX->right == NULL)
				root = &nodeX->left;
		}
		delete nodeX;
		_size--;
		return ;
	}
	else						// *** Two child
	{
		node_type *tmp = first_left(nodeX->right);
		nodeX->data = tmp->data;
		delete_node(nodeX->data.first, &nodeX->right);
	}
}
//---------------------------------------------------------------------------------------


// *** class value_compare ***
template <class Key, class T, class Compare, class Alloc>
class	map<Key, T, Compare, Alloc>::value_compare 
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

}; //-------------------end Namespace ft

#endif
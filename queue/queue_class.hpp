/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:08:50 by ejawe             #+#    #+#             */
/*   Updated: 2021/04/24 18:08:54 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_CLASS_HPP
# define QUEUE_CLASS_HPP

#include "../list/list_class.hpp"
#include "../list/list_impl.hpp"

namespace ft 
{

template <class T, class Container = list<T> >
class queue 
{

public:

	// ******** Member type ********
	typedef	T				value_type;
	typedef	Container		container_type;
	typedef	size_t			size_type;

	// ******** Member function ********

	explicit queue (const container_type& ctnr = container_type()) : _container(ctnr) { };
	queue(const queue &src) : _container(src._container) { };
	queue &operator=(queue const &rhs) { _container = rhs._container; return *this; };
	~queue() { };

	bool empty() const { return _container.empty(); };
	size_type size() const { return _container.size(); }
	value_type& front() { return _container.front(); }
	const value_type& front() const { return _container.front(); }
	value_type& back() { return _container.back(); }
	const value_type& back() const { return _container.back(); }
	void push (const value_type& val) { _container.push_back(val); }
	void pop() { _container.pop_front(); }


	friend bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs._container == rhs._container; }

	friend bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs._container != rhs._container; }

	friend bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs._container < rhs._container; }

	friend bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs._container <= rhs._container; }

	friend bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs._container > rhs._container; }

	friend bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return lhs._container >= rhs._container; }
	

private:
	container_type _container;

}; //-------------------end Queue Class 

}; //-------------------end Namespace ft


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:11:20 by ejawe             #+#    #+#             */
/*   Updated: 2021/04/24 18:11:40 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <memory>
#include <stdexcept>

namespace ft
{

	template<bool, class T = void>
	struct enable_if {};
	
	template<class T>
	struct enable_if<true, T>{ 
		typedef T type; 
	};

	template<typename T>
	void swap(T &a, T &b)
	{
		T c(a); 
		a = b; 
		b = c;
	}

};

#endif

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <type_traits>
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

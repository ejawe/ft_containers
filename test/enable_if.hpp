#ifndef ENABLE_HPP
# define ENABLE_HPP

#include <iostream>
#include <type_traits>

namespace ft
{

	template<bool, class T = void>
	struct enable_if {};
	
	template<class T>
	struct enable_if<true, T>{ 
		typedef T type; 
	};

}

#endif

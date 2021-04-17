#include <iostream>
#include <map>
#include "map_class.hpp"
#include "map_impl.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main()
{
    std::cout << "***************************************" << std::endl;
    std::cout << "******** test constructor *************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<char,int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	std::map<char,int> second (first.begin(),first.end());

	std::map<char,int> third (second);

	std::map<char,int,classcomp> fourth;                 // class as Compare

	bool(*fn_pt)(char,char) = fncomp;
	std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<char,int> first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d']=70;

	// ft::map<char,int> second (first.begin(),first.end());

	// ft::map<char,int> third (second);

	// ft::map<char,int,classcomp> fourth;                 // class as Compare

	// bool(*fn_pt)(char,char) = fncomp;
	// ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	}







	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:07:51 by ejawe             #+#    #+#             */
/*   Updated: 2021/04/27 17:34:29 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <queue>
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
	std::cout << "Constructors work !" << std::endl;
	}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{
	ft::map<char,int> first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	ft::map<char,int> second (first.begin(),first.end());

	ft::map<char,int> third (second);

	ft::map<char,int,classcomp> fourth;                 // class as Compare

	bool(*fn_pt)(char,char) = fncomp;
	ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	std::cout << "Constructors work !" << std::endl;
	}

    std::cout << "***************************************" << std::endl;
    std::cout << "********** test operator= *************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<char,int> first;
	std::map<char,int> second;

	first['x']=8;
	first['y']=16;
	first['z']=32;

	second=first;                // second now contains 3 ints
	first=std::map<char,int>();  // and first is now empty

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<char,int> first;
	ft::map<char,int> second;

	first['x']=8;
	first['y']=16;
	first['z']=32;

	second=first;                // second now contains 3 ints
	first=ft::map<char,int>();  // and first is now empty

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';
	}

    std::cout << "***************************************" << std::endl;
    std::cout << "********** test begin & end ***********" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';}

    std::cout << "***************************************" << std::endl;
    std::cout << "********* test rbegin & rend **********" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	std::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	ft::map<char,int>::reverse_iterator rit;

	// rit=mymap.rend();
	// std::cout << rit->first << " => " << rit->second << '\n';

	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';
	}

    std::cout << "***************************************" << std::endl;
    std::cout << "************** test empty *************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;

	{std::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}}

    std::cout << "***************************************" << std::endl;
    std::cout << "************** test size **************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;

	{std::map<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';}

    std::cout << "***************************************" << std::endl;
    std::cout << "************ test max_size ************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{int i;
	std::map<int,int> mymap;

	if (mymap.max_size()>1000)
	{
		for (i=0; i<1000; i++) mymap[i]=0;
		std::cout << "The map contains 1000 elements.\n";
	}
	else std::cout << "The map could not hold 1000 elements.\n";}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{int i;
	ft::map<int,int> mymap;

	if (mymap.max_size()>1000)
	{
		for (i=0; i<1000; i++) mymap[i]=0;
		std::cout << "The map contains 1000 elements.\n";
	}
	else std::cout << "The map could not hold 1000 elements.\n";}


    std::cout << "***************************************" << std::endl;
    std::cout << "*********** test operator[] ***********" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<char,std::string> mymap;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<char,std::string> mymap;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";}


    std::cout << "***************************************" << std::endl;
    std::cout << "************** test insert ************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('z',200) );

	std::pair<std::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	std::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	std::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';}


	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( ft::pair<char,int>('a',100) );
	mymap.insert ( ft::pair<char,int>('z',200) );

	ft::pair<ft::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( ft::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	ft::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	ft::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	}

    std::cout << "***************************************" << std::endl;
    std::cout << "************** test erase *************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<char,int> mymap;
	std::map<char,int>::iterator it;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';}


	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';}


    std::cout << "***************************************" << std::endl;
    std::cout << "************** test swap **************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';}

    std::cout << "***************************************" << std::endl;
    std::cout << "************** test clear *************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap contains:\n";
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;

	std::cout << "mymap contains:\n";
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	std::cout << "--------------\n";
	mymap['b']=2202;

	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	}

    std::cout << "***************************************" << std::endl;
    std::cout << "************ test key_comp ************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<char,int> mymap;

	std::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	std::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<char,int> mymap;

	ft::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	ft::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';}

    std::cout << "***************************************" << std::endl;
    std::cout << "*********** test value_comp ***********" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	std::cout << "mymap contains:\n";

	std::pair<char,int> highest = *mymap.rbegin();          // last element

	std::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	std::cout << "mymap contains:\n";

	ft::pair<char,int> highest = *mymap.rbegin();          // last element

	ft::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );}


    std::cout << "***************************************" << std::endl;
    std::cout << "************** test find **************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<char,int> mymap;
	std::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';}

    std::cout << "***************************************" << std::endl;
    std::cout << "************** test count *************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
		std::cout << " is an element of mymap.\n";
		else 
		std::cout << " is not an element of mymap.\n";
	}}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
		std::cout << " is an element of mymap.\n";
		else 
		std::cout << " is not an element of mymap.\n";
	}}

    std::cout << "***************************************" << std::endl;
    std::cout << "*** test lower_bound & upper_bound*****" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<char,int> mymap;
	std::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<char,int> mymap;
	ft::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	// std::cout << "itup = " << (*itup).first << std::endl;

	mymap.erase(itlow,itup);        // erases [itlow,itup)
	// std::cout << "fin erase--------" << std::endl;
	// print content:
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	}

    std::cout << "***************************************" << std::endl;
    std::cout << "*********** test equal_range **********" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';}

    std::cout << "***************************************" << std::endl;
    std::cout << "****** test relational operators ******" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<char,int> foo,bar;
	foo['a']=100;
	foo['b']=200;
	bar['a']=10;
	bar['z']=1000;

	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;

	{ft::map<char,int> foo,bar;
	foo['a']=100;
	foo['b']=200;
	bar['a']=10;
	bar['z']=1000;

	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";}

    std::cout << "***************************************" << std::endl;
    std::cout << "************* test swap ***************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	swap(foo,bar);

	std::cout << "foo contains:\n";
	for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;

	{ft::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	swap(foo,bar);

	std::cout << "foo contains:\n";
	for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';}


    std::cout << "***************************************" << std::endl;
    std::cout << "************* test other ***************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<int,int> mymap;

	mymap[10] = 100;
	mymap[5] = 200;
	mymap[15] = 300;
	mymap[7] = 400;
	mymap[2] = 800;
	mymap[9] = 10;
	mymap[31] = 1;

	// show content:
	for (std::map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<int,int> mymap;

	mymap[10] = 100;
	mymap[5] = 200;
	mymap[15] = 300;
	mymap[7] = 400;
	mymap[2] = 800;
	mymap[9] = 10;
	mymap[31] = 1;

	// show content:
	for (ft::map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';}

	std::cout << "***************************************" << std::endl;
    std::cout << "************* test iterators **********" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::map<int,int> mymap;

	mymap[10] = 100;
	mymap[5] = 200;
	mymap[15] = 300;
	mymap[7] = 400;;

	std::cout << "mymap backwards:";
	for (std::map<int,int>::reverse_iterator rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << ' ' << rit->second;

	std::map<int,int>::const_iterator it3 = mymap.begin();
	//  Constructor : Const_Iterator(Const_Iterator const &src)
	std::map<int,int>::const_iterator it = it3;
	it++;

	std::cout << "*1*"<<'\n';
	//Constructor : Const_Reverse_Iterator(Reverse_Iterator<iterator> const &src)
	std::map<int,int>::const_reverse_iterator rit3 = mymap.rbegin();
	std::cout << "*1*"<<'\n';
	// for (; rit3!= myvector.rend(); ++rit3)
	// 	*rit3 = ++i;

	std::cout << "*3*"<<'\n';
	//Constructor : Const_Reverse_Iterator(Const_Reverse_Iterator const &src)
	std::map<int,int>::const_reverse_iterator rit4 = rit3;
	std::cout << "*3*"<<'\n';
	}

	std::cout << '\n';
	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::map<int,int> mymap;

	mymap[10] = 100;
	mymap[5] = 200;
	mymap[15] = 300;
	mymap[7] = 400;;

	std::cout << "mymap backwards:";
	for (ft::map<int,int>::reverse_iterator rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << ' ' << rit->second;

	ft::map<int,int>::const_iterator it3 = mymap.begin();
	//  Constructor : Const_Iterator(Const_Iterator const &src)
	ft::map<int,int>::const_iterator it = it3;
	it++;

	std::cout << "*1*"<<'\n';
	//Constructor : Const_Reverse_Iterator(Reverse_Iterator<iterator> const &src)
	ft::map<int,int>::const_reverse_iterator rit3 = mymap.rbegin();
	std::cout << "*1*"<<'\n';
	// for (; rit3!= myvector.rend(); ++rit3)
	// 	*rit3 = ++i;

	std::cout << "*3*"<<'\n';
	//Constructor : Const_Reverse_Iterator(Const_Reverse_Iterator const &src)
	ft::map<int,int>::const_reverse_iterator rit4 = rit3;
	std::cout << "*3*"<<'\n';
	}
	return 0;
}
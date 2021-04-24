/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:08:19 by ejawe             #+#    #+#             */
/*   Updated: 2021/04/24 18:08:21 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <queue>
#include "../list/list_class.hpp"
#include "../list/list_impl.hpp"
#include "queue_class.hpp"


int		main(void)
{
	std::cout << "***************************************" << std::endl;
    std::cout << "******** test constructors ************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	// std::cout << "std :" << std::endl;
	{std::deque<int> mydeck (3,100);        // deque with 3 elements
	std::list<int> mylist (2,200);         // list with 2 elements

	std::queue<int> first;                 // empty queue
	std::queue<int> second (mydeck);       // queue initialized to copy of deque

	std::queue<int,std::list<int> > third; // empty queue with list as underlying container
	std::queue<int,std::list<int> > fourth (mylist);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';}

    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;
	{ft::list<int> mydeck (3,100);        // deque with 3 elements
	ft::list<int> mylist (2,200);         // list with 2 elements

	ft::queue<int> first;                 // empty queue
	ft::queue<int> second (mydeck);       // queue initialized to copy of deque

	ft::queue<int,ft::list<int> > third; // empty queue with list as underlying container
	ft::queue<int,ft::list<int> > fourth (mylist);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';}

	std::cout << "***************************************" << std::endl;
    std::cout << "************* test empty **************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::queue<int> myqueue;
	int sum (0);

	for (int i=1;i<=10;i++) myqueue.push(i);

	while (!myqueue.empty())
	{
		sum += myqueue.front();
		myqueue.pop();
	}

	std::cout << "total: " << sum << '\n';}
    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;
	{ft::queue<int> myqueue;
	int sum (0);

	for (int i=1;i<=10;i++) myqueue.push(i);

	while (!myqueue.empty())
	{
		sum += myqueue.front();
		myqueue.pop();
	}

	std::cout << "total: " << sum << '\n';}

	std::cout << "***************************************" << std::endl;
    std::cout << "************* test size ***************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::queue<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';}
    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;
	{ft::queue<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';}

	std::cout << "***************************************" << std::endl;
    std::cout << "************* test front **************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::queue<int> myqueue;

	myqueue.push(77);
	myqueue.push(16);

	myqueue.front() -= myqueue.back();    // 77-16=61

	std::cout << "myqueue.front() is now " << myqueue.front() << '\n';}
    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;
	{ft::queue<int> myqueue;

	myqueue.push(77);
	myqueue.push(16);

	myqueue.front() -= myqueue.back();    // 77-16=61

	std::cout << "myqueue.front() is now " << myqueue.front() << '\n';}

	std::cout << "***************************************" << std::endl;
    std::cout << "************* test back **************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::queue<int> myqueue;

	myqueue.push(12);
	myqueue.push(75);   // this is now the back

	myqueue.back() -= myqueue.front();

	std::cout << "myqueue.back() is now " << myqueue.back() << '\n';}
    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;
	{ft::queue<int> myqueue;

	myqueue.push(12);
	myqueue.push(75);   // this is now the back

	myqueue.back() -= myqueue.front();

	std::cout << "myqueue.back() is now " << myqueue.back() << '\n';}

	std::cout << "***************************************" << std::endl;
    std::cout << "*********** test push & pop ***********" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::queue<int> myqueue;

	for (int i=0; i<5; i++) myqueue.push(i);

	std::cout << "myqueue contains: ";
	while (!myqueue.empty())
	{
		std::cout << ' ' << myqueue.front();
		myqueue.pop();
	}
	std::cout << '\n';}
    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;
	{ft::queue<int> myqueue;

	for (int i=0; i<5; i++) myqueue.push(i);

	std::cout << "myqueue contains: ";
	while (!myqueue.empty())
	{
		std::cout << ' ' << myqueue.front();
		myqueue.pop();
	}
	std::cout << '\n';}

	std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "****** test relational operators ******" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;

	{std::queue<int> a;

	for (int i=1; i<10; ++i) a.push(i);

	std::queue<int> b = a;
	std::queue<int> c(a);

	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;

	{ft::queue<int> a;

	for (int i=1; i<10; ++i) a.push(i);

	ft::queue<int> b = a;
	ft::queue<int> c(a);

	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";}

	std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "********* test swap non member ********" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::list<int> foo (3,100);   // three ints with a value of 100
	std::list<int> bar (5,200);   // five ints with a value of 200

	std::swap(foo,bar);

	std::cout << "foo contains:";
	for (std::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (std::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::list<int> foo (3,100);   // three ints with a value of 100
	ft::list<int> bar (5,200);   // five ints with a value of 200

	ft::swap(foo,bar);

	std::cout << "foo contains:";
	for (ft::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (ft::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';}
	return 0;
}
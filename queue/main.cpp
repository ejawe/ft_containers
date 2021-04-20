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
	// std::cout << "std :" << std::endl;
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


	return 0;
}
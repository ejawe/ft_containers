#include <list>
#include "list_class.hpp"
#include "list_impl.hpp"
#include <cmath>
#include <vector>
#include <iostream>

int main ()
{

    std::cout << "***************************************" << std::endl;
    std::cout << "******** test constructor *************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	// constructors used in the same order as described above:
	{std::list<int> first;                                // empty list of ints
	std::list<int> second (4,100);                       // four ints with value 100
	std::list<int> third (second.begin(),second.end());  // iterating through second
	std::list<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are: ";
	for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
		std::cout << *it << ' ';

	std::cout << '\n';}
	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	// constructors used in the same order as described above:
	{
	ft::list<int> first;                                // empty list of ints
	ft::list<int> second (4,100);                       // four ints with value 100
	ft::list<int> third (second.begin(),second.end());  // iterating through second
	ft::list<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	ft::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are: ";
	for (ft::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
		std::cout << *it << ' ';
		std::cout << '\n';
	}

	std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "*********** test operator= ************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::list<int> first (3);      // list of 3 zero-initialized ints
	std::list<int> second (5);     // list of 5 zero-initialized ints

	second = first;
	first = std::list<int>();

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::list<int> first (3);      // list of 3 zero-initialized ints
	ft::list<int> second (5);     // list of 5 zero-initialized ints

	second = first;
	first = ft::list<int>();

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';}

	std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "********** test begin & end ***********" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{int myints[] = {75,23,65,42,13};
	std::list<int> mylist (myints,myints+5);

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';}
	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{int myints[] = {75,23,65,42,13};
	ft::list<int> mylist (myints,myints+5);

	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it=mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';}

	std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "********** test rbegin & rend *********" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::list<int> mylist;
	for (int i=1; i<=5; ++i) mylist.push_back(i);

	std::cout << "mylist backwards:";
	for (std::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
		std::cout << ' ' << *rit;}

	std::cout << '\n';
	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::list<int> mylist;
	for (int i=1; i<=5; ++i) mylist.push_back(i);

	std::cout << "mylist backwards:";
	for (ft::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
		std::cout << ' ' << *rit;}

	std::cout << '\n';

	std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************** test empty *************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::list<int> mylist;
	int sum (0);

	for (int i=1;i<=10;++i) mylist.push_back(i);

	while (!mylist.empty())
	{
		sum += mylist.front();
		mylist.pop_front();
	}

	std::cout << "total: " << sum << '\n';}
	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::list<int> mylist;
	int sum (0);

	for (int i=1;i<=10;++i) mylist.push_back(i);

	while (!mylist.empty())
	{
		sum += mylist.front();
		mylist.pop_front();
	}

	std::cout << "total: " << sum << '\n';}

	std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "*************** test size *************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::list<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.begin(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';}


	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::list<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.begin(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';}



	std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************* test max_size ***********" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
  	{std::list<int> mylist;
	for (int i=0; i<100; i++)
        mylist.push_back(i);
	std::cout << "size: " << mylist.size() << "\n";
	std::cout << "max_size: " << mylist.max_size() << "\n";}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
  	{ft::list<int> mylist;
	for (int i=0; i<100; i++)
        mylist.push_back(i);
	std::cout << "size: " << mylist.size() << "\n";
	std::cout << "max_size: " << mylist.max_size() << "\n";}

	std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "*************** test front ************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::list<int> mylist;

	mylist.push_back(77);
	mylist.push_back(22);

	// now front equals 77, and back 22

	mylist.front() -= mylist.back();

	std::cout << "mylist.front() is now " << mylist.front() << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::list<int> mylist;

	mylist.push_back(77);
	mylist.push_back(22);

	// now front equals 77, and back 22

	mylist.front() -= mylist.back();

	std::cout << "mylist.front() is now " << mylist.front() << '\n';}

	std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "*************** test back *************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::list<int> mylist;

	mylist.push_back(10);

	while (mylist.back() != 0)
	{
		mylist.push_back ( mylist.back() -1 );
	}

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::list<int> mylist;

	mylist.push_back(10);

	while (mylist.back() != 0)
	{
		mylist.push_back ( mylist.back() -1 );
	}

	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';}
	std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************** test assign ************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::list<int> first;
	std::list<int> second;

	first.assign (7,100);                      // 7 ints with value 100

	second.assign (first.begin(),first.end()); // a copy of first

	int myints[]={1776,7,4};
	first.assign (myints,myints+3);            // assigning from array

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';}
	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::list<int> first;
	ft::list<int> second;

	first.assign (7,100);                      // 7 ints with value 100

	second.assign (first.begin(),first.end()); // a copy of first

	int myints[]={1776,7,4};
	first.assign (myints,myints+3);            // assigning from array

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';}

	std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "*********** test push_front ***********" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::list<int> mylist (2,100);         // two ints with a value of 100
	mylist.push_front (200);
	mylist.push_front (300);

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::list<int> mylist (2,100);         // two ints with a value of 100
	mylist.push_front (200);
	mylist.push_front (300);

	std::cout << "mylist contains:";
	for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';}
	std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************ test pop_front ***********" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::list<int> mylist;
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);

	std::cout << "Popping out the elements in mylist:";
	while (!mylist.empty())
	{
		std::cout << ' ' << mylist.front();
		mylist.pop_front();
	}

	std::cout << "\nFinal size of mylist is " << mylist.size() << '\n';}
	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::list<int> mylist;
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);

	std::cout << "Popping out the elements in mylist:";
	while (!mylist.empty())
	{
		std::cout << ' ' << mylist.front();
		mylist.pop_front();
	}

	std::cout << "\nFinal size of mylist is " << mylist.size() << '\n';}

	std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************ test pop_back ************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{  std::list<int> mylist;
	int sum (0);
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);

	while (!mylist.empty())
	{
		sum+=mylist.back();
		mylist.pop_back();
	}

	std::cout << "The elements of mylist summed " << sum << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{  ft::list<int> mylist;
	int sum (0);
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);

	while (!mylist.empty())
	{
		sum+=mylist.back();
		mylist.pop_back();
	}
	std::cout << "The elements of mylist summed " << sum << '\n';}

	std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************* test insert *************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::list<int> mylist;
	std::list<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

	it = mylist.begin();
	++it;       // it points now to number 2           ^

	mylist.insert (it,10);                        // 1 10 2 3 4 5

	// "it" still points to number 2                      ^
	mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

	--it;       // it points now to the second 20            ^

	std::vector<int> myvector (2,30);
	mylist.insert (it,myvector.begin(),myvector.end());
													// 1 10 20 30 30 20 2 3 4 5
													//               ^
	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';}

	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::list<int> mylist;
	ft::list<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

	it = mylist.begin();
	++it;       // it points now to number 2           ^

	mylist.insert (it,10);                        // 1 10 2 3 4 5

	// "it" still points to number 2                      ^
	mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

	--it;       // it points now to the second 20            ^

	std::vector<int> myvector (2,30);
	mylist.insert (it,myvector.begin(),myvector.end());
													// 1 10 20 30 30 20 2 3 4 5
													//               ^
	std::cout << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';}


	std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************* test erase **************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
	std::cout << "std :" << std::endl;
	{std::list<int> mylist;
	std::list<int>::iterator it1,it2;

	// set some values:
	for (int i=1; i<10; ++i) mylist.push_back(i*10);

								// 10 20 30 40 50 60 70 80 90
	it1 = it2 = mylist.begin(); // ^^
	advance (it2,6);            // ^                 ^
	++it1;                      //    ^              ^

	it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
								//    ^           ^

	it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
								//    ^           ^

	++it1;                      //       ^        ^
	--it2;                      //       ^     ^

	mylist.erase (it1,it2);     // 10 30 60 80 90
								//        ^

	std::cout << "mylist contains:";
	for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';}
	std::cout << "-----------------------------" << std::endl;
	std::cout << "ft :" << std::endl;
	{ft::list<int> mylist;
	ft::list<int>::iterator it1,it2;

	// set some values:
	for (int i=1; i<10; ++i) mylist.push_back(i*10);

								// 10 20 30 40 50 60 70 80 90
	it1 = it2 = mylist.begin(); // ^^
	// std::advance (it2,6);            // ^                 ^
	it2++;
	it2++;
	it2++;
	it2++;
	it2++;

	++it1;                      //    ^              ^

	it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
								//    ^           ^

	it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
								//    ^           ^

	++it1;                      //       ^        ^
	--it2;                      //       ^     ^

	mylist.erase (it1,it2);     // 10 30 60 80 90
								//        ^

	std::cout << "mylist contains:";
	for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';}






	return 0;
}






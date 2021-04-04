#include <iostream>
#include "vector_class.hpp"
#include "vector_impl.hpp"
#include <vector>

int main()
{
    std::cout << "***************************************" << std::endl;
    std::cout << "*********** test begin ****************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
    std::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);

    std::cout << "std myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "-----------------------------" << std::endl;

    ft::vector<int> myvector2;
    for (int i=1; i<=5; i++) myvector2.push_back(i);

    std::cout << "ft myvector2 contains:";
    for (ft::vector<int>::iterator it = myvector2.begin() ; it != myvector2.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "*********** test end ******************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;

    std::vector<int> myvector3;
    for (int i=1; i<=5; i++) myvector3.push_back(i);

    std::cout << "std myvector3 contains:";
    for (std::vector<int>::iterator it = myvector3.begin() ; it != myvector3.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "-----------------------------" << std::endl;

    ft::vector<int> myvector4;
    for (int i=1; i<=5; i++) myvector4.push_back(i);

    std::cout << "ft  myvector4 contains:";
    for (ft::vector<int>::iterator it = myvector4.begin() ; it != myvector4.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';


    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "******** test rbegin rend *************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;

    std::vector<int> myvector5 (5);  // 5 default-constructed ints

    int i=0;

    std::vector<int>::reverse_iterator rit = myvector5.rbegin();
    for (; rit!= myvector5.rend(); ++rit)
        *rit = ++i;

    std::cout << "std myvector5 contains:";
    for (std::vector<int>::iterator it = myvector5.begin(); it != myvector5.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "-----------------------------" << std::endl;
    ft::vector<int> myvector6 (5);  // 5 default-constructed ints

    i=0;

    ft::vector<int>::reverse_iterator rit2 = myvector6.rbegin();
    for (; rit2!= myvector6.rend(); ++rit2)
        *rit2 = ++i;

    std::cout << "ft  myvector6 contains:";
    for (ft::vector<int>::iterator it = myvector6.begin(); it != myvector6.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';


    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************ test size ****************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;

    std::cout << "std :" << std::endl;
    std::vector<int> myints;
    std::cout << "0. size: " << myints.size() << '\n';

    for (int i=0; i<10; i++) myints.push_back(i);
    std::cout << "1. size: " << myints.size() << '\n';

    myints.insert (myints.end(),10,100);
    std::cout << "2. size: " << myints.size() << '\n';

    myints.pop_back();
    std::cout << "3. size: " << myints.size() << '\n';

    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;
    ft::vector<int> myints2;
    std::cout << "0. size: " << myints2.size() << '\n';

    for (int i=0; i<10; i++) myints2.push_back(i);
    std::cout << "1. size: " << myints2.size() << '\n';

    myints2.insert (myints2.end(),10,100);
    std::cout << "2. size: " << myints2.size() << '\n';

    myints2.pop_back();
    std::cout << "3. size: " << myints2.size() << '\n'; 

    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "****** test max_size & capacity *******" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;

    std::cout << "std :" << std::endl;
    std::vector<int> nwvec;

    // set some content in the vector:
    for (int i=0; i<100; i++)
        nwvec.push_back(i);

    std::cout << "size: " << nwvec.size() << "\n";
    std::cout << "capacity: " << nwvec.capacity() << "\n";
    std::cout << "max_size: " << nwvec.max_size() << "\n";


    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;

    ft::vector<int> nwvec2;

    // set some content in the vector:
    for (int i=0; i<100; i++) nwvec2.push_back(i);

    std::cout << "size: " << nwvec2.size() << "\n";
    std::cout << "capacity: " << nwvec2.capacity() << "\n";
    std::cout << "max_size: " << nwvec2.max_size() << "\n";

    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************* test resize *************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;


    std::vector<int> nwvec3;

    // set some initial content:
    for (int i=1;i<10;i++) nwvec3.push_back(i);

    nwvec3.resize(5);
    nwvec3.resize(8,100);
    nwvec3.resize(12);

    std::cout << "std nwvec3 contains:";
    for (size_t i=0;i<nwvec3.size();i++)
        std::cout << ' ' << nwvec3[i];
    std::cout << '\n';

    std::cout << "-----------------------------" << std::endl;

    ft::vector<int> nwvec4;

    // set some initial content:
    for (int i=1;i<10;i++) nwvec4.push_back(i);

    nwvec4.resize(5);
    nwvec4.resize(8,100);
    nwvec4.resize(12);

    std::cout << "ft  nwvec4 contains:";
    for (size_t i=0;i<nwvec4.size();i++)
        std::cout << ' ' << nwvec4[i];
    std::cout << '\n';

    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************* test empty* *************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;

    std::cout << "std :" << std::endl;
    std::vector<int> nwvec5;
    int sum (0);

    for (int i=1;i<=10;i++) nwvec5.push_back(i);

    while (!nwvec5.empty())
    {
        sum += nwvec5.back();
        nwvec5.pop_back();
    }

    std::cout << "total: " << sum << '\n';


    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;
    ft::vector<int> nwvec6;
    sum = 0;

    for (int i=1;i<=10;i++) nwvec6.push_back(i);

    while (!nwvec6.empty())
    {
        sum += nwvec6.back();
        nwvec6.pop_back();
    }

    std::cout << "total: " << sum << '\n';


    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************* test reserve ************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
    
    std::cout << "std :" << std::endl;
    std::vector<int>::size_type sz;

    std::vector<int> foo;
    sz = foo.capacity();
    std::cout << "making foo grow:\n";
    for (int i=0; i<100; ++i) {
        foo.push_back(i);
        if (sz!=foo.capacity()) {
        sz = foo.capacity();
        std::cout << "capacity changed: " << sz << '\n';
        }
    }

    std::vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100);   // this is the only difference with foo above
    std::cout << "making bar grow:\n";
    for (int i=0; i<100; ++i) {
        bar.push_back(i);
        if (sz!=bar.capacity()) {
        sz = bar.capacity();
        std::cout << "capacity changed: " << sz << '\n';
        }
    }

    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;

    ft::vector<int>::size_type sz2;

    ft::vector<int> foo2;
    sz2 = foo2.capacity();
    std::cout << "making foo2 grow:\n";
    for (int i=0; i<100; ++i) {
        foo2.push_back(i);
        if (sz2!=foo2.capacity()) {
        sz2 = foo2.capacity();
        std::cout << "capacity changed: " << sz2 << '\n';
        }
    }

    ft::vector<int> bar2;
    sz2 = bar2.capacity();
    bar2.reserve(100);   // this is the only difference with foo above
    std::cout << "making bar2 grow:\n";
    for (int i=0; i<100; ++i) {
        bar2.push_back(i);
        if (sz2!=bar2.capacity()) {
        sz2 = bar2.capacity();
        std::cout << "capacity changed: " << sz2 << '\n';
        }
    }

    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************ test operator[] **********" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
    
    std::cout << "std :" << std::endl;
    std::vector<int> vec1 (10);   // 10 zero-initialized elements

    std::vector<int>::size_type sz4 = vec1.size();

    // assign some values:
    for (unsigned i=0; i<sz4; i++) vec1[i]=i;

    // reverse vector using operator[]:
    for (unsigned i=0; i<sz4/2; i++)
    {
        int temp;
        temp = vec1[sz4-1-i];
        vec1[sz4-1-i]=vec1[i];
        vec1[i]=temp;
    }

    std::cout << "vec1 contains:";
    for (unsigned i=0; i<sz4; i++)
        std::cout << ' ' << vec1[i];
    std::cout << '\n';


    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;

    ft::vector<int> vec2 (10);   // 10 zero-initialized elements

    ft::vector<int>::size_type sz3 = vec2.size();

    // assign some values:
    for (unsigned i=0; i<sz3; i++) vec2[i]=i;

    // reverse vector using operator[]:
    for (unsigned i=0; i<sz3/2; i++)
    {
        int temp;
        temp = vec2[sz3-1-i];
        vec2[sz3-1-i]=vec2[i];
        vec2[i]=temp;
    }

    std::cout << "vec2 contains:";
    for (unsigned i=0; i<sz3; i++)
        std::cout << ' ' << vec2[i];
    std::cout << '\n';


    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "*************** test at ***************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
    
    std::cout << "std :" << std::endl;
    std::vector<int> vec3 (10);   // 10 zero-initialized ints

    // assign some values:
    for (unsigned i=0; i<vec3.size(); i++)
        vec3.at(i)=i;

    std::cout << "vec3 contains:";
    for (unsigned i=0; i<vec3.size(); i++)
        std::cout << ' ' << vec3.at(i);
    std::cout << '\n';

    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;

    std::cout << "std :" << std::endl;
    std::vector<int> vec4 (10);   // 10 zero-initialized ints

    // assign some values:
    for (unsigned i=0; i<vec4.size(); i++)
        vec4.at(i)=i;

    std::cout << "vec4 contains:";
    for (unsigned i=0; i<vec4.size(); i++)
        std::cout << ' ' << vec4.at(i);
    std::cout << '\n';


    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "********** test front & back **********" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
    
    std::cout << "std :" << std::endl;
    std::vector<int> vec5;

    vec5.push_back(78);
    vec5.push_back(16);

    // now front equals 78, and back 16

    vec5.front() -= vec5.back();

    std::cout << "vec5.front() is now " << vec5.front() << '\n';

    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;

    std::vector<int> vec6;

    vec6.push_back(78);
    vec6.push_back(16);

    // now front equals 78, and back 16

    vec6.front() -= vec6.back();

    std::cout << "vec6.front() is now " << vec6.front() << '\n';

    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************* test assign *************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;
    
    std::cout << "std :" << std::endl;
    std::vector<int> first;
    std::vector<int> second;

    first.assign (7,100);             // 7 ints with a value of 100

    std::vector<int>::iterator it;
    it=first.begin()+1;

    second.assign (it,first.end()-1); // the 5 central values of first

    std::cout << "Size of first: " << int (first.size()) << '\n';
    std::cout << "Size of second: " << int (second.size()) << '\n';


    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;


    ft::vector<int> first1;
    ft::vector<int> second2;

    first1.assign (7,100);             // 7 ints with a value of 100

    ft::vector<int>::iterator it2;
    it2=first1.begin()+1;

    second2.assign (it2,first1.end()-1); // the 5 central values of first

    std::cout << "Size of first: " << int (first1.size()) << '\n';
    std::cout << "Size of second: " << int (second2.size()) << '\n';

    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************ test push_back ***********" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;

     std::cout << "std :" << std::endl;
    std::vector<int> myvector8;

    myvector8.push_back(78);
    myvector8.push_back(16);

    std::cout << "myvector8 stores " << myvector8.size() << " numbers.\n";

    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;
    std::vector<int> myvector9;

    myvector9.push_back(78);
    myvector9.push_back(16);

    std::cout << "myvector9 stores " << myvector9.size() << " numbers.\n";

    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************ test pop_back ************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;

     std::cout << "std :" << std::endl;
    myvector.clear();
    sum = 0;
    myvector.push_back (100);
    myvector.push_back (200);
    myvector.push_back (300);

    while (!myvector.empty())
    {
        sum+=myvector.back();
        myvector.pop_back();
    }

    std::cout << "The elements of myvector add up to " << sum << '\n';

    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;

    myvector2.clear();
    sum = 0;
    myvector2.push_back (100);
    myvector2.push_back (200);
    myvector2.push_back (300);

    while (!myvector2.empty())
    {
        sum+=myvector2.back();
        myvector2.pop_back();
    }

    std::cout << "The elements of myvector2 add up to " << sum << '\n';

    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************* test insert *************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;

    std::cout << "std :" << std::endl;

    std::vector<int> nvec (3,100);
    std::vector<int>::iterator it7;

    it7 = nvec.begin();
    it7 = nvec.insert ( it7 , 200 );

    nvec.insert (it7,2,300);

    // "it7" no longer valid, get a new one:
    it7 = nvec.begin();

    std::vector<int> anothervector (2,400);
    nvec.insert (it7+2,anothervector.begin(),anothervector.end());

    int myarray [] = { 501,502,503 };
    nvec.insert (nvec.begin(), myarray, myarray+3);

    std::cout << "nvec contains:";
    for (it7=nvec.begin(); it7<nvec.end(); it7++)
        std::cout << ' ' << *it7;
    std::cout << '\n';


    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;

    ft::vector<int> nvec1 (3,100);
    ft::vector<int>::iterator it6;

    it6 = nvec1.begin();
    it6 = nvec1.insert( it6 , 200 );

    nvec1.insert (it6,2,300);

    // "it6" no longer valid, get a new one:
    it6 = nvec1.begin();

    ft::vector<int> anothervector1 (2,400);
    nvec1.insert (it6+2,anothervector1.begin(),anothervector1.end());

    int myarray1 [] = { 501,502,503 };
    nvec1.insert (nvec1.begin(), myarray1, myarray1+3);

    std::cout << "nvec contains:";
    for (it6=nvec1.begin(); it6<nvec1.end(); it6++)
        std::cout << ' ' << *it6;
    std::cout << '\n';

    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************* test erase **************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;

    std::cout << "std :" << std::endl;
    std::vector<int> nvec2;

    // set some values (from 1 to 10)
    for (int i=1; i<=10; i++) nvec2.push_back(i);

    // erase the 6th element
    nvec2.erase (nvec2.begin()+5);

    // erase the first 3 elements:
    nvec2.erase (nvec2.begin(),nvec2.begin()+3);

    std::cout << "nvec2 contains:";
    for (unsigned i=0; i<nvec2.size(); ++i)
        std::cout << ' ' << nvec2[i];
    std::cout << '\n';

    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;

    ft::vector<int> nvec3;

    // set some values (from 1 to 10)
    for (int i=1; i<=10; i++) nvec3.push_back(i);

    // erase the 6th element
    nvec3.erase (nvec3.begin()+5);

    // erase the first 3 elements:
    nvec3.erase (nvec3.begin(),nvec3.begin()+3);

    std::cout << "nvec3 contains:";
    for (unsigned i=0; i<nvec3.size(); ++i)
        std::cout << ' ' << nvec3[i];
    std::cout << '\n';

    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************* test swap ***************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;

    std::cout << "std :" << std::endl;
    std::vector<int> foo3 (3,100);   // three ints with a value of 100
    std::vector<int> bar3 (5,200);   // five ints with a value of 200

    foo3.swap(bar3);

    std::cout << "foo contains:";
    for (unsigned i=0; i<foo3.size(); i++)
        std::cout << ' ' << foo3[i];
    std::cout << '\n';

    std::cout << "bar contains:";
    for (unsigned i=0; i<bar3.size(); i++)
        std::cout << ' ' << bar3[i];
    std::cout << '\n';

    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;

    ft::vector<int> foo4 (3,100);   // three ints with a value of 100
    ft::vector<int> bar4 (5,200);   // five ints with a value of 200

    foo4.swap(bar4);

    std::cout << "foo contains:";
    for (unsigned i=0; i<foo4.size(); i++)
        std::cout << ' ' << foo4[i];
    std::cout << '\n';

    std::cout << "bar contains:";
    for (unsigned i=0; i<bar4.size(); i++)
        std::cout << ' ' << bar4[i];
    std::cout << '\n';

    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "************* test clear **************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;

    std::cout << "std :" << std::endl;
    std::vector<int> nvec4;
    nvec4.push_back (100);
    nvec4.push_back (200);
    nvec4.push_back (300);

    std::cout << "nvec4 contains:";
    for (unsigned i=0; i<nvec4.size(); i++)
        std::cout << ' ' << nvec4[i];
    std::cout << '\n';

    nvec4.clear();
    nvec4.push_back (1101);
    nvec4.push_back (2202);

    std::cout << "nvec4 contains:";
    for (unsigned i=0; i<nvec4.size(); i++)
        std::cout << ' ' << nvec4[i];
    std::cout << '\n';

    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;

    ft::vector<int> nvec5;
    nvec5.push_back (100);
    nvec5.push_back (200);
    nvec5.push_back (300);

    std::cout << "nvec5 contains:";
    for (unsigned i=0; i<nvec5.size(); i++)
        std::cout << ' ' << nvec5[i];
    std::cout << '\n';

    nvec5.clear();
    nvec5.push_back (1101);
    nvec5.push_back (2202);

    std::cout << "nvec5 contains:";
    for (unsigned i=0; i<nvec5.size(); i++)
        std::cout << ' ' << nvec5[i];
    std::cout << '\n';

    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "******** relational operators *********" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;

    std::cout << "std :" << std::endl;
    std::vector<int> foo5 (3,100);   // three ints with a value of 100
    std::vector<int> bar5 (2,200);   // two ints with a value of 200

    if (foo5==bar5) std::cout << "foo and bar are equal\n";
    if (foo5!=bar5) std::cout << "foo and bar are not equal\n";
    if (foo5< bar5) std::cout << "foo is less than bar\n";
    if (foo5> bar5) std::cout << "foo is greater than bar\n";
    if (foo5<=bar5) std::cout << "foo is less than or equal to bar\n";
    if (foo5>=bar5) std::cout << "foo is greater than or equal to bar\n";

    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;
    ft::vector<int> foo6 (3,100);   // three ints with a value of 100
    ft::vector<int> bar6 (2,200);   // two ints with a value of 200

    if (foo6==bar6) std::cout << "foo and bar are equal\n";
    if (foo6!=bar6) std::cout << "foo and bar are not equal\n";
    if (foo6< bar6) std::cout << "foo is less than bar\n";
    if (foo6> bar6) std::cout << "foo is greater than bar\n";
    if (foo6<=bar6) std::cout << "foo is less than or equal to bar\n";
    if (foo6>=bar6) std::cout << "foo is greater than or equal to bar\n";

    std::cout << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "*********** swap no member ************" << std::endl;
    std::cout << "***************************************" << std::endl << std::endl;

    std::cout << "std :" << std::endl;
    std::vector<int> foo7 (3,100);   // three ints with a value of 100
    std::vector<int> bar7 (5,200);   // five ints with a value of 200

    foo7.swap(bar7);

    std::cout << "foo contains:";
    for (std::vector<int>::iterator it = foo7.begin(); it!=foo7.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "bar contains:";
    for (std::vector<int>::iterator it = bar7.begin(); it!=bar7.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "-----------------------------" << std::endl;
    std::cout << "ft :" << std::endl;
    ft::vector<int> foo8 (3,100);   // three ints with a value of 100
    ft::vector<int> bar8 (5,200);   // five ints with a value of 200

    foo8.swap(bar8);

    std::cout << "foo contains:";
    for (ft::vector<int>::iterator it = foo8.begin(); it!=foo8.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "bar contains:";
    for (ft::vector<int>::iterator it = bar8.begin(); it!=bar8.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    return 0;
}
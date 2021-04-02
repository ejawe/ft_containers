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
    




    return 0;
}
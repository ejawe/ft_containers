// #include "vector_class.hpp"
// #include "vector_impl.hpp"


#include <vector>
#include <iostream>

int main()
{
    // ft::vector<int> a(5, 0);
    std::vector<int> vec(5, 8);

    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << std::endl;

    std::cout << std::endl;

    std::vector<int>::iterator it;
    it = vec.begin();
    it++;
    it++;
    it++;
    
    int pos = 0;
    std::vector<int>::iterator ite = vec.begin();
    while (ite != it)
    {
        ite++;
        pos++;
    }
    std::cout << "position = " << pos << std::endl;

    vec.insert(it, 3, 9);

    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << std::endl;

    return 0;
}
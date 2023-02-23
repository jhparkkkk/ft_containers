#include "./../include/UnitTestVector.hpp"
#include <cassert>
#include <iostream>


void    testVectorModifiers() {
    
    vector<int> test;

    for (size_t i=1; i <= 10; i++)
        test.push_back(i * 10);

    assert(test.front() == 10);
    std::cout << "first value: " << test.front() << "\n";

    assert(test.back() == 100);
    std::cout << "last value: " << test.back() << "\n";

    test.pop_back();
    std::cout << "last value: " << test.back() << "\n";

    while (!test.empty())
    {
        std::cout << "last value: " << test.back() << "\n";
        std::cout << "size: " << test.size() << "\n";
        test.pop_back();
    }
    assert(test.empty()==true);
    std::cout << "container is empty.\n";


}
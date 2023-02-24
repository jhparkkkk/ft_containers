
#include "./../include/UnitTestVector.hpp"

void    testVectorOperators()
{
    std::cout << "test vector operators\n";
    // vector<std::string> one;
    // vector<std::string> two;

    // one.push_back("park");

    // two.push_back("park");

    // assert(one==two);

    vector<int> one(5,10);
    vector<int> two (one);
    assert(one==two);


}
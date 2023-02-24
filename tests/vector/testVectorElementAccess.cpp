#include "./../include/UnitTestVector.hpp"

static void    test_front()
{
    vector<int> test(5, 10);
    assert(test.front()==10);

}

static void test_operator()
{
    vector<int> test;
    for (size_t i=1; i<=10; i++) test.push_back(i*10);
    for (size_t i=0; i<10; i++) std::cout << test[i] << " ";
    
    std::cout << test[2340] << "\n";
    test[2340] = 1;
    std::cout << test[2340] << "\n";
    std::cout << test.capacity() << "\n";
    std::cout << test.size() << "\n";

    std::cout << "init vector with 10 zero initialized elements:\n";
    vector<int> test_empty(10);
    for (size_t i=0; i<10; i++) test_empty[i] = i*10;
    std::cout << "assigning values\n";
    for (size_t i=0; i<10; i++) std::cout << test_empty[i] << " ";
    std::cout << '\n';

    vector<int> myvector (10);   // 10 zero-initialized elements
    vector<int>::size_type sz = myvector.size();
    for (unsigned i=0; i<sz; i++) myvector[i]=i;
    for (unsigned i=0; i<sz/2; i++)
    {
        int temp;
        temp = myvector[sz-1-i];
        myvector[sz-1-i]=myvector[i];
        myvector[i]=temp;
    }
    for (unsigned i=0; i<sz; i++) std::cout << ' ' << myvector[i];
    std::cout << '\n';

}

void    test_at()
{
    vector<int> test(5,10);

    std::cout << test.at(0) << "\n";
    try {
        vector<int>::size_type size = test.size();
        for (size_t i=0; i<size; i++)
            std::cout << test.at(i) << " ";
        std::cout << '\n';
        std::cout << test.at(size + 1) << " ";
    }
    catch (const std::out_of_range& oor) {
    std::cerr << "Out of Range error: " << oor.what() << '\n';
    }

}

void    testVectorElementAccess()
{
    std::cout << "test vector element access\n";
    std::cout << BOLDBLUE << "front()\n" << RESET;
    test_front();
    std::cout << BOLDBLUE << "operator[]()\n" << RESET;
    test_operator();
    std::cout << BOLDBLUE << "at()\n" << RESET;
    test_at();
}
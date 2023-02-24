#include "./../include/UnitTestVector.hpp"

static void    test_max_size()
{
    vector<int>             test_int;
    vector<unsigned int>    test_uint;
    vector<float>           test_float;
    vector<double>          test_double;
    vector<std::string>     test_string; 

    std::cout << "max_size(): " << test_int.max_size() << "\n";
    std::cout << "max_size(): " << test_uint.max_size() << "\n";
    std::cout << "max_size(): " << test_double.max_size() << "\n";
    std::cout << "max_size(): " << test_float.max_size() << "\n";
    std::cout << "max_size(): " << test_string.max_size() << "\n";
}

static void test_size()
{
    vector<int> test(1,10);
    std::cout << "size: " << test.size() << "\n";
    for (size_t i=2; i<=10; i++)
    {
        test.push_back(i*10);
        assert(test.size()==i);
        std::cout << "size: " << test.size() << "\n";
    }
    for (size_t i=9; i>0; i--)
    {
        test.pop_back();
        assert(test.size()==i);
        std::cout << "size: " << test.size() << "\n";
    }
}

static void test_capacity()
{
    vector<int> test(1,10);
    test.push_back(20);
    assert(test.capacity()==2 && test.size()==2);
    std::cout << "capacity: " << test.capacity() << "\n";
    test.push_back(30);
    assert(test.capacity()==4 && test.size()==3);
    std::cout << "capacity: " << test.capacity() << "\n";
    test.push_back(40);
    assert(test.capacity()==4 && test.size()==4);
    std::cout << "capacity: " << test.capacity() << "\n";
    test.push_back(50);
    assert(test.capacity()==8 && test.size()==5);
    std::cout << "capacity: " << test.capacity() << "\n";
}

static void test_reserve()
{

    vector<int>::size_type sz;

    vector<int> foo;
    sz = foo.capacity();
    std::cout << "making foo grow:\n";
    for (int i=0; i<100; ++i) {
        foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << "//" << foo.capacity() << '\n';
    }
    }

    vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100);
    std::cout << "making bar grow:\n";
    for (int i=0; i<100; ++i) {
        bar.push_back(i);
        if (sz!=bar.capacity()) {
            sz = bar.capacity();
        std::cout << "capacity changed: " << sz << "//"<< bar.capacity() <<'\n';
        }
    }
}

void    testVectorCapacity()
{
    std::cout << "test vector capacity\n";
    std::cout << BOLDBLUE << "max_size()\n" << RESET;
    test_max_size();
    std::cout << BOLDBLUE << "size()\n" << RESET;
    test_size();
    std::cout << BOLDBLUE << "capacity()\n" << RESET;
    test_capacity();
    std::cout << BOLDBLUE << "reserve()\n" << RESET;
    test_reserve();
}
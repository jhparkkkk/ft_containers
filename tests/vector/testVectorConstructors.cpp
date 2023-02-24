/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVectorConstructors.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:05:36 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/21 14:27:02 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/UnitTestVector.hpp"

static void test_get_allocator()
{
    vector<int> test;
    int* arr;

    arr = test.get_allocator().allocate(5);
    for (size_t i=0; i<5; i++) test.get_allocator().construct(&arr[i],i);

    std::cout << "The allocated array contains:";
    for (size_t i=0; i<5; i++) std::cout << ' ' << arr[i];
    std::cout << '\n';

    for (size_t i=0; i<5; i++) test.get_allocator().destroy(&arr[i]);
    test.get_allocator().deallocate(arr,5);
}

static void test_operator()
{
    vector<int> one(1, 10);
    vector<int> two(1, 42);
    assert(one.front()==10);    
    one = two;
    assert(one.front()==42);
    vector<int> three = one;
    assert(three.front()==42);
}

void    testVectorConstructors() {
    std::cout << "test vector constructors\n";
    std::cout << BOLDBLUE << "default constructor\n" << RESET;
    vector<int> empty_ctor;
    assert (empty_ctor.size() == 0);
    std::cout << "size is: " << empty_ctor.size() << "\n";
    
    std::cout << BOLDBLUE << "fill constructor\n" << RESET;
    vector<int> fill_ctor(5, 10);
    assert (fill_ctor.front() == 10);
    std::cout << "fill_ctor front: " << fill_ctor.front() << "\n";
    assert (fill_ctor.back() == 10);
    std::cout << "fill_ctor back: " << fill_ctor.back() << "\n";

    std::cout << BOLDBLUE << "copy constructor\n" << RESET;
    vector<int> copy_ctor(fill_ctor);
    assert (copy_ctor.front() == 10);
    std::cout << "copy_ctor front: " << copy_ctor.front() << "\n";
    assert (copy_ctor.back() == 10);
    std::cout << "copy_ctor back: " << copy_ctor.back() << "\n";

    std::cout << BOLDBLUE << "range constructor\n" << RESET;
    std::vector<int> to_copy(10, 20);
    vector<int> range_ctor (to_copy.begin(), to_copy.end());
    std::cout << "range_ctor front: " << range_ctor.front() << "\n";
    std::cout << "range_ctor back: " << range_ctor.back() << "\n";

    int myints[] = {16,2,77,29};
    vector<int> range_arr_ctor (myints, myints + sizeof(myints) / sizeof(int));
    std::cout << "range_arr_ctor front: " << range_arr_ctor.front() << "\n";
    std::cout << "range_arr_ctor back: " << range_arr_ctor.back() << "\n";

    std::cout << BOLDBLUE << "operator=\n" << RESET;
    test_operator();

    std::cout << BOLDBLUE << "get_allocator()\n" << RESET;
    test_get_allocator();



}
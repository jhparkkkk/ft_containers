/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:02:14 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/16 15:17:12 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include "./../include/reverse_iterator.hpp"
#include <iostream>
#include <iterator>
#include <vector>

#ifdef FT
	using namespace ft;
#else
	using namespace std;
#endif

#include <iostream>
// #include <iterator>
#include "./include/meta_function.hpp"

template<typename T, size_t SIZE>
class Stack {
    T arr[SIZE];
    size_t pos;
public:
    Stack() : pos(0) {}
    T pop() {
        return arr[--pos];
    }
    Stack& push(const T& t) {
        arr[pos++] = t;
        return *this;
    }
    // we wish that looping on Stack would be in LIFO order
    // thus we use std::reverse_iterator as an adaptor to existing iterators
    // (which are in this case the simple pointers: [arr, arr+pos)
    typedef reverse_iterator<T*> reverse_iterator;
    reverse_iterator rbegin() {
        return reverse_iterator(arr + pos);
    }
    reverse_iterator rend() {
        return reverse_iterator(arr);
    }
};

void test_reverse_iterator()
{
    std::cout << "test reverse iterator\n";
    Stack<int, 8> s;
    s.push(5).push(15).push(25).push(35);

    /*----------------------------- CONSTRUCTORS -----------------------------*/
    
    // default
    Stack<int, 8>::reverse_iterator it;

    // initialization
    std::vector<int>::iterator vector_it;
    reverse_iterator<std::vector<int>::iterator> explicit_it(vector_it);
    
    // copy
    reverse_iterator<std::vector<int>::const_iterator> copy_it(explicit_it);

    /*--------------------------- MEMBER FUNCTIONS ---------------------------*/
    
    /*_____________________________ operator*() ______________________________*/
    it = s.rbegin();
    assert(*it == 35);
    std::cout << "test operator*() : OK\n";
    
    /*_____________________________ operator->() _____________________________*/
    
    std::vector<std::string> v;
    v.push_back("Jee");
    v.push_back("Park");
    v.push_back("42 stud");
    // Creates a reversed iterator to reverse direction to a given iterator. 
    // Inits first an iterator and checks elements' size;
    std::vector<std::string>::iterator v_it = v.begin();
    assert(v_it->size()==3);
    std::cout << "Size of 1st element is: " << v_it->size() << "\n";
    v_it++;
    assert(v_it->size()==4);
    std::cout << "Size of the 2nd element is: " << v_it->size() << "\n";
    v_it++;
    assert(v_it->size()==7);
    std::cout << "Size of the 3rd element is: " << v_it->size() << "\n";
    v_it++;

    // Inits reverse iterator from v_it
    reverse_iterator<std::vector<std::string>::iterator> v_rit(v_it);

    // Tests operator -> to access members std::string objects
    assert(v_rit->size()==7);
    std::cout << "size of last element is : " << v_rit->size() << std::endl;

    /*______________________________ Operators _______________________________*/
    std::cout << "pre-increments:\n";
    std::cout << *v_rit << "\n";
    std::cout << *++v_rit << "\n";
    std::cout << *v_rit << "\n";
    
    std::cout << "post-increments:\n";
    std::cout << *v_rit << "\n";
    std::cout << *v_rit++ << "\n";
    std::cout << *v_rit << "\n";

    std::cout << "pre-decrements:\n";
    std::cout << *v_rit << "\n";
    std::cout << *--v_rit << "\n";
    std::cout << *v_rit << "\n";
    
    std::cout << "post-decrements:\n";
    std::cout << *v_rit << "\n";
    std::cout << *v_rit-- << "\n";
    std::cout << *v_rit << "\n";

    std::cout << "shallow advances increment by n position: \n";
    std::cout << *(v_rit + 1) << "\n";
    std::cout << *(v_rit + 2) << "\n";
    std::cout << *v_rit << "\n";

    std::cout << "deep advances increment by n position: \n";
    std::cout << *v_rit << "\n";
    v_rit += 1;
    std::cout << *v_rit << "\n";
    v_rit += 1;
    std::cout << *v_rit << "\n";

    std::cout << "shallow advances decrement by n position: \n";
    std::cout << *(v_rit - 1) << "\n";
    std::cout << *(v_rit - 2) << "\n";
    std::cout << *v_rit << "\n";

    std::cout << "deep advances decrement by n position: \n";
    std::cout << *v_rit << "\n";
    v_rit -= 1;
    std::cout << *v_rit << "\n";
    v_rit -= 1;
    std::cout << *v_rit << "\n";

    std::cout << "access to the element at [i]: \n";
    for (int i=2; i >= 0; i--)
        std::cout << i << ": " << v_rit[i] << "\n";
    for (int i=0; i < 3; i++)
        std::cout << i << ": " << v_rit[i] << "\n";
    
    /*_______________________ Relational Operators ___________________________*/

    std::vector<int> myvector;

    for (int i = 0; i < 10; i++) {
        myvector.push_back(i);
    }

    typedef std::vector<int>::iterator iter_type;
    iter_type from = myvector.begin();
    iter_type until = myvector.end();

    reverse_iterator<iter_type> rev_until(from);
    reverse_iterator<iter_type> rev_from(until);

    std::cout << "myvector:";
    while (rev_from != rev_until) {
        std::cout << ' ' << *rev_from++;
    }
    std::cout << '\n';
    std::cout << *rev_from << "\n";
    std::cout << *rev_until << "\n";

    reverse_iterator<int *> x = s.rbegin();
    reverse_iterator<int *> xx = s.rbegin();

    reverse_iterator<int *> y = s.rend();

    assert((x < y) == true);
        std::cout << "iterator x is before iterator y in the underlying container\n";
    assert((x <= xx && x == xx) == true);
        std::cout << "iterator x is equal to iterator xx in the underlying container"
                  << " meaning : pointing the same element\n";
   
   ///// MISSING : Comparison between 2 different types of reverse_iterator
    
    /*_________________ computes distance between 2 iterators ________________*/
    
    std::cout << "x = " << *x << " y = " << *y << " xx = " << *xx << "\n";
    assert(x-y==-4);
    std::cout << "distance between x and y is: " <<  x - y << "\n";
    assert(x-xx==0);
    std::cout << "distance between x and xx is: " <<  x - xx << "\n";

    x = x + 4;
    assert(*x==5);
    assert(x-y==0);
    std::cout << "x is now pointing the same element as y.\n"
              << "x value: " << *x << "\n"
              << "y value: " << *y << "\n"
              << "distance between x and y: " << x-y << "\n";
}

/*
----------------------------------- NOTES --------------------------------------

----------------------------------- ISSUES ------------------------------------
>>> Compilation: comparison between 2 different types of reverse_iterator

*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:01:35 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/18 11:03:20 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./../include/enable_if.hpp"
#include <type_traits>
#include "./../include/is_integral.hpp"

#ifdef FT
	using namespace ft;
#else
	using namespace std;
#endif

struct TypeTraits {
    template < class T >
    void f(const T& value, typename enable_if<!is_integral<T>::value>::type* = 0 )
    {
        std::cout << "value is " << value << "\n";
        std::cout << "Type is not int" << std::endl;
    }

    template< class T >
    void f(const T& value, typename enable_if<is_integral<T>::value>::type* = 0)
    {
        std::cout << "value is " << value << "\n";
        std::cout << "Type is int" << std::endl;
    }
};

/*
    Tests ::enable_if and ::is_integral 
*/
void test_type_traits()
{
    TypeTraits test;
    test.f(1);
    test.f(-1);
    test.f(1.1);
    test.f(-1.1);
    test.f("-");
    test.f("c");
    test.f("plop");
    test.f(100000000000000000);
    test.f(-100000000000000000);
    test.f(10000000000.0000000);
    test.f(-10000000000.0000000);
    test.f(true);
    test.f(false);

    std::cout << std::boolalpha; 
    std::cout << "char: " << is_integral<char>::value << std::endl;
    std::cout << "int: " << is_integral<int>::value << std::endl;
    std::cout << "float: " << is_integral<float>::value << std::endl;
}
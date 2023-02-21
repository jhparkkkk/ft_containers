/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:41:36 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/19 11:38:11 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>

#include "./../include/pair.hpp"
#include "./../include/make_pair.hpp"


#ifdef FT
	using namespace ft;
#else
	using namespace std;
#endif

void    test_utility()
{
    std::cout << "test_utility\n";
    pair <std::string, int> default_ctor;
    pair <std::string, int> initialization_ctor("jeepark", 42);
    pair <std::string, int> copy_ctor(initialization_ctor);

    std::cout << "Testing ::pair constructors:\n";
    std::cout << default_ctor.first << " " << default_ctor.second << "\n";
    assert(initialization_ctor.first=="jeepark" && initialization_ctor.second==42);
    std::cout << initialization_ctor.first << " " << initialization_ctor.second << "\n";
    assert(copy_ctor.first=="jeepark" && copy_ctor.second==42);
    std::cout << copy_ctor.first << " " << copy_ctor.second << "\n";

    std::cout << "Testing ::pair relational operators:\n";
    assert(initialization_ctor == copy_ctor);
    std::cout << "members are equal.\n";
    
    copy_ctor.second = 24;
    assert(initialization_ctor != copy_ctor);
    std::cout << "members are not equal.\n";

    pair <int,int> foo;
    pair <int,int> bar;

    foo = make_pair (10,20);
    bar = make_pair (10.5,'A');

    std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
    std::cout << "bar: " << bar.first << ", " << bar.second << '\n';

    assert(bar != foo);
    bar = foo;
    assert(bar == foo);
    std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
    std::cout << "bar: " << bar.first << ", " << bar.second << '\n';

    
}
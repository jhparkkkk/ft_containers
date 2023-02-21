/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:10:26 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/18 14:14:52 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

#include "./../include/equal.hpp"
#include "./../include/lexicographical_compare.hpp"


#ifdef FT
	using namespace ft;
#else
	using namespace std;
#endif

#define EQUAL std::cout << "The contents of both sequences are equal.\n";
#define DIFFER std::cout << "The contents of both sequences differ.\n";

bool mypredicate (int i, int j) { return (i==j); }

void    test_equal()
{
    int myints[] = {20,40,60,80,100};               
    std::vector<int>myvector (myints,myints+5);

    std::cout << "Using default comparison:\n";
    assert(ft::equal(myvector.begin(), myvector.end(), myints)==true);
        EQUAL;
    assert(std::equal(myvector.begin(), myvector.end(), myints)==true);
        EQUAL;

    std::cout << "Modifying content of myvector:\n";
    myvector[3]=81;
    assert(ft::equal(myvector.begin(), myvector.end(), myints)==false);
        DIFFER;
    assert(std::equal(myvector.begin(), myvector.end(), myints)==false);
        DIFFER;

    std::cout << "Using predicate comparison:\n";
    assert(ft::equal(myvector.begin(), myvector.end(), myints, mypredicate)==false);
        DIFFER;
    assert(std::equal(myvector.begin(), myvector.end(), myints, mypredicate)==false);
        DIFFER;
    
    std::cout << "Comparing a container with itself.\n";
    assert(ft::equal(myvector.begin(), myvector.end(), myvector.begin())==true);
        EQUAL;
    assert(ft::equal(myvector.begin(), myvector.end(), myvector.end())==false);
        DIFFER;
    assert(std::equal(myvector.begin(), myvector.end(), myvector.begin())==true);
        EQUAL;
    assert(std::equal(myvector.begin(), myvector.end(), myvector.end())==false);
        DIFFER;
}

void    test_lexicographical_compare()
{
    // char one[] = "jeepark";
    // char two[] = "jeew";

    std::string one     = "jeepark";
    std::string two     = "jeez";
    std::string three   = "beep";

 
    assert (ft::lexicographical_compare(one.begin(), one.end(), two.begin(), two.end())==true);
    std::cout << "jeepark is lexicographically less than jeez\n";
    assert (std::lexicographical_compare(one.begin(), one.end(), two.begin(), two.end())==true);
    std::cout << "jeepark is lexicographically less than jeez\n";
    assert (ft::lexicographical_compare(one.begin(), one.end(), three.begin(), three.end())==false);
    std::cout << "jeepark is not lexicographically less than beep\n";
    assert (std::lexicographical_compare(one.begin(), one.end(), three.begin(), three.end())==false);
    std::cout << "jeepark is not lexicographically less than beep\n";
   
}

void    test_algorithm()
{
    test_equal();
    test_lexicographical_compare();
}

/*
----------------------------------- NOTES --------------------------------------

----------------------------------- ISSUES ------------------------------------
>>> Error: call to 'equal' is ambiguous
    <algorithm> et equal.hpp pourtant je distingue bien avec le namespace
    Pas eu ce probleme jusqu'ici...
    > utiliser ft:: et std:: pour le moment. 
    > contrairement a lexicographical_compare qui appelle tres bien la fonction
      de son namespace
      > ca marche si char one[] = "jeepark"
      > mais std::string one = "jeepark"
        > parce qque j'envoie des iterateurs ? 

*/
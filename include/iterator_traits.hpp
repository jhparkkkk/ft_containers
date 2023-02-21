/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:16:05 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/20 10:35:39 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

/*
    Structure containing informations regarding an iterator.
    It is used as a common interface for all type definitions an iterator
    should have.
*/
namespace ft {
    template<class Iterator>
    struct iterator_traits {
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;
    };
    template<class T>
    struct iterator_traits<T*> {
        typedef ptrdiff_t                               difference_type;
        typedef T                                       value_type;
        typedef T*                                      pointer;
        typedef T&                                      reference;
        typedef std::random_access_iterator_tag         iterator_category;
    };
    template<class T>
    struct iterator_traits<const T*> {
        typedef ptrdiff_t                               difference_type;
        typedef T                                       value_type;
        typedef const T*                                pointer;
        typedef const T&                                reference;
        typedef std::random_access_iterator_tag         iterator_category;
    };
}

/*
----------------------------------- NOTES --------------------------------------

    >>> DEFINITION
    permet de déterminer les types associés à un itérateur.
    Utilisé pour obtenir des informations sur les itérateurs.
    Par exemple le type de la valeur pointée par l'itérateur
    le type de la différence entre deux itérateurs, etc.

    >>> SYNOPSIS    
    template <typename T>
    struct iterator_traits<MyClass<T>::iterator> {
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;
    typedef random_access_iterator_tag iterator_category;
    };

    >>> EXEMPLE
    j'appelle iterator_traits pour : 
	1) obtenir la distance entre le 1er et le dernier de mon container.
	2) declarer le type de mon element a parcourir de maniere generique. 

    namespace ft{
	template <class BidirectionalIterator>
	void myreverse(BidirectionalIterator first, BidirectionalIterator last) {
	typename iterator_traits<BidirectionalIterator>::difference_type n = distance(first, last);
	std::cout << "n = " << n << '\n';
	--n;
	while(n > 0) {
		typename iterator_traits<BidirectionalIterator>::value_type tmp;
		tmp = *first;
		*first++ = *--last;
		*last = tmp;
		n -= 2;
    }
    }
    }
    > main.cpp
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	std::cout << "Avant l'inversion : ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    	std::cout << *it << ' ';
	}
	std::cout << std::endl;

	ft::myreverse(v.begin(), v.end());

	std::cout << "Après l'inversion : ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    	std::cout << *it << ' ';
	}
	std::cout << std::endl;

------------------------------------ ISSUES ------------------------------------
    >>> ISSUE:  Why random_access_iterator_tag isn't compiling ?
    >>> CAUSE:  Class random_iterator_tag is not defined in namespace ft
    >>> FIX:    Add "std::"
*/ 

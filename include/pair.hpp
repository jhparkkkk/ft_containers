/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:16:15 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/19 11:34:25 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

namespace ft {
    template <class T1, class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        T1 first;
        T2 second;
        
        pair() : first(T1()), second(T2()) { /*std::cout << "default ctor\n";*/}
        pair(const T1& x, const T2& y) : first(x), second(y) {/*std::cout << "initialization ctor\n";*/}
        template<class U, class V>
        pair(const pair<U, V> &p) : first(p.first), second(p.second) { /*std::cout << "copy ctor\n";*/ }

        pair& operator=(const pair& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
        }
    };
    template <class T1, class T2>
    bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y) {
        return x.first == y.first && x.second == y.second; }
    
    template <class T1, class T2>
    bool operator!=(const pair<T1, T2>& x, const pair<T1, T2>& y) {    
        return !(x == y); }
    
    template <class T1, class T2>
    bool operator< (const pair<T1, T2>& x, const pair<T1, T2>& y) {    
        return x.first < y.first || (!(y.first < x.first) && x.second < y.second); }
    template <class T1, class T2>
    bool operator> (const pair<T1, T2>& x, const pair<T1, T2>& y) {
        return y < x;
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2>& x, const pair<T1, T2>& y) {
        return !(x < y);
    }
    template <class T1, class T2>
    bool operator<=(const pair<T1, T2>& x, const pair<T1, T2>& y) {
        return !(y < x);
    }

}

/*
----------------------------------- NOTES --------------------------------------
>>> Constructors 
    > Default
    Creates @c first and @c second using their respective default constructors.
    > Initialization
    2 objects may be passed to a @c pair constructor to be copied.
    > Copy
    A templated copy constructor for the pair class itself.
>>> Relational Operators
    > Q/ other operators than == are > c++98 ? 
----------------------------------- ISSUES ------------------------------------

*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:19:04 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/12 16:25:55 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>

namespace ft {
    template <class T, class CONTAINER = std::vector<T> >
class stack {
    public:
        typedef typename CONTAINER::value_type value_type;
        typedef typename CONTAINER::size_type size_type;
        typedef CONTAINER container_type;

    protected:
        CONTAINER c;

    public:

        /* Constructor */
        explicit stack(const CONTAINER& to_copy = CONTAINER()): c(to_copy) {};

        /*------------------------------- Capacity -------------------------------*/
        bool empty() const {
            return c.empty();
        }
        
        size_type size() const {
            return c.size();
        }
        
        /*-------------------------- Elements Access -----------------------------*/
     
        value_type& top() {
            return c.back();
        }
        
        const value_type& top() const {
            return c.back();
        }
        
        /*------------------------------- Modifiers -------------------------------*/

        void push(const value_type& x) {
            // std::cout << "ft push\n";
            c.push_back(x);
        }
        
        void pop() {
            c.pop_back();
        }
        
        /*-------------------------- Relational Operators -------------------------*/
        template <class U, class C>
            friend bool operator==(const stack<U,C>& x, const stack<U,C>& y);
        template <class U, class C>
            friend bool operator< (const stack<U,C>& x, const stack<U,C>& y);
        template <class U, class C>
            friend bool operator!=(const stack<U,C>& x, const stack<U,C>& y);
        template <class U, class C>
            friend bool operator> (const stack<U,C>& x, const stack<U,C>& y);
        template <class U, class C>
            friend bool operator<=(const stack<U,C>& x, const stack<U,C>& y);
        template <class U, class C>
            friend bool operator>=(const stack<U,C>& x, const stack<U,C>& y);

    };

    template <class U, class C>
            bool operator==(const stack<U,C>& x, const stack<U,C>& y) {
                return x.c == y.c; }

    template <class U, class C>
            bool operator< (const stack<U,C>& x, const stack<U,C>& y) {
                return x.c < y.c; }
    
    template <class U, class C>
            bool operator!=(const stack<U,C>& x, const stack<U,C>& y) {
                return x.c != y.c; }

    template <class U, class C>
            bool operator> (const stack<U,C>& x, const stack<U,C>& y) {
                return x.c > y.c; }

    template <class U, class C>
            bool operator<=(const stack<U,C>& x, const stack<U,C>& y) {
                return x.c <= y.c; }

    template <class U, class C>
            bool operator>=(const stack<U,C>& x, const stack<U,C>& y) {
                return x.c >= y.c; }
}

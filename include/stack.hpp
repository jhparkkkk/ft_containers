/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:19:04 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/11 13:30:26 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>

namespace ft {
    template <class T, class Container = std::vector<T> >
class stack {
    public:
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type size_type;
        typedef Container container_type;

    protected:
        Container c;

    public:

        /* Constructor */
        explicit stack(const Container& to_copy = Container()): c(to_copy) {};

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

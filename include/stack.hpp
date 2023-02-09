/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:19:04 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/09 15:14:26 by jeepark          ###   ########.fr       */
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
        /*
            Constructor
        */
        explicit stack(const Container& = Container()): c() {};

        /*
            Capacity 
        */

        bool empty() const {
            return c.empty();
        }
        
        size_type size() const {
            std::cout << "size is : ";
            return c.size();
        }
        
        /*
            Elements acces
        */        
        
        value_type& top() {
            return c.back();
        }
        
        const value_type& top() const {
            return c.back();
        }
        
        /*
            Modifiers
        */
        void push(const value_type& x) {
            c.push_back(x);
        }
        
        void pop() {
            c.pop_back();
        }
    };

    // template <class T, class Container>
    //     bool operator==(const stack<T, Container>& x, const stack<T, Container>& y);
    
    // template <class T, class Container>
    //     bool operator< (const stack<T, Container>& x, const stack<T, Container>& y);

    // template <class T, class Container>
    //     bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y);

    // template <class T, class Container>
    //     bool operator> (const stack<T, Container>& x, const stack<T, Container>& y);

    // template <class T, class Container>
    //     bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y);

    // template <class T, class Container>
    //     bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y);
}

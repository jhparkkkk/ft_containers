/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:34:07 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/18 10:53:45 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

namespace ft {
    // helper class:
    template <class T, T v> struct integral_constant {
        static const T              value = v;
        typedef T                   value_type;
        typedef integral_constant   type;
        operator value_type() const { return value; }     
    };
    
    typedef integral_constant<bool, true>  true_type; 
    typedef integral_constant<bool, false> false_type;
    
    template <class T> struct is_integral : public false_type {};
    template <> struct is_integral<signed char>         : public true_type {};
    template <> struct is_integral<signed short>        : public true_type {};
    template <> struct is_integral<signed int>          : public true_type {};
    template <> struct is_integral<signed long>         : public true_type {};
    template <> struct is_integral<signed long long>    : public true_type {};

    template <> struct is_integral<unsigned char>       : public true_type {};
    template <> struct is_integral<unsigned short>      : public true_type {};
    template <> struct is_integral<unsigned int>        : public true_type {};
    template <> struct is_integral<unsigned long>       : public true_type {};
    template <> struct is_integral<unsigned long long>  : public true_type {};
    template<> struct is_integral<char>                 : public true_type{ };
    template<> struct is_integral<bool>                 : public true_type{};
}


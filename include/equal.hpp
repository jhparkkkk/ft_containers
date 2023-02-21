/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:00:46 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/18 11:49:40 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

namespace ft {
    /* equality */ 
    template <class Iterator1, class Iterator2>
    bool equal( Iterator1 first1, Iterator1 last1, Iterator2 first2 )
    {
        std::cout << "ft::equal\n";
        while (first1!=last1)
        {
            if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
                return false;
            ++first1; ++first2;
        }
        return true;
    }
    /* predicate */
    template <class Iterator1, class Iterator2, class BinaryPredicate>
    bool equal( Iterator1 first1, Iterator1 last1, Iterator2 first2, BinaryPredicate pred)
    {
        std::cout << "ft::equal\n";
        while (first1!=last1)
        {
            if (!pred(*first1,*first2))
                return false;
            ++first1; ++first2;
        }
        return true;
    }
}
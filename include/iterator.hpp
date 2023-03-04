/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:37:35 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/20 13:26:04 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iterator_traits.hpp"

namespace ft {
    template <class Iterator>
    class randomAccessIterator {
        protected:
            Iterator current;
        public:
            typedef Iterator
                iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category
                iterator_category;
            typedef typename iterator_traits<Iterator>::value_type
                value_type;
            typedef typename iterator_traits<Iterator>::difference_type
                difference_type;
            typedef typename iterator_traits<Iterator>::pointer
                pointer;
            typedef typename iterator_traits<Iterator>::reference
                reference;
        /*-------------------------- Constructors ----------------------------*/
        randomAccessIterator() : current() {}
        randomAccessIterator(pointer current) : current(current) {}
        randomAccessIterator(const randomAccessIterator& o) : current(o.current) {}


    }; 
}
    
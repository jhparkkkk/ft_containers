/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:44:33 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/13 10:13:10 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/iterator_traits.hpp"
#include <vector>

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

bool    test_iterator_traits()
{
    std::vector<int> v;
    for (int i = 1; i <= 5; i++)
        v.push_back(i);

	std::cout << "Before myreverse(): ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    	std::cout << *it << ' ';
	}
	std::cout << std::endl;

	ft::myreverse(v.begin(), v.end());

	std::cout << "After myreverse() : ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    	std::cout << *it << ' ';
	}
	std::cout << std::endl;
    return true;
}
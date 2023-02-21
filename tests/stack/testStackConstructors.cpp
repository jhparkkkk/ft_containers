/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testStackConstructors.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:48:31 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/13 09:58:46 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/UnitTestStack.hpp"

#include <deque>

void    testStackConstructors() {
    std::cout << BOLDMAGENTA << "empty stack\n" << RESET;
    stack<int> empty_stack;
    std::cout << "size: " <<  empty_stack.size() << '\n';

    std::cout << BOLDMAGENTA << "container vector of size 2\n" << RESET;
    std::vector<int> my_vector(2, 200);
    std::cout << "size: " <<  my_vector.size() << '\n';

    std::cout << BOLDMAGENTA << "stack container adaptor with container vector\n" << RESET;
    stack<int,std::vector<int> > adaptor_vector (my_vector);
    std::cout << "size: " << adaptor_vector.size() << '\n';

    std::cout << BOLDMAGENTA << "container deque of size 42\n" << RESET;
    std::deque<int> my_deque(42, 1);
    std::cout << "size: " <<  my_deque.size() << '\n';

    std::cout << BOLDMAGENTA << "stack container adaptor with container deque\n" << RESET;
    stack<int,std::deque<int> > adaptor_deque (my_deque);
    std::cout << "size: " << adaptor_deque.size() << '\n';
}
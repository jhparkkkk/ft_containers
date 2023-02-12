/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testStackOperators.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:45:19 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/12 11:04:54 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UnitTestStack.hpp"
#include <iostream>

void    testStackOperators() {
    UnitTestStack<int> stack_1;
    UnitTestStack<int> stack_2;
    stack_1.push(4);
    stack_2.push(0);
    if (stack_1 == stack_2)
        std::cout << "same\n";
    else
        std::cout << "different\n";
    
    int i = 0;
    while (stack_1 != stack_2) {
        stack_2.pop();
        stack_2.push(i);
        i++;
    }
    
    std::cout << "stack_1 is now equal to stack_2.\n";
    stack_1.push(40);
    if (stack_1 > stack_2)
        std::cout << "stack_1 is bigger than stack_2.\n";
    stack_2.push(41);
    if (stack_2 < stack_1)
        std::cout << "stack_1 is bigger than stack_2.\n";
    stack_2.pop();
    stack_2.push(40);
    if (stack_1 >= stack_2)
        std::cout << "stack_1 is equal to stack_2.\n";
}

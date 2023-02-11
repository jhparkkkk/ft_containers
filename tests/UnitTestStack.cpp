/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnitTestStack.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:15:48 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/11 13:29:12 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UnitTestStack.hpp"
#include <iostream>
#include <stdio.h>

void    unitTestComparisonOverload() {
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

void    unitTestStack() {
    std::cout << BOLDYELLOW;
    std::cout << "__________________________________________________________\n";
    std::cout << "\n                    📦 STACK UNIT TEST                   \n";
    std::cout << "__________________________________________________________";
    std::cout << RESET << "\n";
    
    std::cout << BOLDYELLOW << "\n🧪 Testing stack<int>.....................................\n" << RESET;
    UnitTestStack<int> stackInt;
    stackInt.unitTestMemberFunctions(10);
    std::cout << BOLDYELLOW << "🧪 Testing stack<std::string>.............................\n" << RESET;
    UnitTestStack<std::string> stackString;
    stackString.unitTestMemberFunctions("Hello!");
    std::cout << BOLDYELLOW << "🧪 Testing stack<float>...................................\n" << RESET;
    UnitTestStack<float> stackFloat;
    stackFloat.unitTestMemberFunctions(3.1415);

    std::cout << BOLDYELLOW << "\n🧪 Testing comparisons operators.......................\n" << RESET;
    unitTestComparisonOverload();

    stack<int> empty_stack;
    std::cout << empty_stack.size() << '\n';
    std::vector<int> my_vector(2, 200);
    std::cout << my_vector.size() << '\n';
    stack<int,std::vector<int> > fourth (my_vector);
    std::cout << fourth.size() << '\n';
}
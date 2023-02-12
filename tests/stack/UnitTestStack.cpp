/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnitTestStack.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:15:48 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/11 14:46:50 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UnitTestStack.hpp"
#include <iostream>
#include <stdio.h>
#include <time.h>
void    unitTestStack() {

    float startTime = (float)clock()/CLOCKS_PER_SEC;

    std::cout << BOLDYELLOW;
    std::cout << "__________________________________________________________\n";
    std::cout << "\n                    📦 STACK UNIT TEST                   \n";
    std::cout << "__________________________________________________________";
    std::cout << RESET << "\n";
    
    std::cout << BOLDYELLOW << "\n🧪 Testing stack constructor..............................\n" << RESET;
    testStackConstructors();

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
    testStackOperators();

    // float startTime = (float)clock()/CLOCKS_PER_SEC;

    /* Do work */

    float endTime = (float)clock()/CLOCKS_PER_SEC;

    float timeElapsed = endTime - startTime;
    std::cout << timeElapsed << std::endl;
}
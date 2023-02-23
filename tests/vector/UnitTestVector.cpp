/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnitTestVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:27:45 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/20 15:04:57 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RESET   "\033[0m"
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */

#include "./../include/UnitTestVector.hpp"
#include <iostream>
#include <stdio.h>
#include <time.h>

void    unitTestVector() {
    std::cout << BOLDBLUE;
    std::cout << "__________________________________________________________\n";
    std::cout << "\n                   📦 VECTOR UNIT TEST                   \n";
    std::cout << "__________________________________________________________";
    std::cout << RESET << "\n";
    
    // float startTime = (float)clock()/CLOCKS_PER_SEC;

    std::cout << BOLDBLUE << "\n🧪 Testing vector Constructors.............................\n" << RESET;   
    testVectorConstructors();
    std::cout << BOLDBLUE << "\n🧪 Testing vector Modifiers................................\n" << RESET;   
    testVectorModifiers();
    std::cout << BOLDBLUE << "\n🧪 Testing vector Capacity.................................\n" << RESET;   
    testVectorCapacity();
    // float endTime = (float)clock()/CLOCKS_PER_SEC;
    // float timeElapsed = endTime - startTime;
    // std::cout << timeElapsed << std::endl;
    

    // std::cout << BOLDYELLOW << "🧪 Testing stack<std::string>.............................\n" << RESET;
    // UnitTestStack<std::string> stackString;
    // stackString.unitTestMemberFunctions("Hello!");
    // std::cout << BOLDYELLOW << "🧪 Testing stack<float>...................................\n" << RESET;
    // UnitTestStack<float> stackFloat;
    // stackFloat.unitTestMemberFunctions(3.1415);

    // std::cout << BOLDYELLOW << "\n🧪 Testing comparisons operators.......................\n" << RESET;
    // testStackOperators();
}
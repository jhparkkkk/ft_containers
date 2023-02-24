/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnitTestStack.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:15:48 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/16 14:49:11 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/UnitTestStack.hpp"


void    unitTestStack() {


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
}

/*
----------------------------------- NOTES --------------------------------------
>>> Chrono :
    #include <time.h>
    float startTime = (float)clock()/CLOCKS_PER_SEC;
    
    * Do work *

    float endTime = (float)clock()/CLOCKS_PER_SEC;

    float timeElapsed = endTime - startTime;
    std::cout << timeElapsed << std::endl;

----------------------------------- ISSUES ------------------------------------

*/
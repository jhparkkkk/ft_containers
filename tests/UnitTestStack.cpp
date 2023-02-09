/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnitTestStack.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:15:48 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/09 15:21:05 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UnitTestStack.hpp"
#include <iostream>
#include <stdio.h>

UnitTestStack::UnitTestStack()
{
    std::cout << B_YELLOW << BOLDBLACK;
    std::cout << "                           STACK                            ";
    std::cout << RESET << "\n";

    TestPush();

}

UnitTestStack::~UnitTestStack() {
    std::cout << "UnitTestStack destructor\n";
}

void    UnitTestStack::TestPush() {
    // std::cout << YELLOW << "\nModsifiers : push()\n";
    std::cout << arr.size() << "\n";
    for (int i = 0; i<10; i++)
        this->arr.push(i*10);
    std::cout << arr.size() << "\n";
}


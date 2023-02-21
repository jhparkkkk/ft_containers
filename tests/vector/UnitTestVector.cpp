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
    
    std::cout << BOLDBLUE << "\n🧪 Testing vector constructor..............................\n" << RESET;   
    testVectorConstructors();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVectorConstructors.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:05:36 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/21 12:27:45 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/UnitTestVector.hpp"
#include <cassert>
#include <iostream>

void    testVectorConstructors() {
    std::cout << "test vector constructors\n";
    
    vector<int> empty_ctor;

    vector<int> fill_ctor(1, 10);

}
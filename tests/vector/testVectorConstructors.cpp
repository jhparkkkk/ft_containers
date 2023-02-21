/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVectorConstructors.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:05:36 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/21 14:27:02 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/UnitTestVector.hpp"
#include <cassert>
#include <iostream>

void    testVectorConstructors() {
    std::cout << "test vector constructors\n";
    
    vector<int> empty_ctor;
    assert (empty_ctor.size() == 0);
    std::cout << "size is: " << empty_ctor.size() << "\n";
    
    empty_ctor.push_back(1);
    std::cout << "empty_ctor front: " << empty_ctor.front() << "\n";
    
    // vector<int> fill_ctor(5, 10);
    // std::cout << "fill_ctor front: " << fill_ctor.front() << "\n";
    // std::cout << "fill_ctor back: " << fill_ctor.back() << "\n";


    

}
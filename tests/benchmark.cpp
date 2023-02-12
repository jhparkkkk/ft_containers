/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:52:59 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/12 16:24:07 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <stack>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stack>
#include "./../include/stack.hpp"
#include "benchmark.hpp"

Time::Time() {
    std::cout << "Testing Stack Performance\n";
    while (!std::cin.eof())
    {
        std::cout << "Enter number of operations: ";
        std::cin >> _input;
        std::istringstream(_input) >> _nbOperations;
        std::cout << "Enter number of iterations: ";
        std::cin >> _input;
        std::istringstream(_input) >> _nbIterations;
        break;
    }
}

Time::~Time() { std::cout << "Time desctructor\n"; }

void    Time::test()
{
    std::stack<int> std_container;
    ft::stack<int> ft_container;
    std::deque<int> mydeque;
    double stl_average_time = operate(std_container);
    double ft_average_time = operate(ft_container);
    // Affichez les résultats
    std::cout << "std::stack average executing time: " << stl_average_time << " microsecondes." << std::endl;
    std::cout << "ft::stack average executing time: " << ft_average_time << " microsecondes." << std::endl;

    std::cout << "FT container can be up to 20 times slower than STD container.";
    // Check if ft::stack execution time does not exceed 20 times std::stack's 
    if (ft_average_time > 20 * stl_average_time) {
        std::cout << "Le temps d'exécution de ft::stack dépasse 20 fois celui de std::stack." << std::endl;
    } else {
        std::cout << "Le temps d'exécution de ft::stack est inférieur ou égal à 20 fois celui de std::stack." << std::endl;
    }

    // if speedup > 1 then ft::stack is faster than std::stack
    // else ft::stack is slower than std::stack
    // the absolute number of speedup represents how many times ft::stack is slower or faster than std::stack.
    double speedup = (ft_average_time / stl_average_time);

    std::cout << "ft stack is " << speedup << " times slower than std";
}


int main() {
    Time stackBenchmark = Time();
    stackBenchmark.test();

    return 0;
}

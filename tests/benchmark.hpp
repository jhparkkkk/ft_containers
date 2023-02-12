/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:31:42 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/12 15:58:32 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ctime>
#include <stack>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "./../include/stack.hpp"

class Time {
    public:
        Time();
        ~Time();
        void test(); 
        template<class CONTAINER>
        double  operate(CONTAINER);

    private:
        std::string _input;
        int         _nbOperations;
        int         _nbIterations;
};

template  <class CONTAINER>
double    Time::operate(CONTAINER cntr)
{
    std::cout << "Time::operate\n";
    double total_time = 0;
    for (int j = 0; j < _nbIterations; ++j) {
        clock_t start_time = clock();
        for (int i = 0; i < _nbOperations; ++i) {
            cntr.push(i);
        }
        for (int i = 0; i < _nbOperations; ++i) {
            cntr.pop();
        }
        clock_t end_time = clock();
        total_time += static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
    }
    double average_time = total_time / _nbIterations;
    return average_time;
}
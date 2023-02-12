/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:16:07 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/10 16:38:32 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_containers headers */
#include "stack.hpp"

/* std_containers headers */
#include <vector>
#include <stack>

/* utils */
#include <iostream>
#include <chrono>

/* Unit Test for each container */
#include "./tests/stack/UnitTestStack.hpp"

/*  to compile two binaries : one with my own containers and one from STL
    in order to compare outputs
*/

#ifdef FT
	using namespace ft;
#else
	using namespace std;
#endif

int main()
{
    unitTestStack();

}
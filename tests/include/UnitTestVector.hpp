/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnitTestVector.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:26:58 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/20 15:06:29 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
/* ft_containers headers */
#include "./../../include/vector.hpp"

/* std_containers headers */
#include <vector>
#include <stack>

/* utils */
#include <iostream>

#ifdef FT
	using namespace ft;
#else
	using namespace std;
#endif


void    unitTestVector();
void    testVectorConstructors();
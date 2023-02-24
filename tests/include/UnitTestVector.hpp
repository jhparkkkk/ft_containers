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

#define RESET   "\033[0m"
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
/* ft_containers headers */
#include "./../../include/vector.hpp"

/* std_containers headers */
#include <vector>
#include <stack>
#include <type_traits>

/* utils */
#include <iostream>
#include <cassert>

#ifdef FT
	using namespace ft;
#else
	using namespace std;
#endif


void    unitTestVector();
void    testVectorConstructors();
void    testVectorModifiers();
void    testVectorCapacity();
void	testVectorElementAccess();
void	testVectorOperators();
void	testVectorIterator();
/*
----------------------------------- NOTES --------------------------------------
>>> Testing a container via a templated test class takes too long.
----------------------------------- ISSUES ------------------------------------
>>> Ctor and Dtor called twice when initiating UniTestVector class
	>>> Remove private member container : 
		private:
			vector<T> _c;
		> But why is this working with stack ? 

*/
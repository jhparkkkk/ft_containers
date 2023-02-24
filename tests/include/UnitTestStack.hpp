/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnitTestStack.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:18:16 by jeepark           #+#    #+#             */
/*   Updated: 2023/02/11 13:55:14 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define B_YELLOW    "\033[43m"

#define DEFAULT     "\033[49m"
#pragma once
/* ft_containers headers */
#include "./../../include/stack.hpp"

/* std_containers headers */
#include <vector>
#include <stack>

/* utils */
#include <iostream>
#include <assert> 

#ifdef FT
	using namespace ft;
#else
	using namespace std;
#endif

template <class T>
class UnitTestStack : public stack<T> {
    private:
        stack<T> _c;
    
    public:    
        UnitTestStack() : stack<T>() {}
        ~UnitTestStack() {};

    /*------------------------------- Capacity -------------------------------*/
        
        void    testEmpty() {
            std::cout << BOLDMAGENTA << "empty()\n" << RESET;
            if (this->_c.empty())
                std::cout << "This container is empty.\n";
            else
                std::cout << "This container is not empty.\n";
        }

        void    testSize() {
            std::cout << BOLDMAGENTA << "size()\n" << RESET;
            std::cout << "size is: " << this->_c.size() << "\n";
        }
    /*-------------------------- Elements Access -----------------------------*/
        
        void    testTop() {
            std::cout << BOLDMAGENTA << "top()\n" << RESET;
        try {
            if (this->_c.empty())
                throw ContainerIsEmpty();
            else
                std::cout << this->_c.top() << "\n";
        }
        catch(std::exception & e) {
        std::cout << "Cannot read top element: " << e.what() << "\n";
        }
        }

    /*------------------------------- Modifiers -------------------------------*/

        void    testPush(const T& item, const unsigned int count) {
            std::cout << BOLDMAGENTA << "push()\n" << RESET;
            for (unsigned int i = 0; i<count; i++)
            {
                this->_c.push(item);
                std::cout << "Element no." << i << " pushed.\n";
            }
        }
        
        void    testPop() {
            std::cout << BOLDMAGENTA << "pop()\n" << RESET;
                while (!this->_c.empty()) {
                    this->_c.pop();
                    std::cout << "Popping element...\n";
                }
        }

        stack<T>    getContainer() const { return _c; }
        
    /*------------------------------ Exceptions ------------------------------*/
        class   ContainerIsEmpty : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Container is empty."; }
        };

        void    unitTestMemberFunctions(const T& item) {
            std::cout << "\n👀  Capacity______________________________________________\n";
            testEmpty();
            testSize();
            std::cout << "\n👀  Elements Access_______________________________________\n";
            testTop();
            testPush(item, 1);
            testTop();
            std::cout << "\n👀  Modifiers_____________________________________________\n";
            testPush(item, 10);
            testEmpty();
            testTop();
            testPop();
            testSize();
            testEmpty();
            
        }
};

void    unitTestStack();
void    testStackConstructors();
void    testStackOperators();

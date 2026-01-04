/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:54:26 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/04 18:54:28 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

#include "MutantStack.hpp"

/**
 * @brief Main function to demonstrate the MutantStack class operations.
 *
 * This function showcases the use of MutantStack, including pushing and popping elements, 
 * forward and reverse iteration, and copying a MutantStack to a standard stack.
 */
int main() {
    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(30);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

	// Forward iteration
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "Forward iteration:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    // Reverse iteration
    MutantStack<int>::reverse_iterator  rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator  rite = mstack.rend();
    ++rit;
    --rit;
    std::cout << "Reverse iteration:" << std::endl;
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }

    // Stack creation with mstack object
    std::cout << "stack creation:" << std::endl;
    std::stack<int> s(mstack);
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;

    /**
     * The following block of code is commented out but demonstrates 
     * similar operations using a std::list instead of a MutantStack.
     * This can be used to compare the behavior of std::list with MutantStack.
     */
    /* std::cout << "\nlist tests:" << std::endl;
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(30);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

	// Forward iteration
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    ++lit;
    --lit;
    std::cout << "Forward iteration:" << std::endl;
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }

    // Reverse iteration
    std::list<int>::reverse_iterator  lrit = lst.rbegin();
    std::list<int>::reverse_iterator  lrite = lst.rend();
    ++lrit;
    --lrit;
    std::cout << "Reverse iteration:" << std::endl;
    while (lrit != lrite) {
        std::cout << *lrit << std::endl;
        ++lrit;
    } */
    return 0;
}

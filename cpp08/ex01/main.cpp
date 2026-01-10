/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:57:12 by jde-orma          #+#    #+#             */
/*   Updated: 2026/01/10 18:29:38 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <ctime>
#include <cstdlib>
#define SIZE 10000

void testSpan(int capacity) {
    try {
        Span sp(capacity);
        for (int i = 0; i < capacity; ++i)
            sp.addNumber(rand() % capacity);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Intentar agregar un número extra (debe lanzar excepción)
        sp.addNumber(99);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void testSequence(int capacity) {
    try {
        Span sp(capacity);
        std::vector<int> v;
        v.reserve(capacity);
        srand(time(0));
        for (int i = 0; i < capacity; ++i)
            v.push_back(rand() % capacity);

        sp.addSequence(v.begin(), v.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {
    srand(time(0));
    testSpan(5);
    testSpan(1);
    testSequence(SIZE);
    return 0;
}
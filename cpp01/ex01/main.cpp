/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:29:30 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/19 21:29:30 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static std::string  *generate_horde_name(int size); 

int	main(void) 
{
    const int hordeCount = 2;
    const int hordeSize = 3;
    std::string* hordeNames;
    Zombie* horde[hordeCount];
    
    hordeNames = generate_horde_name(hordeCount);

    std::cout << std::endl;
    std::cout << "Calling zombieHorde()..." << std::endl;

    for (int i = 0; i < hordeCount; i++)
        horde[i] = zombieHorde(hordeSize, hordeNames[i]);

    std::cout << "zombieHorde() finished." << std::endl;
    std::cout << std::endl;
    std::cout << "Calling announce() on hordes..." << std::endl;
    
    for (int i = 0; i < hordeCount; i++)
        for (int j = 0; j < hordeSize; j++)
            horde[i][j].announce();

    std::cout << "announce() finished." << std::endl;
	std::cout << std::endl;
    std::cout << "Deleting the hordes..." << std::endl;

    for (int i = 0; i < hordeCount; i++)
        delete[] horde[i];

    std::cout << "Hordes deleted." << std::endl;
	std::cout << std::endl;
    delete[] hordeNames;
    return (0);
}

static std::string  *generate_horde_name(int size)
{
    const int numNames = 26;
    // Creating a zombie horde   
    std::string zombieNames[] = {
        "Paule", "Elene", "Nikole", "Libe", "Mari", "Erensuge", "Urtzi", 
        "Lamia", "Basajaun", "Gentila", "Jauntxo", "Santxo", "Don Diego", "Doña Casilda", 
        "Eneko", "Fortun", "Eudon", "Jon Ander", "Xabier", "Asier", 
        "Andoni", "Arrate", "Fortun", "Santxa", "Lourdes", "Idoia"
    };
    std::string *hordeNames = new std::string[size];
    int char_count = 0;

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    // Select and print the randomly chosen names
    std::cout << std::endl << "Creating the horde of Basque Zombies: ";
    for (int i = 0; i < size; i++) {
        
        int randomIndex = std::rand() % numNames;
        hordeNames[i] = zombieNames[randomIndex];
        std::cout << GREEN << hordeNames[i] << DEF_COLOR;
        char_count += hordeNames[i].size();
        if (i < size - 1) {
            std::cout << ", ";
            char_count += 2;
        }
        else
            std::cout << std::endl;
    }
    std::cout << "----------------------------";
    for (int i = 0; i < char_count; i++)
        std::cout << "-";
    std::cout << std::endl;
    return (hordeNames);
}
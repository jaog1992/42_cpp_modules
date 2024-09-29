/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dog1de-orma <dog1de-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:22:52 by dog1de-orma          #+#    #+#             */
/*   Updated: 2024/09/17 19:22:52 by dog1de-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// Color codes
const std::string RESET = "\033[0m";
const std::string GREEN = "\033[32m";

int	main(void)
{
	std::cout << std::endl << GREEN << "Creating Animal class:" << RESET << std::endl << std::endl;
	/* You can only call methods that are declared as const. These objects are inmutable! */
	const	Animal* meta = new Animal();
	const	Animal* dog1 = new Dog();
	const	Animal* cat1 = new Cat();
	
	std::cout << std::endl << GREEN << "Testing Animal class:" << RESET << std::endl << std::endl;
	std::cout << "Animal of type " << dog1->getType() << " created" << std::endl;
	std::cout << "Animal of type " << cat1->getType() << " created" << std::endl;
	cat1->makeSound(); //will output the cat sound!
	dog1->makeSound(); //will output the dog sound!
	meta->makeSound();

	std::cout << std::endl << GREEN << "Cleaning Animal objects:" << RESET << std::endl << std::endl;
	delete meta;
	delete dog1;
	delete cat1;

	std::cout << std::endl << GREEN << "Creating WrongAnimal class:" << RESET << std::endl << std::endl;
	const	WrongAnimal* gama = new WrongAnimal();
	const	WrongAnimal* cat2 = new WrongCat();

	std::cout << std::endl << GREEN << "Testing WrongAnimal class:" << RESET << std::endl << std::endl;
	std::cout << "Animal of type " << cat2->getType() << " created" << std::endl;
	cat2->makeSound(); //will output the wrong cat sound!
	gama->makeSound();

	std::cout << std::endl << GREEN << "Cleaning WrongAnimal objects:" << RESET << std::endl << std::endl;

	delete cat2;
	delete gama;
	return (0);
}

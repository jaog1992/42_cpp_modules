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

// Color codes
const std::string RESET = "\033[0m";
const std::string GREEN = "\033[32m";

int	main(void)
{
	std::cout << std::endl << GREEN << "-------- Create Dog --------" << RESET << std::endl << std::endl;
	const Animal* dog1 = new Dog();

	std::cout << std::endl << GREEN << "-------- Create Cat --------" << RESET << std::endl << std::endl;
	const Animal* cat1 = new Cat();

	std::cout << std::endl << GREEN << "-------- Make Sounds --------" << RESET << std::endl << std::endl;
	dog1->makeSound();
	cat1->makeSound();

	std::cout << std::endl << GREEN << "-------- Create copies --------" << RESET << std::endl << std::endl;
	Animal* copy_dog = new Dog(*((Dog*)dog1)); /* We cast to dog as the compiler only knows the pointer to Animal */
											   /* The we dereference the pointer to obtain a reference to the dog object*/
	Animal* copy_cat = new Cat(*((Cat*)cat1));

	std::cout << std::endl << GREEN << "-------- Delete Copies --------" << RESET << std::endl << std::endl;
	delete copy_dog;
	delete copy_cat;
	
	std::cout << std::endl << GREEN << "-------- Assign Operator (Shallow) --------" << RESET << std::endl << std::endl;
	// assignation operator
	copy_dog = (Dog*)dog1;
	copy_cat = (Cat*)cat1;	
	copy_dog->makeSound();
	copy_cat->makeSound();
	
	std::cout << std::endl << GREEN << "-------- Delete Dog --------" << RESET << std::endl << std::endl;
	delete dog1; //should not create a leak
	
	std::cout << std::endl << GREEN << "-------- Delete Cat --------" << RESET << std::endl << std::endl;
	delete cat1; //should not create a leak
	
	return (0);
}

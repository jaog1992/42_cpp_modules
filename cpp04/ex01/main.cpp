/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:22:52 by jde-orma          #+#    #+#             */
/*   Updated: 2024/09/17 19:22:52 by jde-orma         ###   ########.fr       */
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
											   /* Then we dereference the pointer to obtain a reference to the dog object*/
	Animal* copy_cat = new Cat(*((Cat*)cat1));

	std::cout << std::endl << GREEN << "-------- Delete Copies --------" << RESET << std::endl << std::endl;
	delete copy_dog;
	delete copy_cat;
	/* These pointers now point to deallocated memory. 
	   Let's assign them to nullptr to avoid undefined behavior if accessed again. */
	copy_dog = nullptr;
	copy_cat = nullptr;

	std::cout << std::endl << GREEN << "-------- Assign Operator (Shallow) --------" << RESET << std::endl << std::endl;
	/* Assignment operator: This creates a shallow copy by reassigning the pointers to dog1 and cat1.
	   The previously allocated memory for copy_dog and copy_cat was freed, so no additional memory is allocated here. */

	copy_dog = (Dog*)dog1;
	copy_cat = (Cat*)cat1;	
	copy_dog->makeSound();
	copy_cat->makeSound();
	
	std::cout << std::endl << GREEN << "-------- Delete Dog --------" << RESET << std::endl << std::endl;
	delete dog1; //Should not create a leak
	
	std::cout << std::endl << GREEN << "-------- Delete Cat --------" << RESET << std::endl << std::endl;
	delete cat1; //Should not create a leak
	
	/* If Animal's destructor is not virtual, when deleting an object through a pointer to Animal, 
	   only Animal's destructor would be called, causing a memory leak because the derived class
	   destructors (Dog, Cat) wouldn't be called, and resources like Brain wouldn't be deallocated.
	   Using a virtual destructor ensures that the correct destructor for the actual object type 
	   (Dog or Cat) is invoked, preventing resource leaks. */

	return (0);
}

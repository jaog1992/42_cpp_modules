/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:37:33 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/19 22:37:33 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

// Colors
# define GREEN            "\001\e[0;92m\002"
# define BLUE             "\001\e[0;94m\002"
# define DEF_COLOR        "\001\e[0;39m\002"

/* A reference acts as an alias for the referenced variable, allowing direct access 
to the original variable. It cannot hold a null value or change to refer to another 
variable once initialized. Using references in function arguments is generally 
more efficient for large objects, as it avoids unnecessary copies. C does not 
implement references; instead, pointers are used to achieve similar functionality.*/
int	main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

	// Title
	std::cout << std::endl;
	std::cout << ">Test: Demistifying references>>" << std::endl;
	std::cout << std::endl;

	// Variables
	std::cout << "str = \"" << GREEN << str << "\"" << DEF_COLOR << std::endl;
	std::cout << "std::string* stringPTR = " << GREEN << "&str" << DEF_COLOR << std::endl;
	std::cout << "std::string& stringREF = " << GREEN << "str" << DEF_COLOR << std::endl;
	std::cout << std::endl;
	
    std::cout << "Memory address of the string variable: " << BLUE << &str << DEF_COLOR << std::endl;
    std::cout << "Memory address held by stringPTR: " << BLUE << stringPTR << DEF_COLOR << std::endl;
    std::cout << "Memory address held by stringREF: " << BLUE << &stringREF << DEF_COLOR << std::endl;
	std::cout << std::endl;

    std::cout << "Value of the string variable: " << BLUE << str << DEF_COLOR << std::endl;
    std::cout << "Value pointed to by stringPTR: " << BLUE << *stringPTR << DEF_COLOR << std::endl;
    std::cout << "Value pointed to by stringREF: " << BLUE << stringREF << DEF_COLOR << std::endl;
	std::cout << std::endl;

    return EXIT_SUCCESS;
}
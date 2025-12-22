/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:19:37 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/22 15:19:39 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "utils.hpp"

int	main( void ) {
	std::srand(std::time(NULL));
	Base *p = generate();

	identify(p);
	identify(*p);
	delete p;
	return 0;
}
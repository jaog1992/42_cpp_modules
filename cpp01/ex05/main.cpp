/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:50:12 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/22 20:50:12 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() 
{
    Harl harl;

    std::string harl_line_levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "INVALID"};
    std::string corrector_lines[5] = 
    {
        "OK. Show me a DEBUG level comment.",
        "Good enough. Now show me an INFO level one",
        "Nice! How about a WARNING?",
        "Brilliant! Last but not least: An ERROR comment",
        "mmm okey Harl...what if I ask you to prove the behaviour of an INVALID level?"   
    };
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << "[CORRECTOR] " << corrector_lines[i] << std::endl;
        std::cout << std::endl;
        std::cout << "[HARL] ";
        harl.complain(harl_line_levels[i]);
        std::cout << std::endl;
    }

    return (EXIT_SUCCESS);
}



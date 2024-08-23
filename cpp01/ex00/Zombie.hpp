/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:14:49 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/19 21:14:49 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

// Colors
# define RED              "\001\e[0;91m\002"
# define GREEN            "\001\e[0;92m\002"
# define BLUE             "\001\e[0;94m\002"
# define DEF_COLOR        "\001\e[0;39m\002"

class Zombie
{
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void              announce();
        void              setName(std::string name);
        const std::string getName(void);

    private:
        std::string _name;
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif
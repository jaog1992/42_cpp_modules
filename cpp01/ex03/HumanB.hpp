/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:23:37 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/21 22:23:37 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB();
        void        attack();
        void	    setWeapon(Weapon &weapon);

    private:
        std::string _name;
        Weapon      *_weapon;
};

#endif
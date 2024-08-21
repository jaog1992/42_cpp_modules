/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:15:58 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/21 22:15:58 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void        attack();

    private:
        std::string _name;
        Weapon      &_weapon;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:08:01 by jde-orma          #+#    #+#             */
/*   Updated: 2024/08/21 22:08:01 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
    public:
        Weapon(std::string type);
        ~Weapon();
        const std::string &getType() const;
        void        setType(std::string type);

    private:
        std::string _type;
};

#endif
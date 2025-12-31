/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:19:06 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/31 11:52:13 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/**
 * @brief Virtual destructor for Base.
 *
 * Ensures derived-class destructors are called when deleting through a
 * `Base*`. The function is intentionally empty as there is no base-class state
 * to clean up.
 */
Base::~Base( void ) {
}
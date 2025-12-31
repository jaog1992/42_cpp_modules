/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:18:08 by jde-orma          #+#    #+#             */
/*   Updated: 2025/12/31 11:52:07 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H

# define DATA_H

# include <stddef.h>

typedef struct s_data {
	/**
	 * @brief Simple POD structure used for serializer exercises.
	 *
	 * Contains a small set of fields to demonstrate pointer/integer conversion
	 * via reinterpret casts.
	 */
	int	i;
	size_t	len;
	char	c;
}	Data;

#endif
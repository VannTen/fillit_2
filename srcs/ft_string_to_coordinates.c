/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_to_coordinates.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 12:18:39 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/23 13:50:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_relative_position.h"

t_rel_position	*ft_string_to_coordinates(char *str)
{
	char	**tab_lines;

	tab_lines = ft_strsplit(str, '\n');
	return (ft_relative_positions(tab_lines));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_to_coordinates.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 12:18:39 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/23 16:20:58 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_relative_position.h"

t_rel_position	*ft_string_to_coordinates(char *str)
{
	char			**tab_lines;
	t_rel_position	*rel_positions;

	tab_lines = ft_strsplit(str, '\n');
	rel_positions = ft_relative_positions(tab_lines);
	ft_free_string_array(&tab_lines);
	return (rel_positions);
}

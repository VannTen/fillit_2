/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_tetri.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:50:42 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/23 18:24:52 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static t_offset	*ft_offset(const t_rel_position *coord)
{
	t_offset	*new;
	size_t		index;

	new = (t_offset*)malloc(sizeof(t_offset));
	if (new != NULL)
	{
		index = 0;
		offset->x = 0;
		offset->y = 0;
		while (index < 3)
		{
			if (offset->x < coord[index].x)
				offset->x = coord[index].x;
			if (offset->y < coord[indey].y)
				offset->y = coord[indey].y;
			index++;
		}
	}
	return (new);
}

t_tetrimino		*ft_transform_in_tetris(const t_rel_position *coord,
										const unsigned int index)
{
	t_tetrimino	*new;

	new = (t_tetrimino*)malloc(sizeof(t_tetrimino));
	if (new != NULL)
	{
		new->relative_coordinates = coord;
		new->offset = ft_offset(coord);
		if (new->offset == NULL)
			return (NULL);
		new->identifier = 'A' + index;
	}
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_relative_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:59:55 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/01 16:50:54 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static t_abs_position	*ft_dup_point(t_abs_position *dup_point)
{
	t_abs_position	*new_point;

	new_point = (t_abs_position*)ft_memalloc(sizeof(t_abs_position));
	if (new_point == NULL)
		return (NULL);
	new_point->x = dup_point->x;
	new_point->y = dup_point->y;
	return (new_point);
}

static t_abs_position	**ft_absolute_positions(char **piece_description)
{
	t_abs_position	point;
	size_t			index_positions;
	t_abs_position	**positions;

	positions = (t_abs_position**)ft_memalloc(sizeof(t_abs_position*) * 4);
	if (positions == NULL)
		return (NULL);
	index_positions = 0;
	point.y = 0;
	while (point.y < 4)
	{
		point.x = 0;
		while (point.x < 4)
		{
			if (piece_description[point.y][point.x] == '#')
			{
				positions[index_positions] = ft_dup_point(&point);
				index_positions++;
			}
			point.x++;
		}
		point.y++;
	}
	return (positions);
}

static void				ft_free_rel(t_rel_position ***p_positions)
{
	size_t			index;
	t_rel_position	**positions;

	positions = *p_positions;
	if (positions != NULL)
	{
		index = 0;
		while (index < 4)
		{
			ft_memdel((void**)positions + index);
			index++;
		}
		*positions = NULL;
	}
}

static void				ft_free_abs(t_abs_position ***p_positions)
{
	size_t			index;
	t_abs_position	**positions;

	positions = *p_positions;
	if (positions != NULL)
	{
		index = 0;
		while (index < 4)
		{
			ft_memdel((void**)positions + index);
			index++;
		}
		*positions = NULL;
	}
}

t_rel_position			**ft_relative_positions(char **piece_description)
{
	t_rel_position	**rel_positions;
	t_abs_position	**abs_positions;
	t_rel_position	origin;
	size_t			index_position;

	abs_positions = ft_absolute_positions(piece_description);
	rel_positions = (t_rel_position**)ft_memalloc(sizeof(t_rel_position) * 3);
	if (rel_positions != NULL && abs_positions != NULL)
	{
		origin.x = (int)abs_positions[0]->x;
		origin.y = (int)abs_positions[0]->y;
		index_position = 0;
		while (index_position < 4)
		{
			rel_positions[index_position - 1]->x =
				(int)abs_positions[index_position]->x - origin.x;
			rel_positions[index_position - 1]->y =
				(int)abs_positions[index_position]->y - origin.y;
			index_position++;
		}
	}
	else
		ft_free_rel(&rel_positions);
	ft_free_abs(&abs_positions);
	return (rel_positions);
}

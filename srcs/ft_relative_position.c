/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_relative_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:59:55 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/01 17:26:37 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** ft_dup_point
**
** Duplicate (copy is allocated) a t_abs_position struct
** It is initialized to 0 by ft_memalloc.
*/

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

/*
** ft_absolute_positions
**
** Parse the two-dimensions array given as an entry to find 4 '#'.
** Return their absolutes positions (considering array[0][0] as the origin)
** inside an array of pointers of struct (t_abs_position)
*/

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

/*
** ft_free_rel, ft_free_abs
**
** These two functions (they are basically the same, except the type of
** the argument) free the struct array which are allocated in the functions
** ft_absolute_positions and ft_relative_positions.
**
** ft_free_abs will always be used at the end of ft_relative_positions, since
** the absolute positions are not needed afterwards ; this is to prevent any
** memory leaks.
** On the other hand, ft_free_rel will only be used if there is an allocation
** error : that will lead to properly exit the programm, and so freeing any
** allocated memory.
*/

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

/*
** ft_relative_positions
**
** This function is the entry and exit points for that file (others function
** are static)
** It computes three positions (t_rel_position) relative to the first '#'
** of a tetriminos (the first being defined as the highest and leftmost one)
**
** The return value is the address of a struct array containing those, or NULL
** if an error occured (allocation error)
*/

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

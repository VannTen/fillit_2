/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_placable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <chbechet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:45:38 by chbechet          #+#    #+#             */
/*   Updated: 2017/01/08 16:13:20 by chbechet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include "solve_array.h"

/*
** This function test if we place piece it's not overlap the other piece.
*/

t_bool	ft_is_not_overlap(char **tab, int x, int y, t_tetrimino *piece)
{
	unsigned int	index;
	t_rel_position	*coord;

	index = 0;
	if (tab[x][y] != '\0')
		return (FALSE);
	coord = piece->relative_coordinates;
	while (index < 3)
	{
		if (tab[x + coord->x][y + coord->y] != '\0')
			return (FALSE);
		coord++;
		index++;
	}
	return (TRUE);
}

/*
** This function test when we place piece it does not exceed bounds of array.
*/

t_bool	ft_out_of_bound(int size_tab, int y, int x, t_tetrimino *piece)
{
	t_offset	*offset;

	offset = piece->offset;
	if (!(offset->x + x < size_tab))
		return (FALSE);
	if (!(offset->y + y < size_tab))
		return (FALSE);
	if (!(offset->minus_x + x >= 0))
		return (FALSE);
	return (TRUE);
}

/*
** This function use the function on the top for make sure the piece is
** placable in the array.
*/

t_bool	ft_is_placable(t_resolution *array, int x, int y, t_tetrimino *piece)
{
	return (ft_is_not_overlap(array->tab, x, y, piece) &&
			ft_out_of_bound(array->size_tab, x, y, piece));
}

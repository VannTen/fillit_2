/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_placable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <chbechet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:45:38 by chbechet          #+#    #+#             */
/*   Updated: 2017/01/06 22:03:19 by chbechet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function test if we place piece she's not overlap other piece.
*/

t_bool	ft_is_not_overlap(char **tab, int x, int y, t_tetrimino *piece)
{
	unsigned int	index;
	t_rel_position	*coord;

	index = 0;
	if (tab[x][y] != '\0')
		return (FALSE);
	coord = piece->relative_coordinates;
	while (i < 3)
	{
		if (tab[x + coord->x][y + coord->y] != '\0')
			return (FALSE);
		coord++;
		i++;
	}
	return (TRUE);
}

/*
** This function test when we place piece she do not exceed bounds of array.
*/

t_bool	ft_out_of_bound(char **tab,int y, int x, t_tetrimino *piece, unsigned int size_tab)
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
** This function use the function on the top fore make sure the piece is 
** placable in the array.
*/

t_bool	ft_is_placable(char **tab, t_tetrimino *piece, int x, int y)
{
	return(ft_is_not_overlap(param) && ft_out_of_bound(param));
}

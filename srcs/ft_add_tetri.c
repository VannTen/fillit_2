/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:09:47 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/12 17:10:05 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve_array.h"
#include "fillit.h"

void	ft_add_tetri(char **tab, int x, int y, t_tetrimino *piece)
{
	unsigned int	index;
	t_rel_position	*coord;
	char			identifier;

	identifier = piece->identifier;
	tab[x][y] = identifier;
	coord = piece->relative_coordinates;
	index = 0;
	while (index < 3)
	{
		tab[y + coord[index].y][x + coord[index].x] = identifier;
		index++;
	}
}

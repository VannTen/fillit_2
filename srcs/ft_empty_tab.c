/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <chbechet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:33:14 by chbechet          #+#    #+#             */
/*   Updated: 2017/01/05 19:19:12 by chbechet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_empty_tab(char **tab, int x, int y, t_tetrimino *piece)
{
	unsigned int	index;
	t_rel_position	*coord;

	index = 0;
	tab[x][y] = '\0';
	coord = piece->relative_coordinates;
	while (i < 3)
	{
		tab[x + coord->x][y + coord->y] = '\0';
		coord++;
		i++;
	}
}

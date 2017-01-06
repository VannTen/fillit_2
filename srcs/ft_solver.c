/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:09:11 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/06 19:06:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_solver(const t_lst *tetris_lst)
{
	unsigned int	tab_side;
	char			**solve_tab;

	tab_side = ft_calculate_array_size(tetris_lst);
	solve_tab = ft_generate_square(tab_side);
	while (!ft_try_every_position(solve_tab, tetris_lst))
	{
		ft_destroy_tab(&solve_tab, tab_side);
		tab_side++;
		solve_tab = ft_generate_tab(tab_side);
	}
	return (solve_tab);
}

t_bool	ft_try_every_position(char **solve_tab, t_lst *tetris_lst)
{
	size_t	index_x;
	size_t	index_y;

	index_x = 0;
	index_y = 0;
	while (index_y < tab->max_y)
	{
		if (ft_try_piece(solve_tab, index_x, index_y, tetris_lst))
			return (TRUE);
		if (index_x < tab->max_x)
		{
			index_x = 0;
			index_y++;
		}
		else
			index_x++;
	}
	return (FALSE);
}

t_bool	ft_try_piece(char *tab_struct,int x, int y, t_lst *tetri)
{
	if (!ft_is_placable(tetri))
		return (FALSE);
	ft_place(tab, tetri);
	return (ft_try_every_position(tetri->next));
}

char	**ft_generate_square(unsigned int side_length)
{
	char			**square;
	unsigned int	index_1;
	unsigned int	index_2;

	index_1 = 0;
	square = (char**)malloc(sizeof(char*) * size);
	while (index_1 < side_length)
	{
		square[index_1] = ft_strnew(size);
		if (square[index_1] == NULL)
			return (ft_free_string_array(square));
		index_1++;
	}
	return (square);
}

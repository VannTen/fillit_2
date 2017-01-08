/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:09:11 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/08 16:19:04 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "solve_array.h"
#include "libft.h"
#include <stdlib.h>

static t_bool	ft_try_every_position(t_resolution *array,
										const t_lst *tetris_lst)
{
	int	index_x;
	int	index_y;

	index_x = 0;
	index_y = 0;
	while (index_y < array->size_tab)
	{
		if (ft_try_piece(array, index_x, index_y, tetris_lst))
			return (TRUE);
		ft_empty_tab(array->tab, index_x, index_y,
					(t_tetrimino*)tetris_lst->content);
		if (index_x < array->size_tab)
		{
			index_x = 0;
			index_y++;
		}
		else
			index_x++;
	}
	return (FALSE);
}

static t_bool	ft_try_piece(t_resolution *array, int x, int y,
								const t_lst *tetri)
{
	if (!ft_is_placable(array, x, y, (t_tetrimino*)tetri->content))
		return (FALSE);
	ft_add_tetri(array, x, y, (t_tetrimino*)tetri->content);
	return (ft_try_every_position(array, tetri->next));
}

char			**ft_solver(const t_lst *tetris_lst)
{
	t_resolution	*solve_tab;

	solve_tab = ft_generate_struct_resolve(tetris_lst);
	while (!ft_try_every_position(solve_tab, tetris_lst))
	{
		ft_free_string_array(&solve_tab->tab);
		solve_tab->size_tab++;
		solve_tab->tab = ft_generate_square(solve_tab->size_tab);
	}
	return (solve_tab->tab);
}

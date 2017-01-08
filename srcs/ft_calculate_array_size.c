/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_array_size.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:37:45 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/08 12:03:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve_array.h"
#include "libft.h"

static size_t	ft_calculate_array_size(const t_lst *tetris_lst)
{
	size_t	number_of_pieces;
	size_t	min_side;

	number_of_pieces = f_lst_len(tetris_lst);
	min_side = ft_int_square_root(number_of_pieces * 4) + 1;
	return (min_side);
}

char			**ft_generate_square(size_t side_length)
{
	char	**square;
	size_t	index;

	index = 0;
	square = (char**)malloc(sizeof(char*) * side_length + 1);
	while (index < side_length)
	{
		square[index] = ft_strnew(side_length);
		if (square[index] == NULL)
			return (ft_free_string_array(&square));
		index++;
	}
	square[index] = NULL;
	return (square);
}

t_resolution	*ft_generate_struct_resolve(const t_lst *tetris_lst)
{
	t_resolution	*resolve;

	resolve = (t_resolution*)malloc(sizeof(t_resolution));
	if (resolve != NULL)
	{
		resolve->size_tab = ft_calculate_array_size(tetris_lst);
		resolve->tab = ft_generate_square(resolve->size_tab);
		if (resolve->tab == NULL)
		{
			free(resolve);
			resolve = NULL;
		}
	}
	return (resolve);
}

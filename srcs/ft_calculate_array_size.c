/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_array_size.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:37:45 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/28 15:32:58 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_calculate_min_square_possible(t_lst *tetris_lst)
{
	unsigned int	number_of_pieces;
	unsigned int	min_side;

	number_of_pieces = f_lst_len(tetris_lst);
	min_side = ft_int_square_root(number_of_pieces) + 1;
	return (min_side);
}

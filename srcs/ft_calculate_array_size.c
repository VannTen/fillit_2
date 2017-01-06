/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_array_size.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:37:45 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/05 17:35:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_calculate_array_size(const t_lst *tetris_lst)
{
	unsigned int	number_of_pieces;
	unsigned int	min_side;

	number_of_pieces = f_lst_len(tetris_lst);
	min_side = ft_int_square_root(number_of_pieces * 4) + 1;
	return (min_side);
}

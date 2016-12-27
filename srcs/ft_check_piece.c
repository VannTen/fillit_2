/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <chbechet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:28:01 by chbechet          #+#    #+#             */
/*   Updated: 2016/12/27 14:57:15 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_check_count(const char *piece)
{
	unsigned int index;
	unsigned int count_touch;

	index = 0;
	count_touch = 0;
	while (piece[index])
	{
		if (piece[index] == '#')
		{
			if (index + 1 <= 20 && piece[index + 1] == '#')
				count_touch++;
			if (index + 5 <= 20 && piece[index + 5] == '#')
				count_touch++;
			if (index >= 1 && piece[index - 1] == '#')
				count_touch++;
			if (index >= 5 && piece[index - 5] == '#')
				count_touch++;
		}
		index++;
	}
	return (count_touch);
}

t_bool			ft_check_piece(const char *piece)
{
	unsigned int touch;

	touch = ft_check_count(piece);
	if (touch == 6 || touch == 8)
		return (TRUE);
	else
		return (FALSE);
}

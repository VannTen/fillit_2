/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <chbechet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:28:01 by chbechet          #+#    #+#             */
/*   Updated: 2016/12/27 14:35:21 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_check_count(const char *piece)
{
	unsigned int index;
	unsigned int count_touch;

	index = 0;
	count_touch = 0;
	while (piece[index])
	{
		while (piece[index] == '#')
		{
			if (index + 1 <= 20 && piece[index + 1] == '#')
				count_touch++;
			if (index + 5 <= 20 && piece[index + 5] == '#')
				count_touch++;
			if (index - 1 >= 0 && piece[index - 1] == '#')
				count_touch++;
			if (index - 5 >= 0 && piece[index - 5] == '#')
				count_touch++;
			index++;
		}
		index++;
	}
	index++;
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

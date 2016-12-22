/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 17:54:51 by chbechet          #+#    #+#             */
/*   Updated: 2016/12/22 18:55:54 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_valid_count(const char *piece)
{
	unsigned int		point;
	unsigned int		dieze;
	unsigned int		back_n;
	unsigned int		index;

	index = 0;
	dieze = 0;
	back_n = 0;
	point = 0;
	while (piece[index] != '\0')
	{
		if (piece[index] == '.')
			point++;
		else if (piece[index] == '#')
			dieze++;
		else if (piece[index] == '\n')
			back_n++;
		index++;
	}
	if (point == 12 && dieze == 4 && back_n == 4)
		return (TRUE);
	else
		return (FALSE);
}

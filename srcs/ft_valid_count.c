/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 17:54:51 by chbechet          #+#    #+#             */
/*   Updated: 2016/12/21 11:25:42 by chbechet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_valid_count(char **piece)
{
	int		point;
	int		dieze;
	int		back_n;
	int		index;

	index = 0;
	dieze = 0;
	back_n = 0;
	point = 0;
	while (piece[index])
	{
		if (index == '.')
			point++;
		else if (index == '#')
			dieze++;
		else if (index == '\n')
			back_n++;
		index++;
	}
	if (point == 12 && dieze == 4 && back_n == 4)
		return (TRUE);
	else
		return (FALSE);
}

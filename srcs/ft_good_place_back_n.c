/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_good_place_back_n.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:20:18 by chbechet          #+#    #+#             */
/*   Updated: 2016/12/21 17:08:55 by chbechet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_good_place_back_n(char *piece)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (piece[index])
	{
		while (piece[index] != '\n')
		{
			index++;
			count++;
		}
		if (piece[index] == '\n' && count != 4)
			return (FALSE);
		else
		{
			count = 0;
			index++;
		}
	}
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_pieces_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:42:02 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/23 11:47:58 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool		ft_good_place_back_n(const char *piece)
{
	unsigned int	index;
	unsigned int	count;

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

static t_bool		ft_valid_count(const char *piece)
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

t_bool				ft_valid_pieces_format(const t_lst *link)
{
	char *piece;

	piece = (char*)link->content;
	return (ft_valid_count(piece) && ft_good_place_back_n(piece));
}

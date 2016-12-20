/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 17:54:51 by chbechet          #+#    #+#             */
/*   Updated: 2016/12/20 21:45:52 by chbechet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bool		ft_valid_count(char **piece)
{
	int		point;
	int		dieze;
	int		back_n;
	int		index;

	index = 0;
	while (piece[index])
	{
		if (index == '.')
			point++;
		if (index == '#')
			dieze++;
		if (index == '\n')
			back_n++;
		if (point == 12 && dieze == 4 && back_n == 4)
			return (TRUE);
		else
			return (FALSE);
	}
}

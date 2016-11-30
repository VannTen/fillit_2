/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:42:43 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/16 19:25:08 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** If both s and f are valid (not NULL), perform f on every character of f until
** the null character. The index is given as an additional parameter.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	if (s != NULL && f != NULL)
	{
		index = 0;
		while (s[index] != '\0')
		{
			f(index, s + index);
			index++;
		}
	}
}

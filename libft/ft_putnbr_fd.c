/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:24:24 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/16 18:54:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The recursion works that way : if n has more than one digit (n <= 10),
** write all digits before the last (with the recursive call);
** then write last digit.(n % 10)
*/

static void	ft_positive(int n, int fd)
{
	if (n >= 10 != 0)
		ft_positive(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

static void	ft_negative(int n, int fd)
{
	if (n <= -10 != 0)
		ft_negative(n / 10, fd);
	ft_putchar_fd(-(n % 10) + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
		ft_positive(n, fd);
	else
	{
		ft_putchar_fd('-', fd);
		ft_negative(n, fd);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <chbechet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 18:40:03 by chbechet          #+#    #+#             */
/*   Updated: 2016/12/22 14:18:36 by chbechet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_reader.h"
#include "libft.h"
#include <stdlib.h>

t_fifo	*ft_file_reader(const int fd)
{
	char	*piece;
	char	separator;
	int		oct_read;
	t_fifo	*list;

	oct_read = 1;
	while (oct_read != 0)
	{
		list = f_fifo_create();
		if (list == NULL)
			return (NULL);
		piece = ft_piece_reader(fd);
		if (piece == NULL)
			return (NULL);
		if (f_fifo_add(list, piece) == NULL)
			return (f_fifo_destroy(&list, (void*)&ft_strdel));
		oct_read = read(fd, &separator, 1);
		if (oct_read == -1)
			return (NULL);
		if (separator != '\n')
			return (f_fifo_destroy(&list, (void*)&ft_strdel));
	}
	return (list);
}

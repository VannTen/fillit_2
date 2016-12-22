/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <chbechet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 18:40:03 by chbechet          #+#    #+#             */
/*   Updated: 2016/12/21 21:16:37 by chbechet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_fifo	*ft_file_reader(const int fd)
{
	char	*piece;
	char	separator;
	int		oct_read;
	t_fifo	*list;

	while (oct_read != 0)
	{
		list = f_create_fifo();
		if (fifo == NULL)
			return (NULL);
		piece = ft_piece_reader(fd);
		if (piece == NULL)
			return (NULL);
		if (f_add_fifo(piece) == NULL)
			return (f_destroy_fifo(list, &ft_strdel));
		oct_read = read(fd, &separator, 1);
		if (oct_read == -1)
			return (NULL);
		if (separator != '\n')
			return (f_destroy_fifo(list, &ft_strdel));
	}
	return (list);
}

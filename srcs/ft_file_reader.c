/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <chbechet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 18:40:03 by chbechet          #+#    #+#             */
/*   Updated: 2017/01/12 14:16:46 by chbechet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_reader.h"
#include "libft.h"
#include <stdlib.h>

t_lst	*ft_file_reader(const int fd)
{
	char	*piece;
	char	separator;
	int		oct_read;
	t_fifo	*fifo;

	oct_read = 1;
	fifo = f_fifo_create();
	if (fifo == NULL)
		return (NULL);
	while (oct_read != 0)
	{
		piece = ft_piece_reader(fd);
		if (piece == NULL)
			return (NULL);
		if (f_fifo_add(fifo, piece) == NULL)
			return ((t_lst*)f_fifo_destroy(&fifo, &ft_gen_strdel));
		oct_read = read(fd, &separator, 1);
		if (oct_read == -1)
			return (NULL);
		if (separator != '\n' && oct_read != 0)
			return ((t_lst*)f_fifo_destroy(&fifo, &ft_gen_strdel));
	}
	return (fifo->begin_lst);
}

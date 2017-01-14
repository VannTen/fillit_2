/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 15:25:52 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/14 16:26:50 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_reader.h"
#include "ft_transform.h"
#include "fillit.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>

/*
** Open the file, passe it to the reader,
** pass the pieces list to the valider,
** then successively transform into coord, then tetrimino
**
** Then, pass return that tetrimino list
*/

t_lst	*ft_parser(const char *file_name)
{
	t_lst	*pieces;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	pieces = ft_file_reader(fd);
	if (f_lst_every_valid(pieces, &ft_valid_pieces_format) != NULL)
		return (NULL);
	pieces = f_lstmap(pieces, &ft_transform_into_coord);
	pieces = f_lstmapi(pieces, &ft_trans_tetri);
	if (close(fd) == -1)
		return (NULL);
	return (pieces);
}

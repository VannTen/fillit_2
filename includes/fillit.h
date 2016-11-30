/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:53:56 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/30 18:20:13 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>

typedef struct	s_piece_part
{
	int x_index;
	int y_index;
}				t_piece_part;
typedef struct	s_piece_origin
{
	size_t x_index;
	size_t y_index;
}				t_piece_origin;
typedef struct	s_tetriminos
{
	t_point	relative_coordinates[3];
	t_point decalage;
	char	identifier;
}				t_tetriminos;

#endif

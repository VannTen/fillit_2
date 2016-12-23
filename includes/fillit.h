/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:53:56 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/24 00:31:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>

typedef struct			s_relative_position
{
	int x;
	int y;
}						t_rel_position;
typedef struct			s_absolute_position
{
	size_t x;
	size_t y;
}						t_abs_position;
typedef t_rel_position	t_offset;
typedef struct			s_tetrimino
{
	t_rel_position		*relative_coordinates;
	t_offset			*offset;
	char				identifier;
}						t_tetrimino;

#endif

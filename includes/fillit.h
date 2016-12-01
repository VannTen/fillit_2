/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:53:56 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/01 12:21:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>

typedef struct			s_piece_position
{
	int x;
	int y;
}						t_piece_position;
typedef struct			s_piece_origin
{
	size_t x;
	size_t y;
}						t_piece_origin;
typedef t_piece_origin	t_decalage;
typedef struct			s_tetriminos
{
	t_piece_position	relative_coordinates[3];
	t_decalage			decalage;
	char				identifier;
}						t_tetriminos;

#endif

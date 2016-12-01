/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:53:56 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/01 11:43:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>

typedef struct			s_piece_part
{
	int x;
	int y;
}						t_piece_part;
typedef struct			s_piece_origin
{
	size_t x;
	size_t y;
}						t_piece_origin;
typedef t_piece_origin	t_decalage;
typedef struct			s_tetriminos
{
	t_piece_part	relative_coordinates[3];
	t_decalage		decalage;
	char			identifier;
}						t_tetriminos;

#endif

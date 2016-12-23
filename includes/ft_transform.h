/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 18:28:26 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/24 00:24:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRANSFORM_H
# define FT_TRANSFORM_H

# include "libft.h"

t_lst	*ft_transform_into_coord(t_lst *piece);
t_lst	*ft_trans_tetri(t_lst *elem, unsigned int index);

#endif

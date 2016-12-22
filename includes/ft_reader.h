/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 13:58:33 by chbechet          #+#    #+#             */
/*   Updated: 2016/12/22 18:34:40 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READER_H
# define FT_READER_H
# include "libft.h"

char	*ft_piece_reader(const int fd);
t_fifo	*ft_file_reader(const int fd);
t_bool	ft_good_place_back_n(const char *piece);
t_bool	ft_valid_count(const char *piece);


#endif

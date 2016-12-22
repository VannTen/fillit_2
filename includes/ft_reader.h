/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 13:58:33 by chbechet          #+#    #+#             */
/*   Updated: 2016/12/22 14:22:13 by chbechet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READER_H
# define FT_READER_H
# include "libft.h"

char	*ft_piece_reader(const int fd);
t_fifo	*ft_file_reader(const int fd);


#endif

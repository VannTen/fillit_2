/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <chbechet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:43:04 by chbechet          #+#    #+#             */
/*   Updated: 2017/01/08 18:00:57 by chbechet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "libft.h"

t_lst	*ft_parser(const char *filename);
char	**ft_solver(t_lst *tetris_lst);
void	ft_display_file(char **array);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbechet <chbechet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:58:52 by chbechet          #+#    #+#             */
/*   Updated: 2017/01/08 17:57:15 by chbechet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	t_lst	*stock;
	char	**square;

	if (argc != 2)
	{
		ft_putstr("Usage : fillit + filename.");
		return (1);
	}
	stock = ft_parser(argv[1]);
	square = ft_solver(stock);
	ft_display_file(square);
	ft_free_string_array(&square);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_relative_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:59:55 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/01 12:32:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_piece_position	*ft_get_other_parts(char **piece, t_piece_origin *origin)
{
	size_t				index_relative;
	t_piece_position	*relative;

	while (index_relative < 3)
	{
		relative = ft_init_relative_position(0, 1);
		if (piece[origin.y + relative.y][origin.x + relative.x] == '#'
				&& !(ft_part_exists(relative, relative_array)))
		{
			relative_array[index_relative] = relative;
			index_relative++;
		}
	}
}
t_piece_part	*ft_relative_position(char **piece_description)
{
	t_piece_origin	first_point;
	size_t			index_positions;

	first_point.y = 0;
	while (first_point.y < 4)
	{
		first_point.x = 0;
		while (first_point.x < 4)
		{
			if (piece_description[first_point.y][first_point.x] == '#')
				return (ft_get_other_parts(piece_description, &first_point));
			first_point.x++;
		}
		first_point.y++;
	}
	return (ERROR);
}


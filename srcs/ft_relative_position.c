/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absative_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:59:55 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/01 14:28:14 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_abs_position	*ft_dup_point(t_abs_position *point)
{
	return (ft_memdup(point, sizeof(t_abs_position)));
}

static t_abs_position	**ft_absolute_positions(char **piece_description)
{
	t_abs_position	*point;
	size_t			index_positions;
	t_abs_position	**positions;

	positions = (t_abs_position**)ft_memalloc(sizeof(t_abs_position*) * 4);
	if (positions == NULL)
		return (NULL);
	index_positions = 0;
	point->y = 0;
	while (point->y < 4)
	{
		point->x = 0;
		while (point->x < 4)
		{
			if (piece_description[point->y][point->x] == '#')
			{
				positions[index_positions] = ft_copy_point(point);
				index_positions++;
			}
			point->x++;
		}
		point->y++;
	}
	return (positions);
}


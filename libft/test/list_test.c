/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:41:40 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/16 13:23:54 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_list	*test_function(t_list *elem)
{
	return (elem);
}

void	test_lstmap(void)
{
	t_list	*initial_list;
	t_list	*final_list;

	initial_list = ft_lstnew(strdup(" 1 2 3"), 8);
	final_list = ft_lstmap(initial_list, &test_function);
}

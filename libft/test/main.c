/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:34:54 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/17 15:46:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"


int	main(int argc, char *argv[])
{
	char	*list_string[6];

	list_string[0] = "kjhkjh";
	list_string[1] = "dsen";
	list_string[2] = "ddn";
	list_string[3] = "81(";
	list_string[4] = "";
	list_string[5] = NULL;

	if (argc)
	{}
	if (argv[1][0] == '1')
	{
		printf("Testing strcmp\n");
		test_strcmp(list_string, &strcmp, &ft_strcmp);
	}
	else if (argv[1][0] == '2')
	{
		printf("Testing strncmp\n");
		test_strncmp(list_string, &strncmp, &ft_strncmp);
	}
	else if (argv[1][0] == '3')
	{
		printf("Testing strlen\n");
		test_strlen(list_string, &strlen, &ft_strlen);
	}
	else if (argv[1][0] == '4')
	{
		printf("Testing strdup\n");
		test_strdup(list_string, &strdup, &ft_strdup);
	}
	else if (argv[1][0] == '5')
	{
		printf("Testing strcpy\n");
		test_strcpy(list_string, &strcpy, &ft_strcpy);
	}
	else if (argv[1][0] == '6')
	{
		printf("Testing strncpy\n");
		test_strncpy(list_string, &strncpy, &ft_strncpy);
	}
	else if (argv[1][0] == '7')
	{
		printf("Testing strcat\n");
		test_strcpy(list_string, &strcat, &ft_strcat);
	}
	else if (argv[1][0] == '8')
	{
		printf("Testing strlcat\n");
		test_strlcat(list_string, &strlcat, &ft_strlcat);
	}
	else if (argv[1][0] == '9')
	{
		printf("test atoi\n");
		test_atoi(argv[2], &atoi, &ft_atoi);
	}
	else if (ft_strcmp(argv[0], "itoa") == 0)
	{
		printf("test itoa\n");
		test_itoa(atoi(argv[2]), &ft_itoa);
	}
	else if (argv[1][0] == 'b')
	{
		printf("ft_putnbr\n");
		ft_putnbr(atoi(argv[2]));
	}
	else if (ft_strcmp(argv[1], "list") == 0)
	{
		printf("testting lists\n");
		test_lstmap();
	}
	else if (ft_strcmp(argv[1], "strlcat") == 0)
	{
		printf("testting strlcat\n");
		uf_test_strlcat();
	}
	else if(ft_strcmp(argv[1], "memcmp") == 0)
	{
		printf("testing memcmp\n");
		test_memcmp();
	}
	else if(ft_strcmp(argv[1], "atoi2") == 0)
	{
		printf("testing atoi2\n");
		test_atoi_2();
	}
	else if(ft_strcmp(argv[1], "memset") == 0)
	{
		printf("testing memset\n");
		test_memset();
	}
	else
		printf("No function found.\n");
	return (0);
}


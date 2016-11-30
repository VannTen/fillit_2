/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:34:34 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/17 18:18:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"


void	test_strcmp(char **tab, t_strcmp ref, t_strcmp test)
{
	size_t	index;

	index = 0;
	while (tab[index + 1] != NULL)
	{
		printf("\"%s\" et \"%s\" :\n", tab[index], tab[index + 1]);
		printf("Ref : %d\n", ref(tab[index], tab[index + 1]));
		printf("Test : %d\n", test(tab[index], tab[index + 1]));
		index++;
	}
}

void	test_strncmp(char **tab, t_strncmp ref, t_strncmp test)
{
	size_t	index;
	size_t	nb_char;

	nb_char = 5;
	index = 0;
	while (tab[index + 1] != NULL)
	{
		printf("\"%s\" et \"%s\" :\n", tab[index], tab[index + 1]);
		printf("Ref : %d\n", ref(tab[index], tab[index + 1], nb_char));
		printf("Test : %d\n", test(tab[index], tab[index + 1], nb_char));
		index++;
	}
}

void	test_strlen(char **tab, t_strlen ref, t_strlen test)
{
	size_t	index;

	index = 0;
	while (tab[index] != NULL)
	{
		printf("Ref : %zu\nA Test : %zu\n",ref(tab[index]), test(tab[index]));
		index++;
	}
}

void	test_strdup(char **tab, t_strdup ref, t_strdup test)
{
	size_t	index;

	index = 0;
	while (tab[index] != NULL)
	{
		printf("Ref : %s\n",ref(tab[index]));
		printf("Test : %s\n",test(tab[index]));
		index++;
	}
}

/*
** strcpy
** Abort at end of prorgamme when dst is too small
*/

void	test_strcpy(char **tab, t_strcpy ref, t_strcpy test)
{
	size_t	index;
	char	*dst;
	char	*s_ref;
	char	*s_test;

	index = 0;
	dst = (char*)malloc(sizeof(char) * 15);
	*dst = *("desdesfesfss");
	while (tab[index] != NULL)
	{
		//	printf("%s\n", dst);
		s_ref = ref(dst, tab[index]);
		s_test = test(dst, tab[index]);
		printf("Refe : %s\n",s_ref);
		printf("Test : %s\n",s_test);
		index++;
	}
	printf("End of test\n");
}

void	test_strncpy(char **tab, t_strncpy ref, t_strncpy test)
{
	size_t	index;
	size_t	nb_char;
	char	dst[40];
	char	*s_ref;
	char	*s_test;

	index = 0;
	nb_char = 20;
	while (tab[index] != NULL)
	{
		s_test = test(dst, tab[index], nb_char);
		s_ref = ref(dst, tab[index], nb_char);
		printf("Refe : %s\n", s_ref);
		printf("Test : %s\n", s_test);
		index++;
	}
	printf("End of test\n");
}

void	test_strlcat(char **tab, t_strlcat ref, t_strlcat test)
{
	size_t	index;
	size_t	nb_char;
	char	*dst;
	char	*dst_2;
	size_t	n_ref;
	size_t	n_test;

	index = 0;
	nb_char = 15;
	dst = (char*)malloc(sizeof(char) * nb_char);
	dst = strdup("blabla");
	dst_2 = (char*)malloc(sizeof(char) * nb_char);
	dst_2 = strdup("blabla");
	while (tab[index] != NULL)
	{
		n_ref = ref(dst, tab[index], nb_char);
		n_test = test(dst_2, tab[index], nb_char);
		printf("Refe %zu : %s\n%zu\n", index, dst, n_ref);
		printf("Test %zu : %s\n%zu\n", index, dst_2, n_test);
		printf("\n");
		index++;
	}
	printf("End of test\n");
}

void	test_atoi(char *number, t_atoi ref, t_atoi test)
{
	printf("Ref : %d\nTest : %d\n", ref(number), test(number));
}

void	test_itoa(int number, t_itoa test)
{
	printf("Test : %s\n", test(number));
}
#define D_ERROR printf("Error X\n");
int				uf_test_strlcat(void)
{
	char		dest[50] = {0};
	char		dest2[50] = {0};
	size_t		i, j, k;

	if (strlcat(dest, "Hello ", 4) != ft_strlcat(dest2, "Hello ", 4))
		D_ERROR
			memset(dest, 0, sizeof(dest));
	memset(dest2, 0, sizeof(dest));
	j = strlcat(dest, "Hello ", 4);
	k = ft_strlcat(dest2, "Hello ", 4);
	if (strcmp(dest, dest2) != 0 || j != k)
		D_ERROR
			j = strlcat(dest, "Hello ", 1);
	k = ft_strlcat(dest2, "Hello ", 1);
	if (strcmp(dest, dest2) != 0 || j != k)
		D_ERROR
			i = 0;
	while (i < 6)
	{
		dest[4 + i] = 'z';
		dest2[4 + i] = 'z';
		++i;
	}
	printf ("%s\n%s\n", dest, dest2);
	j = strlcat(dest, "abc", 6);
	k = ft_strlcat(dest2, "abc", 6);
	printf ("%s\n%s\n%zu\n%zu", dest, dest2, j, k);
	if (strcmp(dest, dest2) != 0 || j != k)
			{
//		D_ERROR
		}
			return (1);
}

void	test_memcmp()
{
	if (memcmp(NULL, NULL, 0) != ft_memcmp(NULL, NULL, 0))
				D_ERROR
}

void	test_atoi_2(void)
{
	printf("atoi\n");
	printf("Ft_atoi\n");
	printf("%s", ((void *)0));
	ft_atoi(((void *)0));
}

void	test_memset(void)
{
	char *a = "te747567st";
	int c = 0;
	char *b = "test";
	ft_putnbr(strlcat(a,b,c));
	ft_putstr("Ref\n");
	ft_putstr(a);
	ft_putnbr(ft_strlcat(a,b,c));
	ft_putstr("Test\n");
}

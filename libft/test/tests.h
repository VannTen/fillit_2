/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:38:19 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/17 15:45:40 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "libft.h"
# include <stdio.h>

typedef	int		(*t_strcmp)(const char *str,const char *str2);
typedef	int		(*t_strncmp)(const char *str,const char *str2, size_t n);
typedef	size_t	(*t_strlen)(const char *str);
typedef	char	*(*t_strdup)(const char *str);
typedef char	*(*t_strcpy)(char *dst, const char *src);
typedef char	*(*t_strncpy)(char *dst, const char *src, size_t len);
typedef char	*(*t_strcat)(char *s1, const char *s2);
typedef	size_t	(*t_strlcat)(char *dst, const char *src, size_t size);
typedef int		(*t_atoi)(const char *number);
typedef char	*(*t_itoa)(int number);


void	test_strcmp(char **tab, t_strcmp ref, t_strcmp test);
void	test_strncmp(char **tab, t_strncmp ref, t_strncmp test);
void	test_strlen(char **tab, t_strlen ref, t_strlen test);
void	test_strcpy(char **tab, t_strcpy ref, t_strcpy test);
void	test_strncpy(char **tab, t_strncpy ref, t_strncpy test);
void	test_strcat(char **tab, t_strcat ref, t_strcat test);
void	test_strdup(char **tab, t_strdup ref, t_strdup test);
void	test_strlcat(char **tab, t_strlcat ref, t_strlcat test);
void	test_atoi(char *number, t_atoi ref, t_atoi test);
void	test_itoa(int number, t_itoa test);
void	test_lstmap(void);
int		uf_test_strlcat(void);
void	test_memcmp();
void	test_atoi_2(void);
void	test_memset(void);

#endif

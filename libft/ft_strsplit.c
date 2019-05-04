/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:12:26 by tcase             #+#    #+#             */
/*   Updated: 2019/04/14 16:12:21 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t j;

	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			j++;
			while (*s != c && *s)
				s++;
		}
		if (*s == c)
			s++;
	}
	return (j);
}

static void		ft_free_arr(char **strarr, size_t count)
{
	size_t		i;

	i = 0;
	while (i < count)
	{
		free(strarr[i]);
		i++;
	}
	free(strarr);
}

static void		ft_strcpy_term(char *dest, const char *src, size_t len)
{
	while (len-- > 0)
		*dest++ = *src++;
	*dest = '\0';
}

static char		**ft_fill_table(char **strarr, const char *s,\
		char c, size_t count)
{
	size_t	i;
	char	**tmp;

	tmp = strarr;
	while (*s)
	{
		i = 0;
		if (*s != c)
		{
			while (*(s + i) != c && *(s + i))
				i++;
			if (!(*strarr = (char*)malloc(i + 1)))
			{
				ft_free_arr(strarr, count);
				return (NULL);
			}
			ft_strcpy_term(*strarr, s, i);
			strarr++;
			s = (s + i);
		}
		if (*s == c)
			s++;
	}
	*strarr = 0;
	return (tmp);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**strarr;
	size_t	count;

	if (!s || !c)
		return (NULL);
	count = ft_count_words(s, c);
	if (!(strarr = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	return (ft_fill_table(strarr, s, c, count));
}

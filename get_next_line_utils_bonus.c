/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:48:36 by asaber            #+#    #+#             */
/*   Updated: 2022/11/23 14:32:59 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_sln(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int	lns;

	lns = 0;
	while (str[lns] && str[lns] != c)
		lns++;
	if (str[lns] == c)
		return (lns);
	return (-1);
}

char	*ft_calloc(int count, int size)
{
	char	*allocat;
	int		total;
	int		i;

	total = count * size;
	allocat = (char *) malloc(total);
	if (allocat == 0)
		return (0);
	i = 0;
	while (total-- > 0)
		allocat[i++] = 0;
	return (allocat);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*allstr;
	int		i;
	int		j;
	int		temp;

	i = 0;
	j = 0;
	temp = ft_sln(s1);
	allstr = ft_calloc((ft_sln(s1) + ft_sln(s2) + 1), sizeof(char));
	if (!s1 || !s2 || !allstr)
		return (NULL);
	while (i < temp)
	{
		allstr[i] = s1[i];
		i++;
	}
	temp = ft_sln(s2);
	while (j < temp)
		allstr[i++] = s2[j++];
	allstr[i] = '\0';
	free(s1);
	return (allstr);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*ptralloc;
	int		i;
	int		line;

	line = ft_sln(s);
	i = 0;
	if (start < line)
	{
		ptralloc = (char *) malloc((len - start + 2) * sizeof(char));
		if (ptralloc == 0)
			return (0);
		while (start <= len)
		{
			ptralloc[i] = s[start];
			i++;
			start++;
		}
		ptralloc[i] = '\0';
		return (ptralloc);
	}
	return (NULL);
}

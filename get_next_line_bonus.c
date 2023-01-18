/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:01:13 by asaber            #+#    #+#             */
/*   Updated: 2022/11/23 15:59:55 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *str)
{
	char	*pt;
	int		ln;
	int		i;

	i = 0;
	ln = ft_sln(str);
	pt = (char *)malloc(ln + 1);
	while (ln >= i)
	{
		pt[i] = str[i];
		i++;
	}
	return (pt);
}

char	*readnstock(int fd, char *s_var)
{
	char	*add;
	int		i;

	if (!s_var)
		s_var = ft_calloc(1, 1);
	add = ft_calloc(BUFFER_SIZE + 1, 1);
	i = 1;
	while (i > 0)
	{
		i = read(fd, add, BUFFER_SIZE);
		if ((s_var[0] == 0 && add[0] == 0) || i < 0)
		{
			free(add);
			free(s_var);
			return (0);
		}
		add[i] = '\0';
		s_var = ft_strjoin(s_var, add);
		if (ft_strchr(add, '\n') >= 0)
			break ;
	}
	free(add);
	return (s_var);
}

char	*get_next_line(int fd)
{
	static char	*stk[4096];
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stk[fd] = readnstock(fd, stk[fd]);
	if (!stk[fd])
	{
		free(stk[fd]);
		return (0);
	}
	if (ft_strchr(stk[fd], '\n') >= 0)
	{
		line = ft_substr(stk[fd], 0, ft_strchr(stk[fd], '\n'));
		tmp = ft_substr(stk[fd], ft_strchr(stk[fd], '\n') + 1, ft_sln(stk[fd]));
		free(stk[fd]);
		stk[fd] = tmp;
		return (line);
	}
	line = ft_strdup(stk[fd]);
	free(stk[fd]);
	stk[fd] = 0;
	return (line);
}

/*int	main()
{
	int fd = open("test.txt", O_RDWR);	
//	get_next_line(fd);
	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
	close(fd);
}*/
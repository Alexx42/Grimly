/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 22:14:10 by ale-goff          #+#    #+#             */
/*   Updated: 2018/09/30 10:29:30 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <fcntl.h>
#include "libft.h"
#define MAX_FD 2560
#define ALLOC_CHECK(p) if ((p) == NULL) return (-1)

int		next_line(int fd, char **line, char **nl, char **tmp)
{
	char		*tmp1;
	ssize_t		nread;
	char		buf[BUFF_SIZE + 1];

	while ((*nl = ft_strchr(*tmp, '\n')) == NULL)
	{
		ft_bzero(buf, BUFF_SIZE + 1);
		if ((nread = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		if (nread == 0)
		{
			if (**tmp == '\0')
				return (0);
			*line = ft_strdup((*tmp));
			**tmp = '\0';
			return (1);
		}
		tmp1 = *tmp;
		*tmp = ft_strjoin(*tmp, buf);
		free(tmp1);
	}
	return (2);
}

int		get_next_line(int fd, char **line)
{
	static char	*data[MAX_FD] = {0};
	char		*nl;
	char		*tmp;
	int			ret;

	if (line == NULL || fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	if (data[fd] && (nl = ft_strchr(data[fd], '\n')))
	{
		*nl = '\0';
		*line = data[fd];
		data[fd] = ft_strdup(nl + 1);
		return (1);
	}
	tmp = data[fd];
	if (tmp == NULL)
		ALLOC_CHECK(tmp = ft_strdup(""));
	if ((ret = next_line(fd, line, &nl, &tmp)) != 2)
		return (ret);
	*nl = '\0';
	*line = ft_strdup(tmp);
	data[fd] = ft_strdup(nl + 1);
	free(tmp);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:56:32 by gfreddie          #+#    #+#             */
/*   Updated: 2019/09/29 19:42:23 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char		*files[10240];
	char			buf[BUFF_SIZE + 1];
	int				r;
	char			*str;

	while ((!(!(line)) || (r != -1)) && (r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		str = files[fd];
		if (!(files[fd] = ft_strjoin(files[fd], buf)))
			files[fd] = ft_strdup(buf);
		ft_strdel(&str);
	}
	if ((r == -1 || !ft_strlen(files[fd])) && (!line || (*line = ft_strnew(0))))
		return (r);
	str = ft_strchr(files[fd], '\n');
	if (str && !(*str = '\0'))
		str = ft_strdup(str + 1);
	else
		str = ft_strnew(0);
	*line = ft_strdup(files[fd]);
	free(files[fd]);
	files[fd] = str;
	return (1);
}

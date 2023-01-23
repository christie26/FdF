/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:00:07 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/22 20:08:12 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*ft_read_buffer(char *buf, char *storage, int fd)
{
	ssize_t	read_size;
	char	*tmp;

	while (!ft_strchr(storage, '\n'))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buf[read_size] = 0;
		tmp = storage;
		storage = ft_strjoin(storage, buf);
		free(tmp);
		if (!storage)
			return (0);
		if (read_size < BUFFER_SIZE)
			break ;
	}
	if (read_size == -1)
		return (0);
	if (read_size == 0 && storage[0] == 0)
		return (0);
	return (storage);
}

char	*ft_get_line(char **storage)
{
	size_t	n;
	char	*line;

	n = 0;
	while ((*storage)[n] && (*storage)[n] != '\n')
		n++;
	line = ft_substr(*storage, 0, n + 1);
	*storage = ft_substr(*storage, n + 1, ft_strlen(*storage) - n - 1);
	return (line);
}

char	*ft_free(char **buf1, char **buf2)
{
	free(*buf1);
	*buf1 = 0;
	free(*buf2);
	*buf2 = 0;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buf;
	char		*line;
	char		*tmp;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	if (!storage)
	{
		storage = ft_strdup("");
		if (!storage)
			return (0);
	}
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	tmp = ft_read_buffer(buf, storage, fd);
	if (!tmp)
		return (ft_free(&buf, &storage));
	storage = tmp;
	line = ft_get_line(&storage);
	ft_free(&buf, &tmp);
	return (line);
}

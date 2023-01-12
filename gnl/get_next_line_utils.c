/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:00:37 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/12 17:42:55 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	key;
	char	*src;
	size_t	i;
	size_t	len_src;

	src = (char *) s;
	len_src = ft_strlen(src);
	key = c;
	i = 0;
	while (i < len_src + 1)
	{
		if (*src == key)
			return (src);
		src++;
		i++;
	}
	return (0);
}

char	*ft_strdup(char *src)
{
	size_t	len;
	char	*new;
	char	*tmp;

	len = ft_strlen((char *)src);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!(new))
		return (0);
	tmp = new;
	while (*src && *src != '\n')
		*tmp++ = *src++;
	*tmp = 0;
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	len_s1;
	size_t	len_s2;
	size_t	total;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	total = len_s1 + len_s2;
	dst = (char *)malloc(sizeof(char) * (total + 1));
	if (!dst)
		return (0);
	while (len_s1--)
		*(dst++) = *(s1++);
	while (len_s2--)
		*(dst++) = *(s2++);
	*dst = 0;
	dst -= total;
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;

	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	i = 0;
	j = 0;
	while (s[j] && i < len)
	{
		if (j < start)
		{
			j++;
			continue ;
		}
		dst[i++] = s[j++];
	}
	dst[i] = 0;
	return (dst);
}

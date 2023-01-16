/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:43:39 by yoonsele          #+#    #+#             */
/*   Updated: 2022/11/20 18:47:52 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_length(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	cnt;

	j = 0;
	cnt = 0;
	while (s[j] && cnt < len)
	{
		if (j < start)
		{
			j++;
			continue ;
		}
		j++;
		cnt++;
	}
	return (cnt);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;
	size_t	cnt;

	cnt = get_length(s, start, len);
	dst = (char *)malloc(sizeof(char) * (cnt + 1));
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

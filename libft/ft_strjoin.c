/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:00:37 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/13 16:58:54 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

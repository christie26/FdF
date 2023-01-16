/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:15:31 by yoonsele          #+#    #+#             */
/*   Updated: 2022/11/20 18:47:39 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chk(const char *haystack, const char *needle, size_t i, size_t len)
{
	int	j;

	j = 0;
	while (needle[j] && (haystack[i + j] == needle[j]) && (i + j) < len)
		j++;
	if (needle[j] == 0)
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_hay;

	i = 0;
	if (needle[i] == 0)
		return ((char *)haystack);
	len_hay = ft_strlen((char *)haystack);
	while (i < len_hay && i < len)
	{
		if (chk(haystack, needle, i, len))
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}

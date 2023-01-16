/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:21:36 by yoonsele          #+#    #+#             */
/*   Updated: 2022/11/20 18:47:29 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len_src;
	unsigned int	i;
	char			*res;

	len_src = ft_strlen((char *)s);
	res = (char *)malloc(sizeof(char) * (len_src + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < len_src)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

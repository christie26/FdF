/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:58:08 by yoonsele          #+#    #+#             */
/*   Updated: 2022/11/20 18:47:44 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	key;
	char	*src;
	int		i;
	int		tmp;
	int		len_src;

	src = (char *) s;
	len_src = ft_strlen(src);
	key = c;
	i = 0;
	tmp = -1;
	while (i < len_src + 1)
	{
		if (src[i] == key)
			tmp = i;
		i++;
	}
	if (tmp != -1)
		return (src + tmp);
	return (0);
}

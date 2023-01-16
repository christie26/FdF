/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:21:30 by yoonsele          #+#    #+#             */
/*   Updated: 2022/11/20 18:46:39 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*new;
	char	*tmp;

	len = ft_strlen((char *)src);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!(new))
		return (0);
	tmp = new;
	while (*src)
		*tmp++ = *src++;
	*tmp = 0;
	return (new);
}

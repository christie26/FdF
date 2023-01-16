/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:38:31 by yoonsele          #+#    #+#             */
/*   Updated: 2022/11/20 18:46:46 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	len_src;
	unsigned int	i;

	len_src = ft_strlen((char *)s);
	i = 0;
	while (i < len_src)
	{
		(*f)(i, &s[i]);
		i++;
	}
	return ;
}

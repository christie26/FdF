/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:41:39 by yoonsele          #+#    #+#             */
/*   Updated: 2022/11/20 18:45:06 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_digit(unsigned int n)
{
	int	cnt;

	if (n == 0)
		return (1);
	cnt = 0;
	while (n)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

char	*ft_utoa(unsigned int n)
{
	int				digit;
	char			*res;
	char			*tmp;

	digit = find_digit(n);
	res = (char *)malloc(sizeof(char) * (digit + 1));
	if (!res)
		return (0);
	tmp = res;
	tmp += (digit - 1);
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		*tmp = n % 10 + '0';
		tmp--;
		n /= 10;
	}
	res[digit] = 0;
	return (res);
}

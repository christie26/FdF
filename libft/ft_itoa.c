/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:41:39 by yoonsele          #+#    #+#             */
/*   Updated: 2022/11/20 18:45:06 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_digit(int n, int *flag, unsigned int *nb)
{
	int				cnt;
	unsigned int	tmp;

	if (n == 0)
	{
		*nb = 0;
		return (1);
	}
	cnt = 0;
	if (n < 0)
	{
		*nb = -n;
		cnt++;
		*flag = 1;
	}
	else
		*nb = n;
	tmp = *nb;
	while (tmp)
	{
		cnt++;
		tmp /= 10;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	int				digit;
	unsigned int	nb;
	int				flag;
	char			*res;
	char			*tmp;

	digit = find_digit(n, &flag, &nb);
	res = (char *)malloc(sizeof(char) * (digit + 1));
	if (!res)
		return (0);
	tmp = res;
	if (flag)
		*tmp = '-';
	tmp += (digit - 1);
	if (nb == 0)
		res[0] = '0';
	while (nb != 0)
	{
		*tmp = nb % 10 + '0';
		tmp--;
		nb /= 10;
	}
	res[digit] = 0;
	return (res);
}

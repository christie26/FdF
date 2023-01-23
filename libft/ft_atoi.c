/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:32:52 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/22 19:29:22 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(char c)
{
	if (c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == '\t' || c == ' ')
		return (1);
	else
		return (0);
}

static int	is_sign(char c, int *sign)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			(*sign)++;
		return (1);
	}
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	sum;
	int			sign;

	i = 0;
	sum = 0;
	sign = 0;
	while (is_space(str[i]) == 1)
		i++;
	if (is_sign(str[i], &sign) == 1)
		i++;
	while (('0' <= str[i]) && (str[i] <= '9'))
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	if (sign == 1)
		sum = -sum;
	return (sum);
}

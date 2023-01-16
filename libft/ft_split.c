/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:57:22 by yoonsele          #+#    #+#             */
/*   Updated: 2022/11/20 18:46:31 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_table(char **table, int idx_tab)
{
	while (idx_tab)
	{
		idx_tab--;
		free(table[idx_tab]);
	}
	free(table);
	return (0);
}

static char	*ft_filltab(char **tab, char *s, char c, int idx_tab)
{
	int	i;
	int	cnt;

	while (*s == c)
		s++;
	i = 0;
	cnt = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		cnt++;
	}
	tab[idx_tab] = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!tab[idx_tab])
		return (free_table(tab, idx_tab));
	i = 0;
	while (i < cnt)
	{
		tab[idx_tab][i] = s[i];
		i++;
	}
	tab[idx_tab][i] = 0;
	return (s + i);
}

static int	count(char const *s, char c)
{
	int		cnt;
	char	*src;

	src = (char *)s;
	if (!*src)
		return (0);
	cnt = 0;
	if (*src++ != c)
		cnt++;
	while (*src)
	{
		if (*src != c && *(src - 1) == c)
			cnt++;
		src++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*src;
	int		cnt;
	int		i;

	cnt = count(s, c);
	tab = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!tab)
		return (0);
	src = (char *)s;
	i = 0;
	while (i < cnt)
	{
		src = ft_filltab(tab, src, c, i);
		if (src == 0)
			return (0);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

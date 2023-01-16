/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:28:09 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/16 13:41:12 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *node)
{
	if (!lst)
		return ;
	if (*lst)
	{
		node->next = *lst;
		*lst = node;
	}
	else
		*lst = node;
}
/*

lst
a -> b -> c

node
d -> e -> f

*/

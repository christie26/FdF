/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:28:50 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/16 13:40:46 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*sethead(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	void	*tmp;

	if (!lst)
		return (0);
	tmp = (*f)(lst->content);
	if (!tmp)
		return (0);
	head = ft_lstnew(tmp);
	if (!head)
	{
		(*del)(tmp);
		return (0);
	}
	return (head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*curr;
	void	*tmp;

	head = sethead(lst, (*f), (*del));
	if (!head)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		tmp = (*f)(lst->content);
		if (!tmp)
			return (0);
		curr = ft_lstnew(tmp);
		if (!curr)
		{
			(*del)(tmp);
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, curr);
	}
	return (head);
}
// how about use "tail" here

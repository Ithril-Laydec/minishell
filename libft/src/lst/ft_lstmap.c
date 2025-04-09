/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itjimene <itjimene@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:46:00 by itjimene          #+#    #+#             */
/*   Updated: 2024/12/21 16:25:07 by itjimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*mapped;

	mapped = NULL;
	while (lst)
	{
		new = malloc(sizeof(t_list));
		if (!new)
		{
			ft_lstclear(&mapped, del);
			return (NULL);
		}
		new->content = f(lst->content);
		new->next = NULL;
		ft_lstadd_back(&mapped, new);
		lst = lst->next;
	}
	return (mapped);
}

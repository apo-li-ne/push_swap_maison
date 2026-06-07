/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:49:31 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/04/30 14:46:34 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list *ma_liste = NULL;
	t_list *brique1 = ft_lstnew("Monde");
	t_list *brique2 = ft_lstnew("Hello");

	ft_lstadd_front(&ma_liste, brique1);

	ft_lstadd_front(&ma_liste, brique2);

	t_list *temp = ma_liste;
	while (temp)
	{
		printf("%s -> ", (char *)temp->content);
		temp = temp->next;
	}
	printf("NULL\n");

	return (0);
}*/

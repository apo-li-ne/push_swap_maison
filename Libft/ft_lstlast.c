/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:25:29 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/04/30 14:27:49 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	t_list *ma_liste = NULL;
	t_list *brique1 = ft_lstnew("Monde");
	t_list *brique2 = ft_lstnew("Hello");
	t_list *brique3 = ft_lstnew("World");

	ft_lstadd_front(&ma_liste, brique1);
	ft_lstadd_front(&ma_liste, brique2);
	ft_lstadd_front(&ma_liste, brique3);

	printf("%s\n", (char *)ft_lstlast(ma_liste)->content);
	return (0);
}*/
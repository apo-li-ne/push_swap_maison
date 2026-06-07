/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:01:19 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/04/30 15:32:00 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

/*
int main(void)
{
	t_list *ma_liste = NULL;
	ft_lstadd_front(&ma_liste, ft_lstnew(ft_strdup("Monde")));
	ft_lstadd_front(&ma_liste, ft_lstnew(ft_strdup("Hello")));
	printf("Avant clear : %p\n", ma_liste);

	ft_lstclear(&ma_liste, free);
	if (ma_liste == NULL)
		printf("Après clear : NULL (ma_liste est vide)\n");
	else
		printf("Après clear : %p il y a une erreur \n", ma_liste);
	
	return (0);
}
*/
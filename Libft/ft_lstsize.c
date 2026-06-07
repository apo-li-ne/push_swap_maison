/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:04:36 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/05/01 16:49:49 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*
int	main(void)
{
	t_list	*ma_liste;
	t_list	*brique1;
	t_list	*brique2;
	t_list	*brique3;

	// creer 3 noeuds dans une liste puis les compter
	ma_liste = NULL;
	brique1 = ft_lstnew("Monde");
	brique2 = ft_lstnew("Hello");
	brique3 = ft_lstnew("World");
	ft_lstadd_front(&ma_liste, brique1);
	ft_lstadd_front(&ma_liste, brique2);
	ft_lstadd_front(&ma_liste, brique3);
	printf("Taille de la liste : %d\n", ft_lstsize(ma_liste));
	return (0);
}
	*/
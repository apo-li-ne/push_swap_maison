/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:35:38 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/04/30 15:45:43 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	print_string(void *s)
{
	printf("%s\n", (char *)s);
}

int	main(void)
{
	t_list *lst;
	lst = ft_lstnew(ft_strdup("salut"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("monde")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("!")));
	ft_lstiter(lst, print_string);
	ft_lstclear(&lst, free);
	return (0);
}
	*/
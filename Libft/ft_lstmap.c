/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:00:11 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/05/01 16:50:10 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		content = f(lst->content);
		temp = ft_lstnew(content);
		if (!temp)
		{
			del(content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}

/*
void	*f_envelope(void *content)
{
	return (ft_strdup((char *)content));
}

void	del_test(void *content)
{
	(void)content;
}

int	main(void)
{
	t_list	*ma_liste;
	t_list	*brique1;
	t_list	*brique2;
	t_list	*brique3;
	t_list	*new_liste;
	t_list	*temp;

	ma_liste = NULL;
	brique1 = ft_lstnew("Monde");
	brique2 = ft_lstnew("Hello");
	brique3 = ft_lstnew("World");
	ft_lstadd_front(&ma_liste, brique1);
	ft_lstadd_front(&ma_liste, brique2);
	ft_lstadd_front(&ma_liste, brique3);
	new_liste = ft_lstmap(ma_liste, f_envelope, free);
	temp = new_liste;
	while (temp)
	{
		printf("%s -> ", (char *)temp->content);
		temp = temp->next;
	}
	printf("NULL\n");
	ft_lstclear(&ma_liste, del_test);
	ft_lstclear(&new_liste, free);
	return (0);
}
	*/
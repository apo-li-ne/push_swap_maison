/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:14:13 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/04/28 12:43:55 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
int main (void)
{
	t_list *node;
	char *data = "la terre est plate";

	node = ft_lstnew(data);
	if (node)
	{
		printf("Contenu : %s\n", (char *)node->content);
		if (node->next == NULL)
			printf("Suivant est bien NULL !\n");
		free(node);
	}
	return(0);
} */
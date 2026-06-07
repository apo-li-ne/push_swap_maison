/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:54:26 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/05/01 16:52:43 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	if (n != 0 && size > ((size_t)-1 / n))
		return (NULL);
	ptr = malloc(n * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n * size);
	return (ptr);
}
/*
int	main(void)
{
	int	*tab;
	int	i;

	tab = (int *) ft_calloc(10, sizeof(int));
	if (!tab)
		return (1);
	i = 0;
	while (i < 10)
	{
		printf("%d  ", tab[i]);
		i++;
	}
	printf(" \n");
	free(tab);
	return (0);
}
	*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:47:00 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/05/01 16:51:38 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;
	size_t				i;

	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return ((int)a[i] - (int)b[i]);
		i++;
	}
	return (0);
}
/*
int main (void)
{
	char	str1[] = "Hello";
	char	str2[] = "Hello";
	int		result;

	result = ft_memcmp(str1, str2, 5);
	printf("Result: %d\n", result);
	return (0);
}
	*/
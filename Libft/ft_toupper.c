/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:05:13 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/04/27 13:07:39 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*
int	main(void)
{
	printf("=== Test ft_toupper ===\n");
	printf("'a' -> '%c'\n", ft_toupper('a'));
	printf("'z' -> '%c'\n", ft_toupper('z'));
	printf("'A' -> '%c'\n", ft_toupper('A'));
	printf("'5' -> '%c'\n", ft_toupper('5'));
	printf("' ' -> '%c'\n", ft_toupper(' '));
	printf("'-' -> '%c'\n", ft_toupper('-'));

	return (0);
} */
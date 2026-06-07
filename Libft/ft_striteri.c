/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:00:46 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/04/27 13:19:04 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	f_test(unsigned int i, char *c)
{
	(void)i;
	*c = ft_toupper(*c);
}
int	main(void)
{
	char str[] = "hello world, la terre est plate";
	ft_striteri(str, f_test);
	printf("%s\n", str);
	return (0);
} */
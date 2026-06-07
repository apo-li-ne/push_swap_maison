/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:55:55 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/05/04 13:34:56 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	if (*s2 == '\0')
		return ((char *)s1);
	len = ft_strlen(s2);
	i = 0;
	while (s1[i] && i + len <= n)
	{
		if (ft_strncmp(s1 + i, s2, len) == 0)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	str1[] = "Hello";
	char	str2[] = "Hello";
	char	*result;

	result = ft_strnstr(str1, str2, 5);
	printf("Result: %s\n", result);
	return (0);
}
	*/

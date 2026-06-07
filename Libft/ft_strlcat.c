/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:08:51 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/05/04 16:56:48 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && dst_len + i < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
int	main(void)
{
	char dst1[30] = "Bonjour";
	char dst2[10] = "Hello";
	char dst3[20] = "C";
	char dst4[5] = "Test";

	printf("=== Test 1 : Concaténation normale ===\n");
	printf("Avant : dst = \"%s\"\n", dst1);
	size_t ret1 = ft_strlcat(dst1, " monde", 30);
	printf("Après : dst = \"%s\"\n", dst1);
	printf("Retour = %zu, strlen(dst) = %zu\n\n", ret1, ft_strlen(dst1));

	printf("=== Test 2 : Buffer trop petit (troncature) ===\n");
	printf("Avant : dst = \"%s\" (size = 10)\n", dst2);
	size_t ret2 = ft_strlcat(dst2, " World!", 10);
	printf("Après : dst = \"%s\"\n", dst2);
	printf("Retour = %zu, strlen(dst) = %zu (troncature détectée !)\n\n", ret2,
		ft_strlen(dst2));

	printf("=== Test 3 : Plusieurs concaténations ===\n");
	printf("Avant : dst = \"%s\"\n", dst3);
	ft_strlcat(dst3, " is", 20);
	printf("Après 1ère concat : \"%s\"\n", dst3);
	ft_strlcat(dst3, " awesome", 20);
	printf("Après 2ème concat : \"%s\"\n\n", dst3);

	printf("=== Test 4 : Buffer déjà plein ===\n");
	printf("Avant : dst = \"%s\" (size = 5)\n", dst4);
	size_t ret4 = ft_strlcat(dst4, "123", 5);
	printf("Après : dst = \"%s\"\n", dst4);
	printf("Retour = %zu (rien n'a été ajouté, dst = \"%s\")\n\n", ret4, dst4);

	return (0);
}
*/
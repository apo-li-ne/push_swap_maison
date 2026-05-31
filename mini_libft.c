/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apo <apo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:19:30 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/05/30 19:21:51 by apo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	countwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

void	freeall(char **result, int j)
{
	while (j > 0)
		free(result[--j]);
	free(result);
}

char	*ft_substr(const char *s, int start, int len)
{
    int     i;
	char	*out;

    i = 0;
	out = malloc(sizeof(char) * len + 1);
	if (!out)
		return (NULL);
	while (s[i + start] && len)
	{
        out[i] = s[i + start];
        i++;
        len--;
	}
    out[i] = '\0';
    return (out);
}

int     ft_strlen(char  *s)
{
    int     i;

    if (!s)
        return (0);
    i = 0;
    while (s[i])
        i++;
    return (i);
}

char	**jsp(char const *s, char c, char **result)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c)
			i++;
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len)
		{
			result[j] = ft_substr(s, i, len);
			if (!result[j])
				return (freeall(result, j), NULL);
			j++;
		}
		i += len;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((countwords(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = jsp(s, c, result);
	if (!result)
	{
		return (NULL);
	}
	return (result);
}

void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
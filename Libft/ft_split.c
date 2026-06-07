/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:50:45 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/05/01 16:53:20 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		mot;

	count = 0;
	mot = 0;
	while (*s)
	{
		if (*s != c && !mot)
		{
			count++;
			mot = 1;
		}
		else if (*s == c)
			mot = 0;
		s++;
	}
	return (count);
}

static char	*next_word(char const *s, char c, size_t *i)
{
	size_t	start;
	size_t	len;

	while (s[*i] && s[*i] == c)
		(*i)++;
	start = *i;
	len = 0;
	while (s[*i] && s[*i] != c)
	{
		(*i)++;
		len++;
	}
	return (ft_substr(s, (unsigned int)start, len));
}

static void	free_tab(char **tab, size_t n)
{
	while (n--)
		free(tab[n]);
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	mots;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	mots = count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (mots + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (j < mots)
	{
		tab[j] = next_word(s, c, &i);
		if (!tab[j])
		{
			free_tab(tab, j);
			return (NULL);
		}
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
/*
int main (void)
{
	char	**tab;
	int		i;

	tab = ft_split("Hello World, la terre est plate", ' ');
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
*/
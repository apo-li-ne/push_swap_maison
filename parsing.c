/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 03:05:40 by apolguil          #+#    #+#             */
/*   Updated: 2026/06/08 22:40:45 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_is_valid(char *str)
{
	int		i;
	long	n;
	long	sign;

	i = 0;
	n = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		n = n * 10 + (str[i++] - '0');
		if ((sign * n) > INT_MAX || (sign * n) < INT_MIN)
			return (0);
	}
	return (1);
}

int	is_duplicate(t_pile *pile)
{
	t_stack	*i;
	t_stack	*j;

	i = pile->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

void	assign_index(t_pile *pile)
{
	t_stack	*i;
	t_stack	*j;
	int		rank;

	i = pile->top;
	while (i)
	{
		rank = 0;
		j = pile->top;
		while (j)
		{
			if (j->value < i->value)
				rank++;
			j = j->next;
		}
		i->index = rank;
		i = i->next;
	}
}

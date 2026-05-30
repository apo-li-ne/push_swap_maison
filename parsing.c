/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 03:05:40 by apolguil          #+#    #+#             */
/*   Updated: 2026/05/28 19:34:03 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*int		is_overflow(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
	{
		if (ft_strlen(str) > 11)
			return (0);
		if (ft_strlen(str) == 11)
			return (ft_strncmp(*str, "-2147483648", 11) < 0);
		return (1);
	}
	if (ft_strlen(str) > 10)
		return (0);
	if (ft_strlen(str) == 10)
		return (ft_strncmp(*str, "2147483647", 10) < 0);
	return (1);
} */

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
		//gestion du oveflow
		if ((sign * n) > INT_MAX || (sign * n) < INT_MIN)
			return (0);
	}
	return (1);
}

int	is_duplicate(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;

	i = stack;
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

void	assign_index(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;
	int		rank;

	i = stack;
	while (i)
	{
		rank = 0;
		j = stack;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:27:51 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/08 20:53:30 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_pile *pile)
{
	t_stack	*tmp;

	if (!pile || !pile->top || pile->size < 2)
		return (1);
	tmp = pile->top;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

float	compute_disorder(t_pile *pile)
{
	t_stack	*n1;
	t_stack	*n2;
	float	mistake;
	float	paires;

	if (!pile || pile->size < 2)
		return (0);
	mistake = 0;
	paires = 0;
	n1 = pile->top;
	while (n1)
	{
		n2 = n1->next;
		while (n2)
		{
			paires++;
			if (n1->value > n2->value)
				mistake++;
			n2 = n2->next;
		}
		n1 = n1->next;
	}
	if (paires == 0)
		return (0);
	return (mistake / paires);
}

int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

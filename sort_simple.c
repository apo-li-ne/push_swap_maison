/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:16:00 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/08 21:06:57 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_program *prog)
{
	if (prog->a.top->value > prog->a.top->next->value)
		sa(prog);
}

static int	find_min_pos(t_pile *pile)
{
	t_stack	*tmp;
	int		pos;
	int		min_pos;
	int		min_val;

	tmp = pile->top;
	pos = 0;
	min_pos = 0;
	min_val = tmp->value;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}

static void	bring_min_to_top(t_program *prog)
{
	int	pos;
	int	size;

	pos = find_min_pos(&prog->a);
	size = prog->a.size;
	if (pos == 0)
		return ;
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(prog);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			rra(prog);
			pos--;
		}
	}
}

void	sort_three(t_program *prog)
{
	int	a;
	int	b;
	int	c;

	a = prog->a.top->value;
	b = prog->a.top->next->value;
	c = prog->a.top->next->next->value;
	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
		rra(prog);
	else if (b < a && a < c)
		sa(prog);
	else if (b < c && c < a)
		ra(prog);
	else if (c < a && a < b)
		(sa(prog), rra(prog));
	else
		(ra(prog), sa(prog));
}

void	sort_simple(t_program *prog)
{
	if (is_sorted(&prog->a))
		return ;
	if (prog->a.size == 2)
	{
		sort_two(prog);
		return ;
	}
	if (prog->a.size == 3)
	{
		sort_three(prog);
		return ;
	}
	while (prog->a.size > 3)
	{
		bring_min_to_top(prog);
		pb(prog);
	}
	sort_three(prog);
	while (prog->b.size > 0)
		pa(prog);
}

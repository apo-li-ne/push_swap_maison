/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:16:00 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/03 21:28:51 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_program *prog)
{
	if (prog->a.top->value > prog->a.top->next->value)
		sa(prog);
}

// on cherche la position du minimum dans a
// retourne le nombre de noeuds avant lui depuis le top
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

// on fait remonter le min au top : ra si plus proche du haut, rra sinon
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
		pos = size - pos; // nb de rra necessaires
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
	if (a < c && c < b)
		return (void)(rra(prog));
	if (b < a && a < c)
		return (void)(sa(prog));
	if (b < c && c < a)
		return (void)(ra(prog));
	if (c < a && a < b)
	{
		sa(prog);
		rra(prog);
		return ;
	}
	// cas restant : c < b < a -> ordre inverse total
	ra(prog);
	sa(prog);
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
	// phase 1 : on envoie les minimums un par un dans b
	while (prog->a.size > 3)
	{
		bring_min_to_top(prog);
		pb(prog);
	}
	// phase 2 : on trie les 3 restants dans a
	sort_three(prog);
	// phase 3 : on ramene tout de b vers a
	while (prog->b.size > 0)
		pa(prog);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 22:26:40 by apolguil          #+#    #+#             */
/*   Updated: 2026/06/08 22:41:17 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile *pile)
{
	t_stack	*first;
	t_stack	*second;

	if (pile->size < 2)
		return ;
	first = pile->top;
	second = pile->top->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	pile->last = first;
	second->next = first;
	pile->top = second;
}

void	sa(t_program *prog)
{
	swap(&prog->a);
	exec_op(prog, "sa");
}

void	sb(t_program *prog)
{
	swap(&prog->b);
	exec_op(prog, "sb");
}

void	ss(t_program *prog)
{
	swap(&prog->a);
	swap(&prog->b);
	exec_op(prog, "ss");
}

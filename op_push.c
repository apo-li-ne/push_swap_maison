/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 22:28:15 by apolguil          #+#    #+#             */
/*   Updated: 2026/06/08 22:41:40 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_pile *from, t_pile *to)
{
	t_stack	*tmp;

	if (from->size == 0)
		return ;
	tmp = from->top;
	from->top = from->top->next;
	if (from->top)
		from->top->prev = NULL;
	else
		from->last = NULL;
	from->size--;
	tmp->next = to->top;
	tmp->prev = NULL;
	if (to->top)
		to->top->prev = tmp;
	else
		to->last = tmp;
	to->top = tmp;
	to->size++;
}

void	pa(t_program *prog)
{
	push(&prog->b, &prog->a);
	exec_op(prog, "pa");
}

void	pb(t_program *prog)
{
	push(&prog->a, &prog->b);
	exec_op(prog, "pb");
}

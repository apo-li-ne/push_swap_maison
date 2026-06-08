/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 22:30:08 by apolguil          #+#    #+#             */
/*   Updated: 2026/06/08 22:41:32 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_pile *pile)
{
	t_stack	*tmp;

	if (pile->size < 2)
		return ;
	tmp = pile->last;
	pile->last = pile->last->prev;
	pile->last->next = NULL;
	tmp->prev = NULL;
	tmp->next = pile->top;
	pile->top->prev = tmp;
	pile->top = tmp;
}

void	rra(t_program *prog)
{
	reverse_rotate(&prog->a);
	exec_op(prog, "rra");
}

void	rrb(t_program *prog)
{
	reverse_rotate(&prog->b);
	exec_op(prog, "rrb");
}

void	rrr(t_program *prog)
{
	reverse_rotate(&prog->a);
	reverse_rotate(&prog->b);
	exec_op(prog, "rrr");
}

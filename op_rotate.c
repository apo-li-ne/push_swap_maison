/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 22:29:19 by apolguil          #+#    #+#             */
/*   Updated: 2026/06/08 22:41:25 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_pile *pile)
{
	t_stack	*tmp;

	if (pile->size < 2)
		return ;
	tmp = pile->top;
	pile->top = pile->top->next;
	pile->top->prev = NULL;
	tmp->next = NULL;
	tmp->prev = pile->last;
	pile->last->next = tmp;
	pile->last = tmp;
}

void	ra(t_program *prog)
{
	rotate(&prog->a);
	exec_op(prog, "ra");
}

void	rb(t_program *prog)
{
	rotate(&prog->b);
	exec_op(prog, "rb");
}

void	rr(t_program *prog)
{
	rotate(&prog->a);
	rotate(&prog->b);
	exec_op(prog, "rr");
}

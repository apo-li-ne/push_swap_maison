/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 11:24:16 by apo               #+#    #+#             */
/*   Updated: 2026/06/08 22:30:23 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_op(t_program *prog, char *op)
{
	prog->op_count++;
	if (ft_strcmp(op, "sa") == 0)
		prog->counts[0]++;
	else if (ft_strcmp(op, "sb") == 0)
		prog->counts[1]++;
	else if (ft_strcmp(op, "ss") == 0)
		prog->counts[2]++;
	else if (ft_strcmp(op, "pa") == 0)
		prog->counts[3]++;
	else if (ft_strcmp(op, "pb") == 0)
		prog->counts[4]++;
	else if (ft_strcmp(op, "ra") == 0)
		prog->counts[5]++;
	else if (ft_strcmp(op, "rb") == 0)
		prog->counts[6]++;
	else if (ft_strcmp(op, "rr") == 0)
		prog->counts[7]++;
	else if (ft_strcmp(op, "rra") == 0)
		prog->counts[8]++;
	else if (ft_strcmp(op, "rrb") == 0)
		prog->counts[9]++;
	else if (ft_strcmp(op, "rrr") == 0)
		prog->counts[10]++;
	ft_printf("%s\n", op);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 18:05:07 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/04 18:19:00 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_bench_ops(t_program *prog)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(prog->counts[0], 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(prog->counts[1], 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(prog->counts[2], 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(prog->counts[3], 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(prog->counts[4], 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(prog->counts[5], 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(prog->counts[6], 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(prog->counts[7], 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(prog->counts[8], 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(prog->counts[9], 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(prog->counts[10], 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_program *prog, float disorder)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((int)(disorder * 100), 2);
	ft_putstr_fd(".", 2);
	if ((int)(disorder * 10000) % 100 < 10)
    	ft_putstr_fd("0", 2);
	ft_putnbr_fd((int)(disorder * 10000) % 100, 2);
	ft_putstr_fd("%\n[bench] strategy: ", 2);
	if (prog->strategy == FLAG_SIMPLE)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (prog->strategy == FLAG_MEDIUM)
		ft_putstr_fd("Medium / O(n sqrt n)\n", 2);
	else if (prog->strategy == FLAG_COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else
		ft_putstr_fd("Adaptive / O(n log n)\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(prog->op_count, 2);
	ft_putstr_fd("\n", 2);
	print_bench_ops(prog);
}
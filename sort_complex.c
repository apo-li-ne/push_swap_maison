/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:32:15 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/08 23:08:13 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bits_needed_for_index(int size)
{
	int	index_max;
	int	bits;

	index_max = size - 1;
	bits = 0;
	while (index_max > 0)
	{
		index_max >>= 1;
		bits++;
	}
	return (bits);
}

int	top_index(t_program *prog)
{
	return (prog->a.top->index);
}

int	is_bit_one(int index, int bits)
{
	return ((index >> bits) & 1);
}

void	ft_radix(t_program *prog, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (is_bit_one(top_index(prog), bit))
			ra(prog);
		else
			pb(prog);
		i++;
	}
	while (prog->b.size > 0)
		pa(prog);
}

void	sort_complex(t_program *prog)
{
	int	size;
	int	bit;
	int	total_bits;

	size = prog->a.size;
	total_bits = max_bits_needed_for_index(size);
	bit = 0;
	while (bit < total_bits)
	{
		ft_radix(prog, bit, size);
		bit++;
	}
}

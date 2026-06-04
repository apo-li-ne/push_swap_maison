/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:32:15 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/03 21:29:18 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 18:32:15 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/03 18:33:20 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(int size)
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

void	sort_complex(t_program *prog)
{
	int	size;
	int	bits;
	int	i;
	int	j;
	int	index;

	size = prog->a.size; 
	bits = max_bits(size); 
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			index = prog->a.top->index; 
			if ((index >> i) & 1) 
				ra(prog);
			else
				pb(prog);
			j++;
		}
		while (prog->b.size > 0)
			pa(prog);
		i++;
	}
}

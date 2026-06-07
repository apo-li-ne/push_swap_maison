/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:16:20 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/04 15:29:45 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_program *prog)
{
	float	disorder;

	disorder = compute_disorder(&prog->a);
	if (disorder < 0.2f)
		sort_simple(prog);
	else if (disorder >= 0.2f && disorder < 0.5f)
		sort_medium(prog);
	else
		sort_complex(prog);
}
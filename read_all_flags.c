/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apo <apo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 01:21:05 by apolguil          #+#    #+#             */
/*   Updated: 2026/05/30 19:13:01 by apo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_complexity(char *arg, t_program *prog)
{
	if (ft_strcmp(arg, "--simple") == 0)
		prog->strategy = FLAG_SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		prog->strategy = FLAG_MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		prog->strategy = FLAG_COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		prog->strategy = FLAG_ADAPTIVE;
}

void	parse_program_flags(int argc, char **av, t_program *prog)
{
	int	i;

	i = 1;
	prog->strategy = FLAG_ADAPTIVE;
	prog->is_bench = 0;
	
	/*while (i <= 2 && i < argc)*/
	while (i < argc)
	{
		if (ft_strcmp(av[i], "--bench") == 0)
			prog->is_bench = 1; 
		else
			check_complexity(av[i], prog); 
		i++;
	}
}
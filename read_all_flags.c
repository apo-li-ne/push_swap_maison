/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 01:21:05 by apolguil          #+#    #+#             */
/*   Updated: 2026/05/29 20:51:07 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	get_flags_complexity(char **av, int **flags, int *seen, int *i)
{
	if (!ft_strcmp(av[*i], "--simple"))
	{
		*flags[*i - 1] = FLAG_SIMPLE;
		*seen = FLAG_SIMPLE;
	}
	else if (!ft_strcmp(av[*i], "--medium"))
	{
		*flags[*i - 1] = FLAG_MEDIUM;
		*seen = FLAG_MEDIUM;
	}
	else if (!ft_strcmp(av[*i], "--complex"))
	{
		*flags[*i - 1] = FLAG_COMPLEX;
		*seen = FLAG_COMPLEX;
	}
	else if (!ft_strcmp(av[*i], "--adaptive"))
	{
		*flags[*i - 1] = FLAG_ADAPTIVE;
		*seen = FLAG_ADAPTIVE;
	}
}

int	*get_flag(int ac, char **av)
{
	int	i;
	int	seen;

	int flags[2] = {0, 0};
	i = 0;
	seen = 0;
	while (i <= 2 && i < ac)
	{
		if (!ft_strcmp(av[i], "--bench") && seen != FLAG_BENCH)
		{
			seen = FLAG_BENCH;
			flags[i - 1] = FLAG_BENCH;
		}
		else if (seen == 0 || seen == FLAG_BENCH)
            get_flags_complexity(&flags, &seen, &i);
		if (seen == 0)
			return (NULL);
        i++;
	}
    return flags;
}
*/


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
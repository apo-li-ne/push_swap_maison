/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:28:22 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/05/30 06:48:47 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(char *str)
{
	if (ft_strcmp(str, "--bench") == 0)
		return (1);
	if (ft_strcmp(str, "--simple") == 0)
		return (1);
	if (ft_strcmp(str, "--medium") == 0)
		return (1);
	if (ft_strcmp(str, "--complex") == 0)
		return (1);
	if (ft_strcmp(str, "--adaptive") == 0)
		return (1);
	return (0);
}

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1; // Sera rempli plus tard par assign_index
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!stack || !new_node)
		return ;
	if (!*stack) // Si la pile est vide il devient le premier element
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}

int	init_from_split(t_program *prog, char *str)
{
	char	**split;
	int		i;
	t_stack	*node;

	split = ft_split(str, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		if (!int_is_valid(split[i]))
			return (free_split(split), 0);
		node = create_node(ft_atoi(split[i]));
		if (!node)
			return (free_split(split), 0);
		stack_add_back(&(prog->stack_a), node);
		i++;
	}
	return (free_split(split), is_duplicate(prog->stack_a));
}

int	init_stack_a(t_program *prog, int ac, char **av)
{
	int		i;
	char *joined;
	char *tmp;

	if (ac == 2 && !is_flag(av[1]))
	{
		printf("patate");
		// si il y a que deux arguments (le nom du programme et une chaine)
		return (init_from_split(prog, av[1])); // return init split
	}
	printf("patate");
	i = 1;
	while (is_flag(av[i]))
	{
		printf("%d", i);
		i++;
	}
	joined = NULL;
	while (av[i])
	{
		tmp = joined;
		joined = ft_strjoin(tmp, av[i]);
		free(tmp);
		i++;
	}
	return (init_from_split(prog, joined));
}

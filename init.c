/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:28:22 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/08 21:21:35 by apolguil         ###   ########.fr       */
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
	new_node->index = -1;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	pile_add_back(t_pile *pile, t_stack *new_node)
{
	if (!pile || !new_node)
		return ;
	if (!pile->top)
	{
		pile->top = new_node;
		pile->last = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		new_node->next = NULL;
		new_node->prev = pile->last;
		pile->last->next = new_node;
		pile->last = new_node;
	}
	pile->size++;
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
		pile_add_back(&prog->a, node);
		i++;
	}
	if (is_duplicate(&prog->a))
		return (free_split(split), 0);
	return (free_split(split), 1);
}

int	init_stack_a(t_program *prog, int ac, char **av)
{
	int		i;
	t_stack	*node;

	i = 1;
	while (i < ac)
	{
		if (!is_flag(av[i]))
		{
			if (ft_strchr(av[i], ' '))
				return (init_from_split(prog, av[i]));
			if (!int_is_valid(av[i]))
				return (0);
			node = create_node(ft_atoi(av[i]));
			if (!node)
				return (0);
			pile_add_back(&prog->a, node);
		}
		i++;
	}
	if (is_duplicate(&prog->a))
		return (0);
	return (1);
}

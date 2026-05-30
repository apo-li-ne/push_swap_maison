/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:36:43 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/05/30 06:49:28 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Main de test

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	printf("\n=== ETAT DE LA PILE A ===\n");
	if (!tmp)
		printf("(Pile vide)\n");
	while (tmp)
	{
		printf("Valeur : %d | Index : %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	printf("=========================\n\n");
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_program	prog;

	if (argc < 2)
		return (0);

	prog.stack_a = NULL;
	prog.stack_b = NULL;

	parse_program_flags(argc, argv, &prog);

	if (!init_stack_a(&prog, argc, argv))
	{
		write(2, "Error\n", 6);
		free_stack(&prog.stack_a); 
		return (1);
	}

	//Attribution des index
	assign_index(prog.stack_a);

	printf("Stratégie (0=Simple, 3=Adaptive) : %d\n", prog.strategy);
	printf("Mode Bench activé ? : %d\n", prog.is_bench);
	print_stack(prog.stack_a);

	free_stack(&prog.stack_a);
	return (0);
}
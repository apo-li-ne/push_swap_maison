/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apo <apo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:36:43 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/05/31 12:14:46 by apo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_pile *pile)
{
	t_stack	*tmp;

	tmp = pile->top;
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

void	free_pile(t_pile *pile) 
{
	t_stack	*tmp;

	if (!pile || !pile->top)
		return ;
	while (pile->top)
	{
		tmp = pile->top->next;
		free(pile->top);
		pile->top = tmp;
	}
	pile->last = NULL;
	pile->size = 0;    
}

int	main(int argc, char **argv)
{
	t_program	prog;

	if (argc < 2)
		return (0);
	prog.a = (t_pile){NULL, NULL, 0};
	prog.b = (t_pile){NULL, NULL, 0};
	
	parse_program_flags(argc, argv, &prog);
	if (!init_stack_a(&prog, argc, argv))
	{
		write(2, "Error\n", 6);
		free_pile(&prog.a);
		return (1);
	}
	assign_index(&prog.a);
	printf("Stratégie (0=Simple, 3=Adaptive) : %d\n", prog.strategy);
	printf("Mode Bench activé ? : %d\n", prog.is_bench);
	print_stack(&prog.a);
	
	free_pile(&prog.a);
	return (0);
}

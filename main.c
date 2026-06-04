/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:36:43 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/04 01:45:08 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Fonction de debug pour afficher les deux piles horizontalement.
*/
void	print_stacks(t_program *prog)
{
	t_stack	*tmp_a = prog->a.top;
	t_stack	*tmp_b = prog->b.top;

	printf("\nPile A : ");
	if (!tmp_a)
		printf("(vide)");
	while (tmp_a)
	{
		printf("[%d] ", tmp_a->value);
		tmp_a = tmp_a->next;
	}
	printf("\nPile B : ");
	if (!tmp_b)
		printf("(vide)");
	while (tmp_b)
	{
		printf("[%d] ", tmp_b->value);
		tmp_b = tmp_b->next;
	}
	printf("\n--------------------------------\n");
}


void	free_stack(t_pile *pile)
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
{/*
	t_program	prog;

	if (argc < 2)
		return (0);

	prog.a.top = NULL;
	prog.a.last = NULL;
	prog.a.size = 0;
	prog.b.top = NULL;
	prog.b.last = NULL;
	prog.b.size = 0;
	prog.op_count = 0;
	prog.is_bench = 1;

	parse_program_flags(argc, argv, &prog);
	if (!init_stack_a(&prog, argc, argv))
	{
		write(2, "Error\n", 6);
		free_pile(&prog.a);
		return (1);
	}
	
	if (is_sorted(&prog.a))
	{
		free_pile(&prog.a);
		return (0);
	}
	printf("\n=== ETAT INITIAL ===");
	print_stacks(&prog);

	printf("\n> Push 2 elements dans B (pb, pb)\n");
	pb(&prog);
	pb(&prog);
	print_stacks(&prog);

	printf("\n> Swap A et Swap B en meme temps (ss)\n");
	ss(&prog);
	print_stacks(&prog);

	printf("\n> Rotate A (ra)\n");
	ra(&prog);
	print_stacks(&prog);

	printf("\n> Reverse Rotate B (rrb)\n");
	rrb(&prog);
	print_stacks(&prog);

	printf("\n> On remet tout dans A (pa, pa)\n");
	pa(&prog);
	pa(&prog);
	print_stacks(&prog);

	if (prog.is_bench)
	{
		printf("\n=========================\n");
		printf("🎯 TOTAL OPERATIONS : %d\n", prog.op_count);
		printf("=========================\n\n");
	}

	free_pile(&prog.a);
	free_pile(&prog.b);

	return (0); */


	t_program	prog;

	if (argc < 2)
		return (0);
	prog.a.top = NULL;
	prog.a.last = NULL;
	prog.a.size = 0;
	prog.b.top = NULL;
	prog.b.last = NULL;
	prog.b.size = 0;
	prog.op_count = 0;
	prog.is_bench = 0;
	parse_program_flags(argc, argv, &prog);
	if (!init_stack_a(&prog, argc, argv))
	{
		free_stack(&prog.a);  // peut avoir des noeuds deja alloues
		free_stack(&prog.b);  // vide mais pas grave d'appeler quand meme
		write(2, "Error\n", 6);
		return (1);
	}
	if (is_sorted(&prog.a))
	{
		free_stack(&prog.a);
		return (0);
	}
	assign_index(&prog.a);
	if (prog.strategy == FLAG_SIMPLE)
		sort_simple(&prog);
	else if (prog.strategy == FLAG_COMPLEX)
		sort_complex(&prog);
	else if (prog.strategy == FLAG_MEDIUM)
		sort_complex(&prog);
	free_stack(&prog.a);
	free_stack(&prog.b);
	return (0);

}

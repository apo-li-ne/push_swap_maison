/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:36:43 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/08 23:08:54 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_program *prog)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = prog->a.top;
	tmp_b = prog->b.top;
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

void	init_prog(t_program *prog)
{
	int	i;

	i = 0;
	while (i < 11)
		prog->counts[i++] = 0;
	prog->a.top = NULL;
	prog->a.last = NULL;
	prog->a.size = 0;
	prog->b.top = NULL;
	prog->b.last = NULL;
	prog->b.size = 0;
	prog->op_count = 0;
	prog->is_bench = 0;
}

void	run_strategy(t_program *prog)
{
	if (prog->strategy == FLAG_SIMPLE)
		sort_simple(prog);
	else if (prog->strategy == FLAG_COMPLEX)
		sort_complex(prog);
	else if (prog->strategy == FLAG_MEDIUM)
		sort_medium(prog);
	else
		sort_adaptive(prog);
}

int	main(int argc, char **argv)
{
	t_program	prog;
	float		disorder;

	if (argc < 2)
		return (0);
	init_prog(&prog);
	parse_program_flags(argc, argv, &prog);
	if (!init_stack_a(&prog, argc, argv))
		return (free_stack(&prog.a), free_stack(&prog.b), write(2, "Error\n",
				6), 1);
	if (is_sorted(&prog.a))
		return (free_stack(&prog.a), 0);
	assign_index(&prog.a);
	disorder = compute_disorder(&prog.a);
	run_strategy(&prog);
	if (prog.is_bench)
		print_bench(&prog, disorder);
	free_stack(&prog.a);
	free_stack(&prog.b);
	return (0);
}

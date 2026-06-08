/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:03:01 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/08 22:43:24 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_pile
{
	t_stack			*top;
	t_stack			*last;
	int				size;
}					t_pile;

typedef enum e_strategy
{
	FLAG_SIMPLE,
	FLAG_MEDIUM,
	FLAG_COMPLEX,
	FLAG_ADAPTIVE
}					t_strategy;

typedef struct s_program
{
	t_pile			a;
	t_pile			b;
	t_strategy		strategy;
	int				is_bench;
	int				op_count;
	int				counts[11];
}					t_program;

int					int_is_valid(char *str);
int					is_duplicate(t_pile *pile);
void				assign_index(t_pile *pile);
void				parse_program_flags(int argc, char **av, t_program *prog);
int					init_stack_a(t_program *prog, int ac, char **av);

t_stack				*create_node(int value);
void				pile_add_back(t_pile *pile, t_stack *new_node);
void				free_stack(t_pile *pile);
int					ft_sqrt(int n);

void				sa(t_program *prog);
void				sb(t_program *prog);
void				ss(t_program *prog);
void				pa(t_program *prog);
void				pb(t_program *prog);
void				ra(t_program *prog);
void				rb(t_program *prog);
void				rr(t_program *prog);
void				rra(t_program *prog);
void				rrb(t_program *prog);
void				rrr(t_program *prog);
void				exec_op(t_program *prog, char *op);

int					is_sorted(t_pile *pile);
float				compute_disorder(t_pile *pile);

void				sort_complex(t_program *prog);

void				sort_two(t_program *prog);
void				sort_three(t_program *prog);
void				sort_simple(t_program *prog);

void				sort_medium(t_program *prog);

void				sort_adaptive(t_program *prog);

void				print_bench(t_program *prog, float disorder);

#endif

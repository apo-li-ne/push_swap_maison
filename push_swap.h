/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:03:01 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/05/30 06:16:32 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;
typedef enum e_strategy
{
	FLAG_SIMPLE,
	FLAG_MEDIUM,
	FLAG_COMPLEX,
	FLAG_ADAPTIVE
}					t_strategy; //au lieu de travailler avec plusieurs define, maintenant on peut declarer une variable directement avec t_strategy

//Le mode Bench, lui, n'est pas un algorithme de tri. C'est une option d'affichage (un outil de mesure)
typedef struct s_program
{
	t_stack     *stack_a;
	t_stack     *stack_b;
	t_strategy  strategy;   // Stocke l'algo (Simple, Medium, etc.)
	int         is_bench;   // Mode Bench : 0 (Désactivé) ou 1 (Activé)
}               t_program;

int	ft_strcmp(const char *s1, const char *s2);
int	ft_atoi(const char *str);


int	int_is_valid(char *str);
int	is_duplicate(t_stack *stack);
void	assign_index(t_stack *stack);


void	parse_program_flags(int argc, char **av, t_program *prog);

t_stack	*create_node(int value);
void	stack_add_back(t_stack **stack, t_stack *new_node);
int	init_stack_a(t_program *prog, int ac, char **av);
int  init_from_split(t_program *prog, char *str);

char    **ft_split(char const *s, char c);
void	free_split(char **split);
char	*ft_strjoin(char *s1, char *s2);

#endif

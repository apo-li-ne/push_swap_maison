/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apo <apo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:03:01 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/05/31 12:11:28 by apo              ###   ########.fr       */
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

typedef struct s_pile 
{
	t_stack		*top;
	t_stack		*last;
	int			size;
}				t_pile;

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
	// t_stack		*stack_a; 
	// t_stack		*stack_b;
	t_pile		a; //remplace *stack_a qui est juste un pointeur vers le premier élément par un struct pile qui contient top last et size
	t_pile	    b;
	t_strategy  strategy;   // Stocke l'algo (Simple, Medium, etc.)
	int         is_bench;   // Mode Bench : 0 (Désactivé) ou 1 (Activé)
}               t_program;

int	int_is_valid(char *str);
int     is_duplicate(t_pile *pile);
void    assign_index(t_pile *pile);
void	parse_program_flags(int argc, char **av, t_program *prog);
int	init_stack_a(t_program *prog, int ac, char **av);
int  init_from_split(t_program *prog, char *str);

t_stack	*create_node(int value);
void	pile_add_back(t_pile *pile, t_stack *new_node);

char    **ft_split(char const *s, char c);
void	free_split(char **split);
char	*ft_strchr(const char *s, int c);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_atoi(const char *str);
char	*ft_substr(const char *s, int start, int len);

void	sa(t_pile *a);
void	sb(t_pile *b);
void	ss(t_pile *a, t_pile *b);
void	pa(t_pile *a, t_pile *b);
void	pb(t_pile *a, t_pile *b);
void	ra(t_pile *a);
void	rb(t_pile *b);
void	rr(t_pile *a, t_pile *b);
void	rra(t_pile *a);
void	rrb(t_pile *b);
void	rrr(t_pile *a, t_pile *b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 11:24:16 by apo               #+#    #+#             */
/*   Updated: 2026/06/07 22:08:15 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_op(t_program *prog, char *op)
{
	prog->op_count++;
	
	if (ft_strcmp(op, "sa") == 0)
		prog->counts[0]++;
	else if (ft_strcmp(op, "sb") == 0)
		prog->counts[1]++;
	else if (ft_strcmp(op, "ss") == 0)
		prog->counts[2]++;
	else if (ft_strcmp(op, "pa") == 0)
		prog->counts[3]++;
	else if (ft_strcmp(op, "pb") == 0)
		prog->counts[4]++;
	else if (ft_strcmp(op, "ra") == 0)
		prog->counts[5]++;
	else if (ft_strcmp(op, "rb") == 0)
		prog->counts[6]++;
	else if (ft_strcmp(op, "rr") == 0)
		prog->counts[7]++;
	else if (ft_strcmp(op, "rra") == 0)
		prog->counts[8]++;
	else if (ft_strcmp(op, "rrb") == 0)
		prog->counts[9]++;
	else if (ft_strcmp(op, "rrr") == 0)
		prog->counts[10]++;
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
}
void	swap(t_pile *pile)
{
	t_stack	*first;
	t_stack	*second;

	if (pile->size < 2)
		return ;
	first = pile->top; //fisrt est le top de la pile
	second = pile->top->next; //second le next du top
	first->next = second->next; //on veut swap les deux premier, on fait passer le "third" au dessus du second
	if (second->next)
		second->next->prev = first; //on veut que le prev du "third" devienne le next du nouveau top 
	else
		pile->last = first; //si le next de second n'existe pas le last de la pile c'est le first
	second->prev = NULL;
	second->next = first;
	first->prev = second; //le second est donc le first mm si il s'appelle toujours second et vice versa, on joue avec les pointeurs quoi
	pile->top = second; //et voilà !!
}

void	sa(t_program *prog)
{
	swap(&prog->a);
	exec_op(prog, "sa");
}

void	sb(t_program *prog)
{
	swap(&prog->b);
	exec_op(prog, "sb");
}

void	ss(t_program *prog)
{
	swap(&prog->a);
	swap(&prog->b);
	exec_op(prog, "ss");
}

void	push(t_pile *from, t_pile *to)
{
	t_stack	*tmp;

	if (from->size == 0)
		return ;
	tmp = from->top; //on suave le top de from dans tmp
	from->top = from->top->next; //le nouveau top et le nexte de celui-ci
	if (from->top)
		from->top->prev = NULL; //le prev du top est NULL, il n'existe pas
	else
		from->last = NULL;
	from->size--; //on enlève un noeud donc on diminue la size
	tmp->next = to->top; //next de tmp devient le top de to
	tmp->prev = NULL; //tmp est le nv top donc rien avant lui
	if (to->top)
		to->top->prev = tmp; //le top de to pointe maintenant vers tmp
	else
		to->last = tmp; //si to était vide, tmp devient également le last c'est le seul élément présent dans to
	to->top = tmp;
	to->size++; // ajout d'un élément à to
}

void	pa(t_program *prog)
{
	push(&prog->b, &prog->a);
	exec_op(prog, "pa");
}

void	pb(t_program *prog)
{
	push(&prog->a, &prog->b);
	exec_op(prog, "pb");
}

void	rotate(t_pile *pile)
{
	t_stack	*tmp;

	if (pile->size < 2)
		return ;
	tmp = pile->top; //on sauve le top dans tmp
	pile->top = pile->top->next; //nouveau top deviens le next de l'ancien top
	pile->top->prev = NULL; //maintenant le prev du nv top pointe vers null
	tmp->next = NULL; //tmp va être le last donc next pointe vers rien
	tmp->prev = pile->last; //le prev de tmp c'est l'ancien last de la pile
	pile->last->next = tmp; //l'ancien last pointe vers tmp
	pile->last = tmp; //et voilaaa
}

void	ra(t_program *prog)
{
	rotate(&prog->a);
	exec_op(prog, "ra");
}

void	rb(t_program *prog)
{
	rotate(&prog->b);
	exec_op(prog, "rb");
}

void	rr(t_program *prog)
{
	rotate(&prog->a);
	rotate(&prog->b);
	exec_op(prog, "rr");
}

void	reverse_rotate(t_pile *pile) //bon vraiment le même principe que rotate à l'envers
{
	t_stack	*tmp;

	if (pile->size < 2)
		return ;
	tmp = pile->last;
	pile->last = pile->last->prev;
	pile->last->next = NULL;
	tmp->prev = NULL;
	tmp->next = pile->top;
	pile->top->prev = tmp;
	pile->top = tmp;
}

void	rra(t_program *prog)
{
	reverse_rotate(&prog->a);
	exec_op(prog, "rra");
}

void	rrb(t_program *prog)
{
	reverse_rotate(&prog->b);
	exec_op(prog, "rrb");
}

void	rrr(t_program *prog)
{
	reverse_rotate(&prog->a);
	reverse_rotate(&prog->b);
	exec_op(prog, "rrr");
}
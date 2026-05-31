/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apo <apo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 11:24:16 by apo               #+#    #+#             */
/*   Updated: 2026/05/31 12:07:29 by apo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sa(t_pile *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_pile *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_pile *a, t_pile *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
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

void	pa(t_pile *a, t_pile *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_pile *a, t_pile *b)
{
	push(a, b);
	write(1, "pb\n", 3);
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

void	ra(t_pile *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_pile *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_pile *a, t_pile *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
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

void	rra(t_pile *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_pile *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_pile *a, t_pile *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
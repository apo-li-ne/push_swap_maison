/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 22:17:13 by apolguil          #+#    #+#             */
/*   Updated: 2026/06/07 23:36:24 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_pos_next_element_to_push(t_program *prog, int element_nbr)
{
    int i;
    t_stack *stack_b;

    i = 0;
    stack_b = prog->b.top;
    while (stack_b && stack_b->index != element_nbr) // on va chercher le plus grand index(une fois trier) present dans la stack
    {
        stack_b = stack_b->next;
        i++;
    }
    if (!stack_b)
		return (0);
    if (i > prog->b.size / 2)
        return (i - prog->b.size);
    return (i);
}

static void get_elements_back(t_program *prog, int nb_elements)
{
    int rot_to_pos; //nombre de rotation necessaires pour mettre le + grand element de b en haut de b
    void(*f_op)(t_program *);
    int i;

    i = 0;
    while (prog->b.size)
    {
        i = 0;
        rot_to_pos = find_pos_next_element_to_push(prog, --nb_elements);
        if (rot_to_pos < 0)
        {
            f_op = rrb;
            rot_to_pos *= -1;
        }
        else 
            f_op = rb;
        while (i++ < rot_to_pos)
            f_op(prog);
        pa(prog);
    }
}

void sort_medium(t_program *prog)
{
	int	chunck_size;
	int	nb_elements;
	int	i;
	int	j;

	nb_elements = prog->a.size;
	chunck_size = nb_elements / ft_sqrt(nb_elements); // ← nb_chunck inline
	i = 1;
	while (prog->a.size)
	{
		j = prog->a.size; // ← current_size inline
		while (j--)
		{
			if (prog->a.top->index <= chunck_size * i)
				pb(prog);
			else
				ra(prog);
		}
		i++;
	}
	get_elements_back(prog, nb_elements);
}

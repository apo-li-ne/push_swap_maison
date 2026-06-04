#include "push_swap.h"

int find_pos_next_element_to_push(t_program *prog, int element_nbr)
{
    int i;
    t_stack *stack_b;

    i = 0;
    stack_b = prog->b.top;
    while (prog->b.top->index != element_nbr) // on va chercher le plus grand index(une fois trier) present dans la stack
    {
        stack_b = stack_b->next;
        i++;
    }
    if (i > element_nbr / 2)
        return (i - element_nbr);
    return (i);
}

void get_elements_back(t_program *prog, int nb_elements)
{
    int rot_to_pos; //nombre de rotation necessaires pour mettre le + grand element de b en haut de b
    void(*f_op)(t_program *);
    int i;

    i = 0;
    while (prog->b.size)
    {
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
    int chunck_size;
    int nb_elements;
    int nb_chunck;
    int i;


    nb_elements = prog->a.size;
    nb_chunck = ft_sqrt(nb_elements);
    chunck_size = nb_elements / nb_chunck;
    i = 1;
    while (prog->a.size)
    {
        while (prog->a.size >= (nb_elements - (chunck_size * i))) //tant que la stack n a pas diminuee d un (autre) chunk
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

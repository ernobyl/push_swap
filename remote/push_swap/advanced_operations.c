/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:10:32 by emichels          #+#    #+#             */
/*   Updated: 2024/02/16 13:22:31 by emichels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    prep_for_push(t_stack **stack, t_stack *top, char stackname)
{
    while (*stack != top)
    {
        if (stackname == 'a')
        {
            if (top->move == up)
                ra(stack);
            else
                rra(stack);
        }
        else if (stackname == 'b')
        {
            if (top->move == up)
                rb(stack);
            else
                rrb(stack);
        }
    }
}

void    move_a_to_b(t_stack **a, t_stack **b)
{
    t_stack    *cheapest;

    cheapest = get_cheapest(*a);
    if (cheapest->move == up && cheapest->target->move == up)
        rr_to_place(a, b, cheapest);
    else if (cheapest->move == down && cheapest->target->move == down)
        reverse_to_place(a, b, cheapest);
    prep_for_push(a, cheapest, 'a');
    prep_for_push(b, cheapest->target, 'b');
    pb(a, b);
}

void    move_b_to_a(t_stack **a, t_stack **b)
{
    prep_for_push(a, (*b)->target, 'a');
    pa(b, a);
}

void    min_on_top(t_stack **a)
{
    while ((*a)->value != find_min_value(*a)->value)
    {
        if (find_min_value(*a)->move == up)
            ra(a);
        else
            rra(a);
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:10:32 by emichels          #+#    #+#             */
/*   Updated: 2024/02/16 13:22:31 by emichels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    current_index(t_stack *stack)
{
    int i;

    i = 0;
    if (!stack)
        return ;
    while (stack)
    {
        stack->index = i;
        stack = stack->next;
        i++;
    }
}

void    scan_stack(t_stack *a, t_stack *b)
{
    current_index(a);
    current_index(b);
    set_target(a, b);
    check_operations(a, b);
    set_least_operations(a);
}
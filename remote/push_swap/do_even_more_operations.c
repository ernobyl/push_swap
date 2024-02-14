/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_even_more_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:28:04 by emichels          #+#    #+#             */
/*   Updated: 2024/02/09 16:27:08 by emichels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:10:32 by emichels          #+#    #+#             */
/*   Updated: 2024/02/16 13:22:31 by emichels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*current_a;
	long	closest_bigger;

	while (b)
	{
		closest_bigger = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < closest_bigger)
			{
				closest_bigger = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_bigger == LONG_MAX)
			b->target = find_min_value(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	scan_stack_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

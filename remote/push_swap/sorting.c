/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:28:04 by emichels          #+#    #+#             */
/*   Updated: 2024/02/09 16:27:08 by emichels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_three(int argc, t_stack **stack, char **argv)
{
	if (count_args(argv[1]) == 2 || argc == 3)
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
	if (count_args(argv[1]) == 3 || argc == 4)
	{
		while ((*stack)->value > (*stack)->next->value ||
				(*stack)->value > (*stack)->next->next->value ||
				(*stack)->next->value > (*stack)->next->next->value)
		{
			if ((*stack)->value < (*stack)->next->value &&
				(*stack)->value < (*stack)->next->next->value)
				rra(stack);
			else if ((*stack)->next->value > (*stack)->next->next->value)
				ra(stack);
			else if ((*stack)->value > (*stack)->next->value)
			{
				if ((*stack)->value > (*stack)->next->next->value)
					ra(stack);
				else
					sa(stack);
			}
		}
	}
}

void selection_sort(t_stack **a, t_stack **b)
{
	int min_index;
	int size;

	size = count_stack(a);
	if (size > 3)
	{
		while (size > 0)
		{
			min_index = find_min_value_index(a);
			move_to_top(a, min_index, size);
			pb(a, b);
			size--;
		}
		size = count_stack(b);
		while (size > 0)
		{
			pa(b, a);
			size--;
		}
	}
}

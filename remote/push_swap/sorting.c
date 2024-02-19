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

void	sort_two(t_stack **stack)
{
	int	size;

	size = count_stack(stack);
	if (size == 2)
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
}

void	sort_three(t_stack **stack)
{
	int		size;
	t_stack	*max_val;

	size = count_stack(stack);
	if (size == 3)
	{
		max_val = find_max_value(*stack);
		if (max_val == *stack)
			ra(stack);
		else if (max_val == (*stack)->next)
			rra(stack);
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	size;

	size = count_stack(a);
	if (size > 3)
	{
		if (size-- > 3 && !if_sorted(*a))
			pb(a, b);
		if (size-- > 3 && !if_sorted(*a))
			pb(a, b);
		while (size-- > 3 && !if_sorted(*a))
		{
			scan_stack_a(*a, *b);
			move_a_to_b(a, b);
		}
		sort_three(a);
		while (*b)
		{
			scan_stack_b(*a, *b);
			move_b_to_a(a, b);
		}
		current_index(*a);
		min_on_top(a);
	}
}
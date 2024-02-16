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
		max_val = find_max_value(stack);
		if (max_val == *stack)
			ra(stack);
		else if (max_val == (*stack)->next)
			rra(stack);
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
	}
}

void selection_sort(t_stack **a, t_stack **b)
{
	int min_index;
	int size;

	size = count_stack(a);
	if (size > 3 && size <= 20)
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

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	size;

	size = count_stack(a);
	if (size-- > 3 && !if_sorted(*a))
		pb(a, b);
	if (size-- > 3 && !if_sorted(*a))
		pb(a, b);
	while (size-- > 3 && !if_sorted(*a))
	{
		scan_stack(*a, *b);
	}
}
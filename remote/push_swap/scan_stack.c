/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:10:32 by emichels          #+#    #+#             */
/*   Updated: 2024/02/22 11:39:46 by emichels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *stack)
{
	int	i;
	int	direction;

	i = 0;
	if (!stack)
		return ;
	direction = count_stack(&stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= direction)
			stack->move = up;
		else
			stack->move = down;
		stack = stack->next;
		++i;
	}
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*current_b;
	long	closest_smaller;

	while (a)
	{
		closest_smaller = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value
				&& current_b->value > closest_smaller)
			{
				closest_smaller = current_b->value;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_smaller == LONG_MIN)
			a->target = find_max_value(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	check_operations(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = count_stack(&a);
	size_b = count_stack(&b);
	while (a)
	{
		a->operations = a->index;
		if (a->move == down)
			a->operations = size_a - a->index;
		if (a->target->move == up)
			a->operations = a->operations + a->target->index;
		else
			a->operations = a->operations + size_b - a->target->index;
		a = a->next;
	}
}

void	set_least_operations(t_stack *stack)
{
	long	least_operations;
	t_stack	*cheapest;

	if (!stack)
		return ;
	least_operations = LONG_MAX;
	while (stack)
	{
		if (stack->operations < least_operations)
		{
			least_operations = stack->operations;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->switch_cheapest = true;
}

void	scan_stack_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	check_operations(a, b);
	set_least_operations(a);
}

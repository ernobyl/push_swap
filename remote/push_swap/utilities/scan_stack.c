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

#include "../push_swap.h"

void	get_index_and_direction(t_stack *stack)
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

void	set_move_count(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = count_stack(&a);
	size_b = count_stack(&b);
	while (a)
	{
		a->move_count = a->index;
		if (a->move == down)
			a->move_count = size_a - a->index;
		if (a->target->move == up)
			a->move_count = a->move_count + a->target->index;
		else
			a->move_count = a->move_count + size_b - a->target->index;
		a = a->next;
	}
}

void	set_least_moves(t_stack *stack)
{
	long	min_move_count;
	t_stack	*cheapest;

	if (!stack)
		return ;
	min_move_count = LONG_MAX;
	while (stack)
	{
		if (stack->move_count < min_move_count)
		{
			min_move_count = stack->move_count;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->least_moves = true;
}

void	scan_stack_a(t_stack *a, t_stack *b)
{
	get_index_and_direction(a);
	get_index_and_direction(b);
	set_target_a(a, b);
	set_move_count(a, b);
	set_least_moves(a);
}

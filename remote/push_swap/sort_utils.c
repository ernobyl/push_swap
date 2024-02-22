/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:28:04 by emichels          #+#    #+#             */
/*   Updated: 2024/02/09 16:27:08 by emichels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_stack(t_stack **stack)
{
	t_stack	*temp;
	int		count;

	count = 0;
	temp = *stack;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

bool	if_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*find_max_value(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*max_node;

	temp = stack;
	max_node = temp;
	while (temp != NULL)
	{
		if (temp->value > max_node->value)
			max_node = temp;
		temp = temp->next;
	}
	return (max_node);
}

t_stack	*find_min_value(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*min_node;

	temp = stack;
	min_node = temp;
	while (temp != NULL)
	{
		if (temp->value < min_node->value)
			min_node = temp;
		temp = temp->next;
	}
	return (min_node);
}

int	find_min_value_index(t_stack **stack)
{
	t_stack	*temp;
	int		min_value;
	int		min_index;
	int		i;

	temp = *stack;
	min_value = temp->value;
	min_index = 0;
	i = 0;
	while (temp != NULL)
	{
		if (temp->value < min_value)
		{
			min_value = temp->value;
			min_index = i;
		}
		temp = temp->next;
		i++;
	}
	return (min_index);
}

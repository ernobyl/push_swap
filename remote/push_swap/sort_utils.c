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

int count_stack(t_stack **stack)
{
	t_stack *temp;
	int count = 0;

	temp = *stack;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

int find_max_value_index(t_stack **stack)
{
	t_stack *temp;
	int max_value;
	int max_index;
	int i;

	temp = *stack;
	max_value = temp->value;
	max_index = 0;
	i = 0;
	while (temp != NULL)
	{
		if (temp->value > max_value)
		{
			max_value = temp->value;
			max_index = i;
		}
		temp = temp->next;
		i++;
	}
	return max_index;
}

int find_min_value_index(t_stack **stack)
{
	t_stack *temp;
	int min_value;
	int min_index;
	int i;

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
	return min_index;
}

void	move_to_top(t_stack **stack, int index, int size)
{
	if (index <= size / 2)
	{
		while (index > 0)
		{
			ra(stack);
			index--;
		}
	}
	else
	{
		while (index < size)
		{
			rra(stack);
			index++;
		}
	}
}
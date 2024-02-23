/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:47:32 by emichels          #+#    #+#             */
/*   Updated: 2024/02/22 11:38:05 by emichels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_last(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_second_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	rotate(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	*stack = (*stack)->next;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = first_node;
	first_node->next = NULL;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last_node;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last_node = stack_last(*stack);
	second_last = stack_second_last(*stack);
	tmp = *stack;
	*stack = last_node;
	(*stack)->next = tmp;
	second_last->next = NULL;
}

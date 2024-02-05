/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:47:32 by emichels          #+#    #+#             */
/*   Updated: 2024/02/05 15:25:53 by emichels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_stack	*first_node;
	t_stack	*last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last_node = *stack;
	while (last_node->next->next)
		last_node = last_node->next;
	first_node = last_node->next;
	last_node->next = NULL;
	first_node->next = *stack;
	*stack = first_node;
}
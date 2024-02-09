/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populating_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:16:41 by emichels          #+#    #+#             */
/*   Updated: 2024/02/09 12:21:21 by emichels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stacknew(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*temp;
	int		i;

	stack = stacknew(ft_atol(argv[1]));
	temp = stack;
	i = 2;
	while (i < argc)
	{
		temp->next = stacknew(ft_atol(argv[i]));
		if (!temp->next)
			return (NULL);
		temp = temp->next;
		i++;
	}
	return (stack);
}

t_stack	*fill_stack_single(int count, char **split_args)
{
	t_stack	*stack;
	t_stack	*temp;
	int		i;

	stack = stacknew(ft_atol(split_args[0]));
	temp = stack;
	i = 1;
	while (i < count)
	{
		temp->next = stacknew(ft_atol(split_args[i]));
		if (!temp->next)
			return (NULL);
		temp = temp->next;
		i++;
	}
	return (stack);
}

void	clear_stack(t_stack **stack)
{
	if (stack && *stack)
	{
		clear_stack(&(*stack)->next);
		free(*stack);
		*stack = NULL;
	}
}

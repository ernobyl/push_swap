/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:28:04 by emichels          #+#    #+#             */
/*   Updated: 2024/02/01 16:13:38 by emichels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_valid_args(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (i < argc)
	{
		k = i + 1;
		while (argv[k])
		{
			if (ft_strcmp(argv[i], argv[k]) == 0)
				return (-1);
			k++;
		}
		if (argv[i] == NULL || argv[i][0] == '\0')
			return (-1);
		i++;
	}
	return (0);
}
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

	stack = stacknew(ft_atoi(argv[1]));
	temp = stack;
	i = 2;
	while (i < argc)
	{
		temp->next = stacknew(ft_atoi(argv[i]));
		if (!temp->next)
			return (NULL);
		temp = temp->next;
		i++;
	}
	return (stack);
}

void	swap_a(t_stack *stack)
{
	int	tmp;
	
	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack	*b;
	
	if (argc < 2)
		return (0);
	if (check_valid_args(argc, argv) == -1)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	b = NULL;
	a = fill_stack(argc, argv);
	swap_a(a);
	while (a != NULL)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	return (0);
}
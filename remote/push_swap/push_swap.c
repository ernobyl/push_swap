/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:28:04 by emichels          #+#    #+#             */
/*   Updated: 2024/02/09 16:27:08 by emichels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_args(char *argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[i])
	{
		while (argv[i] && argv[i] == ' ')
			i++;
		if (argv[i])
			count++;
		while (argv[i] && argv[i] != ' ')
			i++;
	}
	return (count);
}

char	**args_single_string(char **argv)
{
	char	**split_result;
	int		argc;

	if (!argv[1])
		return (NULL);
	argc = count_args(argv[1]);
	if (argc == 0)
		return (NULL);
	split_result = ft_split(argv[1], ' ');
	if (check_valid_args(0, argc, split_result) == -1)
	{
		ft_free(split_result);
		return (NULL);
	}
	return (split_result);
}

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

void	flip(t_stack **stack, int k, int size)
{
	if (k <= size / 2)
	{
		while (k > 0)
		{
			rotate(stack);
			k--;
		}
	}
	else
	{
		while (k < size)
		{
			reverse_rotate(stack);
			k++;
		}
	}
}

void	pancake_sort(t_stack **stack)
{
	int	size;
	int	max_index;

	size = count_stack(stack);
	while (size > 0)
	{
		max_index = find_max_value_index(stack);
		if (max_index != size)
		{
			flip(stack, max_index, size);
			flip(stack, size, size);
			size--;
		}
		reverse_rotate(stack);
		size--;
	}
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack	*b;
	char	**split_result;
	
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		split_result = args_single_string(argv);
		if (!split_result)
			return (error_message());
		a = fill_stack_single(count_args(argv[1]), split_result);
		ft_free(split_result);
	}
	else
	{
		if (check_valid_args(1, argc, argv) == -1)
			return (error_message());
		a = fill_stack(argc, argv);
	}
	b = NULL;
	// testing stuff from this point onwards
	// swap(&a);
	// push(&a, &b);
	// push(&a, &b);
	// push(&a, &b);
	// rotate(&a);
	// reverse_rotate(&b);
	//sort_two_three(argc, &a, argv);
	pancake_sort(&a);
	t_stack	*tmp_a = a;
	printf("Stack A:\n");
	while (tmp_a != NULL)
	{
		printf("%d\n", tmp_a->value);
		tmp_a = tmp_a->next;
	}
	printf("Stack B:\n");
	while (b != NULL)
	{
		printf("%d\n", b->value);
		b = b->next;
	}
	// testing ends here
	clear_stack(&a);
	return (0);
}

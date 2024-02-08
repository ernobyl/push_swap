/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:28:04 by emichels          #+#    #+#             */
/*   Updated: 2024/02/08 14:08:31 by emichels         ###   ########.fr       */
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

int	isdigit_or_sign(int c)
{
	if ((c >= 48 && c <= 57) || c == 43 || c == 45)
		return (1);
	else
		return (0);
}

int	check_valid_args(int argpos, int argc, char **argv)
{
	int	i;
	int	k;
	int	n;

	i = argpos;
	while (i < argc)
	{
		if ((argpos == 1 && argc > 2) || (argpos == 0 && argc > 0))
		{
			k = i + 1;
			while (argv[k])
			{
				if (ft_strcmp(argv[i], argv[k]) == 0)
					return (-1);
				k++;
			}
		}
		n = 0;
		while (argv[i][n])
		{
			if (!isdigit_or_sign(argv[i][n]))
				return (-1);
			n++;
		}
		if (argv[i] == NULL || argv[i][0] == '\0')
			return (-1);
		if (ft_atol(argv[i]) < -2147483648 || ft_atol(argv[i]) > 2147483647)
			return (-1);
		i++;
	}
	return (0);
}

int	error_message(void)
{
	write(2, "Error\n", 6);
	return (0);
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
	// swap(a);
	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	rotate(&a);
	reverse_rotate(&b);
	printf("Stack A:\n");
	while (a != NULL)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	printf("Stack B:\n");
	while (b != NULL)
	{
		printf("%d\n", b->value);
		b = b->next;
	}
	// testing ends here
	return (0);
}
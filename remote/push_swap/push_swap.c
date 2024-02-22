/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:28:04 by emichels          #+#    #+#             */
/*   Updated: 2024/02/22 14:07:02 by emichels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_args(char *argv)
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

static char	**args_single_string(char **argv)
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

static void	perform_sorting(t_stack *a, t_stack *b)
{
	sort_two(&a);
	sort_three(&a);
	sort_stacks(&a, &b);
	clear_stack(&a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_result;

	a = NULL;
	b = NULL;
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
	perform_sorting(a, b);
	return (0);
}

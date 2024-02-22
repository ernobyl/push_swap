/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:45:21 by emichels          #+#    #+#             */
/*   Updated: 2024/02/22 11:06:31 by emichels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isdigit_or_sign(int c)
{
	if ((c >= 48 && c <= 57) || c == 43 || c == 45)
		return (1);
	else
		return (0);
}

static int	is_sign(int c)
{
	if (c == 43 || c == 45)
		return (1);
	else
		return (0);
}

static int	check_digits(int i, char **argv)
{
	int	n;

	n = 0;
	if (!isdigit_or_sign(argv[i][0]) || (is_sign(argv[i][0])
		&& !ft_isdigit(argv[i][1])))
		return (0);
	n++;
	while (argv[i][n])
	{
		if (!ft_isdigit(argv[i][n]))
			return (0);
		n++;
	}
	return (1);
}

int	check_valid_args(int argpos, int argc, char **argv)
{
	int	i;
	int	k;

	i = argpos;
	while (i < argc)
	{
		if ((argpos == 1 && argc > 2) || (argpos == 0 && argc > 0))
		{
			k = i + 1;
			while (argv[k])
			{
				if (ft_atoi(argv[i]) == ft_atoi(argv[k]))
					return (-1);
				k++;
			}
		}
		if (!check_digits(i, argv))
			return (-1);
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

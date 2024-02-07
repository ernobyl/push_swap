/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:29:45 by emichels          #+#    #+#             */
/*   Updated: 2024/02/05 16:57:29 by emichels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // for now included only for printf, remove at some point
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

void	swap(t_stack *stack);
void	push(t_stack **from, t_stack **to);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

#endif

/*
pelkällä ykkösellä antaa tällä hetkellä errorin
checklist:
	"In case of error, display "Error" followed by a ’\n’ on the standard error.
	Errors include for example: some arguments aren’t integers, some arguments are
	bigger than an integer and/or there are duplicates."

	- error check for an empty string ("") as an argument - done
	- error check for duplicates (strcmp to check for duplicates?) - done
	- error check for max and min ints, maybe modify ft_atoi (also over/under max/min) - done
	- check if the arguments are a single string "1 2 3" (ft_split) - should be working
	- check if there are non-numerical arguments - done
	- program should display nothing if run with no arguments - done

project plan:
	- create the stacks - done
	- implement swap, rotate, reverse rotate, push - basic operations done
	- choose sorting algorithm
	- implement sorting algorithm
	- test with checker
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:29:45 by emichels          #+#    #+#             */
/*   Updated: 2024/02/01 16:12:15 by emichels         ###   ########.fr       */
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


#endif

/*
checklist:
	"In case of error, display "Error" followed by a ’\n’ on the standard error.
	Errors include for example: some arguments aren’t integers, some arguments are
	bigger than an integer and/or there are duplicates."

	- error check for an empty string ("") as an argument - done (I think)
	- error check for duplicates (strcmp to check for duplicates?) - done (I think)
	- error check for max and min ints (also over/under max/min)

project plan:
	- create the stacks
	- implement swap, rotate, reverse rotate, push
	- choose sorting algorithm
	- implement sorting algorithm
	- test with checker
*/
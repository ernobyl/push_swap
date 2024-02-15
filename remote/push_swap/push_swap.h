/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:29:45 by emichels          #+#    #+#             */
/*   Updated: 2024/02/09 12:24:36 by emichels         ###   ########.fr       */
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

/* general */
int		count_args(char *argv);

/* operations */
void	swap(t_stack **stack);
void	push(t_stack **from, t_stack **to);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* sorting */
int 	count_stack(t_stack **stack);
t_stack *find_max_value(t_stack **stack);
int 	find_min_value_index(t_stack **stack);
void	move_to_place(t_stack **stack, int index, int size);
void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
void	selection_sort(t_stack **a, t_stack **b);

/* error handling */
int		isdigit_or_sign(int c);
int		check_valid_args(int argpos, int argc, char **argv);
int		error_message(void);

/* stack handling */
t_stack	*stacknew(int value);
t_stack	*fill_stack(int argc, char **argv);
t_stack	*fill_stack_single(int count, char **split_args);
void	clear_stack(t_stack **stack); // <-- probably doesn't work, check later

#endif

/*
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
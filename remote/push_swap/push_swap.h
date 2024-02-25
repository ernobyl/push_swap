/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emichels <emichels@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:29:45 by emichels          #+#    #+#             */
/*   Updated: 2024/02/22 14:14:48 by emichels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef enum e_direction
{
	up,
	down
}	t_direction;

typedef struct s_stack
{
	int				value;
	int				index;
	int				move_count;
	bool			least_moves;
	struct s_stack	*next;
	struct s_stack	*target;
	t_direction		move;
}	t_stack;

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
void	rr_to_place(t_stack **a, t_stack **b, t_stack *cheapest);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	reverse_to_place(t_stack **a, t_stack **b, t_stack *cheapest);
void	prep_for_push(t_stack **stack, t_stack *top, char stackname);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);

/* sorting */
bool	if_sorted(t_stack *stack);
int		count_stack(t_stack **stack);
t_stack	*find_max_value(t_stack *stack);
t_stack	*find_min_value(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_stacks(t_stack **a, t_stack **b);
void	get_index_and_direction(t_stack *stack);
void	set_target_a(t_stack *a, t_stack *b);
void	set_target_b(t_stack *a, t_stack *b);
void	set_move_count(t_stack *a, t_stack *b);
void	set_least_moves(t_stack *stack);
void	scan_stack_a(t_stack *a, t_stack *b);
void	scan_stack_b(t_stack *a, t_stack *b);

/* error handling */
int		check_valid_args(int argpos, int argc, char **argv);
int		error_message(void);

/* stack handling */
t_stack	*stacknew(int value);
t_stack	*fill_stack(int argc, char **argv);
t_stack	*fill_stack_single(int count, char **split_args);
void	clear_stack(t_stack **stack);

#endif

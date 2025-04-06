/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:29:57 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/06 03:40:25 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				value;//integer value
	int				position;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;//number in the stack, node of the DLL

typedef struct s_stack
{
	t_node	*head;//top element of the struct
	t_node	*tail;//bottom element
	int		stack_size;//track of number of input
}	t_stack;//manages linked list

typedef struct s_cost
{
	int	cost_a;
	int	cost_b;
	int	totalcost;
	int	position_b;
	int	target_a;
}	t_cost;

//stack init and manageent
t_stack	*init_stack(void);
t_node	*new_node(int value);
t_node	*remove_head(t_stack *stack);
void	add_head(t_stack *stack, t_node *node);
void	add_tail(t_stack *stack, t_node *node);
int		is_sorted(t_stack *stack);


//sorting algo
void	sort_stack(t_stack **stack);
void	three_sort(t_stack **a);
void	four_sort(t_stack **a, t_stack **b);
void	five_sort(t_stack **a, t_stack **b);
void	chunk_sort(t_stack **a, t_stack **b, int chunk_size);
void	chunk_to_b(t_stack **a, t_stack **b, int chunksize);
void	chunk_to_a(t_stack **a, t_stack **b, int chunksize);
void	binary_insert_sort(t_stack **a, t_stack **b);
t_cost	find_cheapest(t_stack **a, t_stack **b);
int		find_target(int position_b, t_stack *a, int size);
void	find_pivot(t_stack *stack, int *pivot, int size);
void	minisort(t_stack *a, t_stack *b);
void	hybrid_radix_chunk(t_stack **a, t_stack **b, int chunk_size);
void	merge_chunks(t_stack **a, t_stack **b);
void	best_move(t_stack *a, t_stack *b);
void	ultimate_sorter(t_stack **a, t_stack **b);

//input handling
int		parse_input(int argc, char **argv, t_stack *a, t_stack *b);
void	fill_stack(t_stack *stack, int argc, char *argv[]);
void	assign_rank(t_stack *stack);
void	assign_pos(t_stack **a, int size);
int		is_valid_digit(char *str);
int 	has_dup(t_stack *stack, int value);
int 	is_valid_arg(int split, t_stack *a, t_stack *b);

//utils
void	free_stack(t_stack **stack);
void	print_stack(t_stack *stack);
void	error_exit(const char *msg, t_stack *a, t_stack *b);
int		ft_isdigit(int c);
int		is_overflow(char *str);


//stack operations
void	push(t_stack **src, t_stack **dest);
void	swap(t_stack **stack);
void	rot_up(t_stack **stack);
void	rot_down(t_stack **stack);
void	split_stack(t_stack *stack);//into smaller chunks - if <10 <100 <500
int 	calc_cost(t_stack *a, t_stack *b, int value);

//operations specific
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//tests^^
//cost calculating functions of moving elements betwwen stacks-greedy
//position tracking functions-at input?
//algorithm selecion logic criteria based on input size
//stack visualization/debugging helpers

#endif
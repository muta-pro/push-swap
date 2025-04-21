/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:29:57 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/21 22:36:19 by imutavdz         ###   ########.fr       */
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
}	t_node; //number in the stack, node of the DLL

typedef struct s_stack
{
	t_node	*head;//top element of the struct
	t_node	*tail;//bottom element
	int		stack_size;//track of number of input
}	t_stack; //manages linked list

typedef struct s_cost
{
	int	cost_a;
	int	cost_b;
	int	totalcost;
	int	position_b;
	int	target_a;
}	t_cost;

//stack init and manageent
t_stack		*init_stack(void);
t_node		*new_node(int value);
t_node		*remove_head(t_stack *stack);
t_node		*remove_tail(t_stack *stack);
void		add_head(t_stack **stack, t_node *node);
void		add_tail(t_stack **stack, t_node *node);
int			is_sorted(t_stack *stack);
void		free_node(t_node *node);


//sorting algo
void		minisort(t_stack *a, t_stack *b, int size);
void		three_sort(t_stack *a);
void		four_sort(t_stack **a, t_stack **b);
void		five_sort(t_stack **a, t_stack **b);
void		chunk_sort(t_stack **a, t_stack **b, int chunk_size);
void		chunk_to_b(t_stack **a, t_stack **b, int start_pos, int end_pos);
void		back_to_a(t_stack **a, t_stack **b);
void		ultimate_sorter(t_stack **a, t_stack **b);
void		sort_arr(int *arr, int stack_size);
void		recurs_sort_arr(int *arr, int low, int high);
// void 		limit_fivehynderet_chunking(t_stack **a, t_stack **b);
// void 		limit_hundert_chunking(t_stack **a, t_stack **b);
// void		hybrid_radix_chunk(t_stack **a, t_stack **b, int chunk_size);

//optimization
int			find_target(int position_b, t_stack *a, int size);/////////
t_cost		find_cheapest(t_stack **a, t_stack **b);///////////
void		best_move(t_stack *a, t_stack *b);////////////
int 		calc_cost(t_stack *a, t_stack *b, int position);/////////////
int 		min_value(t_stack *stack);
int			max_value(t_stack *stack);////////////
int			count_chunked(t_stack *a, int start, int end);
int			find_t_distance(t_stack *a, int start_pos, int end_pos);
int			find_b_distance(t_stack *a, int start_pos, int end_pos);


//input handling
int			valid_input(int argc, char **argv, t_stack **stack);
int			fill_stack(t_stack **stack, long long *holder, int size);
void		assign_rank(t_stack *stack, int *arr, int size);
void		assign_pos(t_stack *a, int size);
int			is_valid_digit(const char *str);
int			has_dup(long long *holder, int size);
int			is_valid_arg(const char *str, long long *values);
long		ft_atol_ps(const char *str, int *overflow);

//utils
void		free_stack(t_stack **stack);
void		clean_exit(const char *msg, t_stack **a, t_stack **b, void *ptr);
void		print_stack(t_stack *stack);
int			ft_isdigit(int c);
int			is_overflow(long long result, int sign);
void		move_values(t_stack *a, int *arr);
void		ft_swap(int *a, int *b);
int			bisearch(int *arr, int stack_size, int target);
int			partition(int *arr, int low, int high);


//stack operations
void		push(t_stack **src, t_stack **dest);
void		swap(t_stack **stack);
void		rot_up(t_stack **stack);
void		rot_down(t_stack **stack);
// void		split_stack(t_stack *stack);//into smaller chunks - if <10 <100 <500

//operations specific
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **b, t_stack **a);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

#endif
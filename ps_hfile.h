/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hfile.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:29:57 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/24 13:15:08 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_HFILE_H
# define PS_HFILE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
// # include "libft/libft.h"

typedef struct	s_node
{
	int				value;//integer value
	struct s_node	*next;
	struct s_node	*prev;
} t_node;//number in the stack, node of the DLL

typedef struct	s_stack
{
	t_node	*head;//top element of the struct
	t_node	*tail;//bottom element
	int		stack_size;//track of number of input
} t_stack;//manages linked list

//stack init and manageent
t_stack	*init_stack(void);
t_node	*new_node(int value);
void	free_stack(t_stack **stack);
int		is_sorted(t_stack *stack);

//stack operations
void	push(t_stack *src, t_stack *dest);
void	swap(t_stack *stack);
void	rot_up(t_stack *stack);
void	rot_down(t_stack *stack);
void	split_stack(t_stack *stack);//into smaller chunks - if <10 <100 <500

//sorting algo
void	sort_stack(t_stack **stack);
void	chunk_sort(t_stack **a, t_stack **b, int chunk_size);
void	binary_insert_sort(t_stack **a, t_stack **b);
void	greedy_sort(t_stack **a, t_stack **b);
void	find_alg(t_stack **a, t_stack **b, int size);
void	find_pivot(t_stack *stack, int *pivot, int size);
void	minisort(t_stack *a);
void	hybrid_radix_chunk(t_stack **a, t_stack **b, int chunk_size);
void	merge_chunks(t_stack **a, t_stack **b);

//input handling
int		parse_input(int argc, char **argv, t_stack **a);
void	print_error(void);

//operations specific
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *b, t_stack *a);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

//cost calculating functions of moving elements betwwen stacks
//position tracking functions
//algorithm selecion logic criteria based on input size
//stack visualization/debugging helpers

#endif
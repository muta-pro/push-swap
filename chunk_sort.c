/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:21:36 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/17 01:52:27 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"
//divide input into parts, push and sort smaller chunks efficiently
//optimize rotations and push operations
//split stack A into partitions
//chunk_size based on input size
//move each to stack B
//finding shortest path to reach elements
//sort_chunks insert_sort or select_sort
//merge stack pushing to stack A
//hybrid strategy - prepocessing step
//user  radix on final pass
//count comparisons try to minimize - choose algo
//alg complexity should match problems lower bound
//stack sorting - greedy sort, binary insert sort, divide&concq
//find O(N log N) method
//sort each chunk with insertion sort or selection sort
//greedy sort find best order to push numbers back 
//quicksort partitioning
int	get_chunkcount(int stack_size)
{
	if (stack_size <= 10)
		return (2);
	else if (stack_size <= 100)
		return (5);
	else
		return (11);
}

void	chunk_to_b(t_stack **a, t_stack **b, int start_pos, int end_pos)
{
	int	chunksize;
	int	top_dist;
	int	bottom_dist;
//find_cheapest to move funciotn
	top_dist = find_t_distance(*a, start_pos, end_pos);
	bottom_dist = find_b_distance(*a, start_pos, end_pos);
	if (top_dist == -1 && bottom_dist == -1)
		return ;
	if ((top_dist != -1 && top_dist <= bottom_dist) || bottom_dist == -1)
	{
		while (top_dist-- > 0)
			ra(a);
	}
	else
	{
		while (bottom_dist-- > 0)
			rra(a);
	}
	chunksize = end_pos - start_pos;
	pb(b, a);
	if ((*b)->head->position < start_pos + chunksize / 2)
		rb(b);
}

int	count_chunked(t_stack *a, int chunk_start, int chunk_end)
{
	t_node	*current;
	int		count;

	count = 0;
	current = a->head;
	while (current)
	{
		if (current->position >= chunk_start && current->position <= chunk_end)
			count++;
		current = current->next;
	}
	return (count);
}

void back_to_a(t_stack *a, t_stack *b)
{
	best_move(find_cheapest(calc_cost()));
	rr();rrr();rb();ra();
	pa();

	//pushing back elemets that require fewest moves
	//use target position in A do determine optimal positoin
	//calc combined costs for both stacks
}

void	chunk_sort(t_stack **a, t_stack **b, int stack_size)
{
	int		chunksize;
	int		chunkcount;
	int		chunk_start;
	int		chunk_end;

	chunkcount = get_chunkcount(stack_size);
	chunksize = stack_size / chunkcount;
	chunk_start = 0;
	chunk_end = chunksize - 1;
	while ((*a)->stack_size > 3)
	{
		chunk_to_b(a, b, chunk_start, chunk_end);
		if (count_chunked(*a, chunk_start, chunk_end) == 0)
		{
			chunk_start += chunksize;
			chunk_end += chunksize;
			if (chunk_end >= stack_size)
				chunk_end = stack_size - 1;
		}
	}
	if ((*a)->stack_size == 3)
		three_sort(*a);
	back_to_a(a, b);
}

// void	hundert_chunking(t_stack **a, t_stack **b)
// {

// }
// void	fivehunderet_chunking(t_stack **a, t_stack **b);

// void	chunk_to_a(t_stack **a, t_stack **b, int chunksize);
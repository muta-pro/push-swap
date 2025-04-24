/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:21:36 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/24 20:20:36 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"
//optimize rotations and push operations
//split stack A into partitions
//chunk_size based on input size
//move each to stack B
//finding shortest path to reach elements
//merge stack pushing to stack A
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

//Analyzes all elements in the current chunk.
//calc total cost A and B
//calc distance from the top before pushing
//find_cheapest to move funciotn
//best element based on rotation cost
//minimum movement execution
void	chunk_to_b(t_stack **a, t_stack **b, int start_pos, int end_pos)
{
	t_cost	cheapest;

	while (count_chunked(*a, start_pos, end_pos) > 0)
	{
		cheapest = find_cheapest(a, b, start_pos, end_pos);
		best_move(a, b, cheapest);
	}
}

//count how many elem are processing in this range
//pointer to loop through stack
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

//use target position in A do determine optimal positoin
//calc combined costs for both stacks
void	back_to_a(t_stack **a, t_stack **b)
{
	int	b_size;
	int	pos;
	int	cost_b;

	while ((*b)->head != NULL) //while B not empty
	{
		b_size = (*b)->stack_size;
		pos = max_value(*b);
		if (pos <= b_size / 2)
			cost_b = pos;
		else
			cost_b = -(b_size - pos);
		best_move_b(b, cost_b);
		pa(a, b);
	}
}

void	chunk_sort(t_stack **a, t_stack **b, int stack_size)
{
	int		chunk_size;
	int		chunkcount;
	int		chunk_start;
	int		chunk_end;

	chunkcount = get_chunkcount(stack_size); //how many chunks we need
	chunk_size = stack_size / chunkcount; //how many elements are there
	chunk_start = 0; //range of first chunk
	chunk_end = chunk_size - 1;
	while ((*a)->stack_size > 3)
	{
		chunk_to_b(a, b, chunk_start, chunk_end);
		if (count_chunked(*a, chunk_start, chunk_end) == 0) //no elements left in range
		{
			chunk_start += chunk_size; //here we move to the next chunk
			chunk_end += chunk_size;
			if (chunk_end >= stack_size) //not going over limit size
				chunk_end = stack_size - 1;
		}
	}
	if ((*a)->stack_size == 3)
		three_sort(*a);
	ft_putendl_fd("--- ENTERING back_to_a ---", 1);
	back_to_a(a, b);
}

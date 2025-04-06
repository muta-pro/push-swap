/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:21:36 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/05 19:21:23 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"
//divide input into parts, push and sort smaller chunks efficiently
//optimize rotations and push operations
//split stack A into partitions
//chunk_size based on input size
//move each to stack B
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
void	chuncksort(t_stack **a, t_stack **b, int chunksize)
{

	search_ medium
		
}

void chunk_to_b(t_stack **a, t_stack **b, int chunksize);
void chunk_to_a(t_stack **a, t_stack **b, int chunksize);

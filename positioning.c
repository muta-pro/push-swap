/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:37:51 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/12 21:58:29 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
OBJECTIVE; assign position index to each node, 
where position is the node's rank in the sorted stack
we use curr so we don't modify drectly head, insted only curr
we sort using recursive function quicksort
using binary search to find the target value in a sorted array and return rank
assigning position to each node
*/
#include "ps.h"

void	move_values(t_stack *a, int *arr)
{
	t_node	*curr;
	int		i;

	curr = a->head;
	i = 0;
	if (!a || !arr)
		return ;
	while (curr)
	{
		arr[i] = curr->value;
		curr = curr->next;
		i++;
	}
}

void	assign_rank(t_stack *a, int *arr, int stack_size)
{
	t_node	*curr;

	curr = a->head;
	while (curr)
	{
		curr->position = bisearch(arr, stack_size, curr->value);
		curr = curr->next;
	}
}

int	bisearch(int *arr, int stack_size, int target)
{
	int	start;
	int	end;
	int	middle;

	start = 0;
	end = stack_size - 1;
	while (start <= end)
	{
		middle = (start + end) / 2;
		if (arr[middle] == target)
			return (middle);
		else if (arr[middle] < target)
			start = middle + 1;
		else
			end = middle - 1;
	}
	return (-1);
}

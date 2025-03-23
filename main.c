/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:28:19 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/23 18:38:55 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//error handling
//arguments handling - integers
//chinking for initial distribution of elements
//target position calculation
//optimization for each move
//handling of edge cases

void ultimate_sorter(t_stack *a, t_stack *b)
{
	int size;

	size = a->size;
	if (size <= 5)
	{
		minisort(a);//bubble sort / insertion sort for stack
		return;
	}
	if (size <= 50)
	{
		chunksort(a, b);//greedy sort
		return;
	}
	else
		megasort_hybrid(a, b);//binary search / radixsort / chunksort
}

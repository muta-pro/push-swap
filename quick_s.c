/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:55:00 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/12 21:57:47 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"
/*functions that implement the quicksort alg to sort an array of int
these will be assigned positions for each node*/

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[(high + low) / 2];
	i = low;
	j = high;
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			ft_swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}
	return (i);
}

void	recurs_sort_arr(int *arr, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high);
		recurs_sort_arr(arr, low, pivot_index - 1);
		recurs_sort_arr(arr, pivot_index, high);
	}
}

void	sort_arr(int *arr, int stack_size)
{
	if (!arr || stack_size < 2)
		return ;
	recurs_sort_arr(arr, 0, stack_size - 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:28:19 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/09 05:41:49 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"
/*
** Program Flow:
* 1. Parse and validate arguments - check for dup
* 2. Build stacks with position assignment
* 3. Check if already sorted
* 4. Choose sorting algorithm based on size
* 5. Execute chosen sorting algorithm
* 6. Free memory and exit
*/
void	ultimate_sorter(t_stack **a, t_stack **b)
{
	int	size;

	assign_pos(a, (*a)->stack_size);
	size = (*a)->stack_size;
	if (size <= 1)
		return ;
	else if (size <= 5)
		minisort(a, b); //bubble sort / insertion sort for stack
	else if (size <= 100)
		chunk_sort(a, b, 20); //greedy sort
	else
		hybrid_radix_chunk(a, b, clac_chunksize(size)); //binary search / radixsort / chunksort
}

//should call sorting based on input size
int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	int			size;

	if (argc < 2)
		return (0);
	size = argc - 1;
	a = init_stack();
	if (!a)
		return (0);
	if (!valid_input(argc, argv, a))
		clean_exit("Error\n", &a, NULL, NULL);
	b = init_stack();
	if (!b)
		return (clean_exit("Error\n", &a, NULL, NULL));
	assign_pos(&a, size);
	if (a->stack_size > 1 && !is_sorted(a))
		ultimate_sorter(&a, &b);
	else
	{
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}

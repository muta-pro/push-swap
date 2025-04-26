/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:28:19 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/26 03:18:43 by imutavdz         ###   ########.fr       */
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
	if ((*a)->stack_size > 1 && !is_sorted(*a))
	{
		if ((*a)->stack_size <= 5)
			minisort(*a, *b, (*a)->stack_size);
		else if ((*a)->stack_size > 5)
			greedy_sort(a, b);
		else
			clean_exit("Error\n", a, b, NULL);
	}
	else
		clean_exit("Error\n", a, b, NULL);
}

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	size_t total_moves;

	if (argc < 2)
		return (0);
	a = init_stack();
	if (!a)
		return (0);
	if (!valid_input(argc, argv, &a))
		clean_exit("Error\n", &a, NULL, NULL);
	b = init_stack();
	if (!b)
		clean_exit("Error\n", &a, NULL, NULL);
	assign_pos(a, a->stack_size);
	ultimate_sorter(&a, &b);
    // --- Print total moves ---
    total_moves = get_move_count(false); // Get final count without incrementing
    ft_putstr_fd("Total moves: ", 1);
    ft_putnbr_fd(total_moves, 1); // Assuming ft_putnbr_fd works with size_t or int
    ft_putendl_fd("", 1);
    // --- End print total ---
	free_stack(&a);
	free_stack(&b);
	return (0);
}

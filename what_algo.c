/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:38:55 by imutavdz          #+#    #+#             */
/*   Updated: 2025/04/09 01:27:09 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
algorythm selection logic
based on input size
*/
#include "ps.h"

void	minisort(t_stack *a, t_stack *b, int size)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		three_sort(a);
	else if (size == 4)
		four_sort(a, b);
	else if (size == 5)
		five_sort(a, b);
}

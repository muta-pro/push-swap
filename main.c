/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:31:37 by imutavdz          #+#    #+#             */
/*   Updated: 2025/02/22 20:19:14 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ultimate_sorter(t_stack *a, t_stack *b)
{
	int size;

	size = a->size;
	if (size <= 3)
	{
		minisort(a);
		return;
	}
	if (size <= 50)
	{
		chunksort(a, b);
		return;
	}
	else
		megasort_hybrid(a, b);
}
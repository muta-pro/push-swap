/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:31:37 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/14 16:53:57 by imutavdz         ###   ########.fr       */
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
int main(int argc, char **argv)
{
	if (argc < 2)
		return (-1);
	
}
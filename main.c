/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:31:37 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/22 23:01:23 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//intput parsing into stack A
//check for valid int, duplicates, error handling
int main(int argc, int **argv[])
{
	int i;

	t_stack *a = new_stack();
	t_stack *b = new_stack();
	i = 1;
	while (i < argc)
	{
		append_node(a, atoi(argv[i]));
		i++;
	}
	return (0);
}

void ultimate_sorter(t_stack *a, t_stack *b)
{
	int size;

	size = a->size;
	if (size <= 5)
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
//inegrate operations into algorithm
//PRINT OUT OR LOG OPERATIONS AS THEY EXECUTE - CHECKER
//HOW TO CHECK THE STATE OF BOTH STACKS - ALG DETECTING
//CREATE SCENARIOS WHERE ALG USES THE COMBINED COMMANDS.
//BUILD CHECKER PROGRAM
//CHECK THAT BOTH STACKS ALIGN DURING ALG DESIGN
//like chunking or an optimized insertion sort
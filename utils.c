/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:20:49 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/24 13:15:11 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int is_sorted(t_stack *stack)
{
	int current;

	if (!stack || !stack->head)
		return ;
	current = stack->head;
	while (stack->next)
	{
		if (current->value > stack->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int min_value(t_stack *stack)
{
	t_node	*current;
	int 	min;

	if (!stack->head)
		return (0);
	current = stack->head;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
			current = current->next;
	}
	return (min);
}
int max_value(t_stack *stack);
{
	t_node *current;
	int max;

	if (!stack->head)
		return (0);
	current = stack->head;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
			current = current->next;
	}
	return (max);
}

int position_value(t_stack *stack, t_node value)
{
	int current;
	int position;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	position = 0;
	while (current)
	{
		if (current->value == value)
			return (position);
		current = current->nextl
		position++;
	}
	return (-1);
}

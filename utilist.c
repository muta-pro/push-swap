/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:38:01 by imutavdz          #+#    #+#             */
/*   Updated: 2025/02/22 19:58:01 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
static void	free_node(int value)
{
	t_node	prev;
	t_node	curr;

	prev = NULL;
	curr = ?

}
t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->uppest = NULL;
	stack->lowest = NULL;
	stack->size = 0;
	return (stack);
}

int min_value(t_stack stack)
{
	t_node	*current;
	int 	min;

	if (!stack->uppest)
		return (-1);
	current = stack->uppest;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
			current = current->next;
	}
	return (min);
}
int max_value(int value);
{
	t_node *current;
	int max;

	if (!stack->uppest)
		return (-1);
	current = stack->uppest;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
			current = current->next;
	}
	return (max);
}

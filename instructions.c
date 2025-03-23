/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:53:06 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/23 18:38:28 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void rot_up(t_stack **stack)
{
	t_node *prev_up;
	t_node *next_up;
	t_node *prev_low;

	if (!stack->head || !stack->head->next)
		return;
	prev_up = stack->head;
	prev_low = stack->tail;
	next_up = stack->head->next;
	stack->top = new_top;
    stack->bottom = old_top;
    old_tail->next = old_top;
    old_top->prev = old_tail;
    old_top->next = NULL;
}

void push(t_stack **dest, t_stack **src)
{
	t_node *node;

	node = new_node(value);
	if (!node)
		return ;
	if (!stack->head)
	{
		stack->tail = node;
		stack->head = node;
	}
	else
	{
		node->prev = stack->head;
		stack->head->next = node;
		stack->head = node;
	}
	stack->size++;
}
void pa(stack *a, stack *b)
{
	if (b->head >= 0)
	{
		a->[++(a->head)] = b->
	}
}

void swap(t_stack **stack)//single stack operations sa sb
{
	t_stack *first;
	t_stack *second;
	if ((!*stack) || !((*stack)->next))
		retutn;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void swapboth();//combined swap ss
void rot_down(t_stack **stack); // reverse rotate rra rrb rrr
//WRITE TEST FUNCTIONS
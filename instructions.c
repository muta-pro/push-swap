/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:53:06 by imutavdz          #+#    #+#             */
/*   Updated: 2025/03/23 21:53:07 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void ra(t_stack **a)
{
	rot_up(&a)
}
void rb(t_stack **b)
{
	rot_up(&b);
}
void rot_up(t_stack *stack)
{
	t_node *holder;

	if (!stak || !stack->head || !stack->head->next)
		return ;
	holder = stack->head; //node to be moved at the bottom
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	stack->tail->next = holder;
	stack->prev = stack->tail;
	temp->next = NULL;
	stack->tail = temp;
}

void pa(t_stack *a, t_stack *b)
{
	push(&a, &b);
}
void pb(t_stack *b, t_stack *a)
{
	push(&b, &a);
}

void push(t_stack **dest, t_stack **src)
{
	t_node *node;

	node = new_node(value);
	if (!node || !src || !*src || !(*src)->head || !dest || !dest)
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
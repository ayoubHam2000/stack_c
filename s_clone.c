/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_clone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:10:56 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/15 15:55:58 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*s_empty_stack(t_stack *stack)
{
	t_stack	*new_stack;
	t_node	*node;

	new_stack = s_init();
	if (!new_stack)
		return (NULL);
	node = stack->top;
	while (node)
	{
		if (!s_push(new_stack, NULL))
		{
			s_clear(new_stack, NULL);
			free(new_stack);
			return (NULL);
		}
		node = node->next;
	}
	return (new_stack);
}

t_stack	*s_clone(t_stack *stack, void *(*clone_ptr)(void *p))
{
	t_stack	*new_stack;
	t_node	*node;
	t_node	*new_node;

	new_stack = s_empty_stack(stack);
	if (!new_stack)
		return (NULL);
	node = stack->top;
	new_node = new_stack->top;
	while (node)
	{
		if (node->p && clone_ptr)
			new_node->p = clone_ptr(node->p);
		node = node->next;
		new_node = new_node->next;
	}
	return (new_stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_clear.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:03:08 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/15 13:34:20 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	default_del_ptr(void *p)
{
	free(p);
}

void	s_clear(t_stack *stack, void (*del_ptr)(void *p))
{
	t_node	*node;
	t_node	*target;

	if (!stack)
		return ;
	if (!del_ptr)
		del_ptr = default_del_ptr;
	node = stack->top;
	while (node)
	{
		target = node;
		node = node->next;
		del_ptr(target->p);
		free(target);
	}
	stack->top = NULL;
}

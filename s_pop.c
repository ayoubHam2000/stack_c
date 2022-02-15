/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_pop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:52:27 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/15 11:56:53 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	*s_pop(t_stack *stack)
{
	t_node	*node;
	void	*p;

	node = stack->top;
	p = NULL;
	if (node)
	{
		stack->top = node->next;
		p = node->p;
		free(node);
	}
	return (p);
}

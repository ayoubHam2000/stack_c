/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:52:48 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/15 16:09:05 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

void	*p_int(int a)
{
	int	*p;

	p = malloc(4);
	*p = a;
	return (p);
}

void	*c_int(void *p)
{
	int	*n;

	n = malloc(4);
	*n = *((int *)p);
	return (n);
}

int	main(void)
{
	t_stack	*stack;
	void	*p;

	stack = s_init();
	s_push(stack, p_int(10));
	s_push(stack, p_int(13));
	s_push(stack, p_int(19));
	p = s_pop(stack);
	while (p)
	{
		if (p)
			printf("%d <- ", *((int *)(p)));
		free(p);
		p = s_pop(stack);
	}
	printf("\n");
	system("leaks stack");
	return (0);
}

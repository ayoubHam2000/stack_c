/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:53:12 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/15 16:11:35 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node	t_node;
struct s_node
{
	void	*p;
	t_node	*next;
};

typedef struct s_stack	t_stack;
struct s_stack
{
	t_node	*top;
	long	len;
};

//NULL if malloc failed
void	*s_init(void);

//free the pointer after you pop it.
void	*s_pop(t_stack *stack);

//0 if s_push malloc failed
int		s_push(t_stack *stack, void *p);

/*
* NULL if the creating of Nodes failed
* if clone_ptr is NULL => all pointers of the cloned stack will be NULL
*/
t_stack	*s_clone(t_stack *stack, void *(*clone_ptr)(void *p));
void	s_clear(t_stack *stack, void (*del_ptr)(void *p));

#endif

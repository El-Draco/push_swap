/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriyas <rriyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:24:43 by rriyas            #+#    #+#             */
/*   Updated: 2022/06/15 20:50:29 by rriyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first_two(t_stack *s, char ch)
{
	struct s_stack	*temp;

	if (!*s || !(*s)->next)
		return ;
	temp = (*s)->next;
	(*s)->next = temp->next;
	temp->next = *s;
	*s = temp;
	write(1, "s", 1);
	write(1, &ch, sizeof(char));
	write(1, "\n", 1);
}

//  shift up all elements by one:
void	rotate(t_stack *s, char ch)
{
	struct s_stack	*temp;
	struct s_stack	*ptr;

	if (!*s || !(*s)->next)
		return ;
	temp = *s;
	*s = (*s)->next;
	(*s)->prev = NULL;
	ptr = *s;
	if (!ptr)
		return ;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = temp;
	temp->prev = ptr;
	temp->next = NULL;
	write(1, "r", 1);
	write(1, &ch, sizeof(char));
	write(1, "\n", 1);
}

//  shift down all elements by one:
void	rev_rotate(t_stack *s, char ch)
{
	struct s_stack	*temp;

	if (!*s || !(*s)->next)
		return ;
	temp = *s;
	while (temp->next->next)
		temp = temp->next;
	temp->next->next = *s;
	*s = temp->next;
	temp->next = NULL;
	write(1, "rr", 2);
	write(1, &ch, sizeof(char));
	write(1, "\n", 1);
	(*s)->prev = NULL;
	(*s)->next->prev = *s;
}

void	push_to(t_stack *dest, t_stack *src, char ch)
{
	struct s_stack	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp->next = *dest;
	if (*dest)
		(*dest)->prev = temp;
	*dest = temp;
	(*dest)->prev = NULL;
	if (ch != 'x')
	{
		write(1, "p", 1);
		write(1, &ch, sizeof(char));
		write(1, "\n", 1);
	}
}

void	smart_rotate(t_stack *a, int size, int until, char stack)
{
	int		i;

	i = -1;
	if (until == -1 || until == 0 || until == size)
		return ;
	if (until <= size / 2)
		while (++i < until)
			rotate(a, stack);
	else
	{
		until = size - until;
		while (++i < until)
			rev_rotate(a, stack);
	}
}

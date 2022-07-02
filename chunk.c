/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriyas <rriyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:19:21 by rriyas            #+#    #+#             */
/*   Updated: 2022/06/17 15:46:40 by rriyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fn that finds the index of the first number from the
//bottom of the stack thqat belongs to chunk i
int	find_num_from_bot(t_stack *a, int size, int chunk, int npc)
{
	int				i;
	struct s_stack	*ptr;

	ptr = *a;
	i = 0;
	if (!*a)
		return (-1);
	while (ptr->next && i < size)
	{
		ptr = ptr->next;
		i++;
	}
	while (ptr && i >= size / 2)
	{
		if (ptr->cindex >= chunk * npc && ptr->cindex < chunk * npc + npc)
			return (i);
		ptr = ptr->prev;
		i--;
	}
	return (-1);
}

//fn that finds the index of the first number from the
//top of the stack thqat belongs to chunk i
int	find_num_from_top(t_stack *a, int size, int chunk, int npc)
{
	int				i;
	struct s_stack	*ptr;

	ptr = *a;
	i = -1;
	while (ptr && ++i <= size / 2)
	{
		if (ptr->cindex >= chunk * npc && ptr->cindex < chunk * npc + npc)
			return (i);
		ptr = ptr->next;
	}
	return (-1);
}

//this fn receieves two indeices s and l
//then it decides which one is easier to bring to the top of a
int	smart_picker(int s, int l, int size)
{
	int	x1;
	int	x2;

	if (s == -1 && l == -1)
		return (-1);
	if (s == -1)
		return (l);
	if (l == -1)
		return (s);
	x1 = min(s, size - s);
	x2 = min(l, size - l);
	if (x1 < x2)
		return (s);
	return (l);
}

//this fn checks if any numbers remain in the stack that
//belong to chunk i
int	check_exists(t_stack *a, int size, int chunk, int npc)
{
	int				top;
	int				bot;

	top = -1;
	bot = -1;
	bot = find_num_from_bot(a, size, chunk, npc);
	top = find_num_from_top(a, size, chunk, npc);
	if (top == -1 && bot == -1)
		return (-1);
	return (1);
}

//This fn seperates the stack a into chunks of npc numbers
//and proceeds to push them into stack b:
//npc - numbers per chunk
void	chunk(t_stack *a, t_stack *b, int chunk, int npc)
{
	int				final;
	int				top;
	int				bot;
	int				size;

	size = find_size(a);
	while (check_exists(a, size, chunk, npc) != -1)
	{
		top = -1;
		bot = -1;
		bot = find_num_from_bot(a, size, chunk, npc);
		top = find_num_from_top(a, size, chunk, npc);
		final = smart_picker(top, bot, size);
		smart_rotate(a, size, final, 'a');
		push_to(b, a, 'b');
		if ((*b)->cindex >= chunk * npc
			&& (*b)->cindex < chunk * npc + (npc / 2))
			rotate(b, 'b');
		size--;
	}
}

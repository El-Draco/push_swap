/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriyas <rriyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:33:34 by rriyas            #+#    #+#             */
/*   Updated: 2022/06/17 15:47:09 by rriyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	sort_100(t_stack *a, t_stack *b)
{
	int	npc;
	int	noc;
	int	c;

	npc = 17;
	noc = 6;
	c = 0;
	while (c < noc)
	{
		chunk(a, b, c, npc);
		c++;
	}
	c = noc - 1;
	while (c >= 0)
	{
		while (check_exists(b, find_size(b), c, npc) == 1)
			semi_to_full(a, b);
		c--;
	}
}

void	sort_500(t_stack *a, t_stack *b)
{
	int	npc;
	int	noc;
	int	c;

	npc = 56;
	noc = 9;
	c = 0;
	while (c < noc)
	{
		chunk(a, b, c, npc);
		c++;
	}
	c = noc - 1;
	while (c >= 0)
	{
		while (check_exists(b, find_size(b), c, npc) == 1)
			semi_to_full(a, b);
		c--;
	}
}

void	radi_sort(t_stack *a, t_stack *b, int size)
{
	int	*arr;

	arr = sorted_array(a, size);
	assign_indices(a, arr, size);
	if (sorted(a))
	{
		free(arr);
		return ;
	}
	if (size <= 3)
		sort_three(a, b);
	else if (size <= 5)
		sort_five(a, b);
	else if (size <= 100)
		sort_100(a, b);
	else if (size <= 500)
		sort_500(a, b);
	else
		sort_extra(a, b, size);
	free(arr);
}

//first find the largest in stack b belonging to chunk i and then
//pushes it to stack a:
void	semi_to_full(t_stack *a, t_stack *b)
{
	int				pos;

	pos = index_largest(b);
	smart_rotate(b, find_size(b), pos, 'b');
	push_to(a, b, 'a');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorte_extra_large.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriyas <rriyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:36:32 by rriyas            #+#    #+#             */
/*   Updated: 2022/06/16 15:36:34 by rriyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_extra(t_stack *a, t_stack *b, int size)
{
	int	npc;
	int	noc;
	int	c;

	npc = size / 9 + (0 != size % 9);
	noc = 9;
	c = 0;
	size++;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriyas <rriyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:32:43 by rriyas            #+#    #+#             */
/*   Updated: 2022/06/15 20:54:53 by rriyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_stack *s)
{
	struct s_stack	*ptr;

	if (!*s)
		write(1, "NULL\n", 6);
	ptr = *s;
	while (ptr)
	{
		printf("%d should be at %d\n", ptr->val, ptr->cindex);
		ptr = ptr->next;
	}
}

void	sort_three(t_stack *a, t_stack *b)
{
	struct s_stack	*ptr;

	ptr = *a;
	if (sorted(a) || !ptr)
		return ;
	if (largest(a) == ptr->val && smallest(a) == ptr->next->val)
		rotate(a, 'a');
	else if (largest(a) != ptr->val && smallest(a) == ptr->next->val)
		swap_first_two(a, 'a');
	else if (largest(a) == ptr->val && smallest(a) != ptr->next->val)
		swap_first_two(a, 'a');
	else
		rev_rotate(a, 'a');
	sort_three(a, b);
}

int	index_smallest(t_stack *a)
{
	int				num;
	int				i;
	struct s_stack	*ptr;

	i = 0;
	num = smallest(a);
	ptr = *a;
	while (ptr)
	{
		if (ptr->val == num)
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (i);
}

int	find_smallest_greater_than(t_stack *a, int b_top)
{
	struct s_stack	*ptr;
	int				largest;
	int				index;
	int				i;

	ptr = *a;
	i = 0;
	index = -1;
	largest = ptr->val;
	while (ptr)
	{
		if ((index == -1 || ptr->val < largest) && ptr->val > b_top)
		{
			index = i;
			largest = ptr->val;
		}
		i++;
		ptr = ptr->next;
	}
	return (index);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int				i;
	int				index;

	push_to(b, a, 'b');
	push_to(b, a, 'b');
	sort_three(a, b);
	while (find_size(b) != 0)
	{
		index = -1;
		if (largest(a) < (*b)->val)
			smart_rotate(a, find_size(a), index_largest(a) + 1, 'a');
		else
		{
			index = find_smallest_greater_than(a, (*b)->val);
			if (index != -1)
				smart_rotate(a, find_size(a), index, 'a');
		}
		push_to(a, b, 'a');
	}
	i = index_smallest(a);
	if (!sorted(a))
		smart_rotate(a, find_size(a), i, 'a');
}

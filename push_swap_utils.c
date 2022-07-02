/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_swap_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriyas <rriyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:21:04 by rriyas            #+#    #+#             */
/*   Updated: 2022/06/15 19:24:10 by rriyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	clear_stack(t_stack *s)
{
	struct s_stack	*temp;

	if (!*s)
		return ;
	while (*s)
	{
		temp = *s;
		*s = (*s)->next;
		free(temp);
	}
}

int	sorted(t_stack *a)
{
	struct s_stack	*ptr;

	ptr = *a;
	if (!*a)
		return (FALSE);
	while (ptr->next)
	{
		if (ptr->val > ptr->next->val)
			return (FALSE);
		ptr = ptr->next;
	}
	return (TRUE);
}

int	index_largest(t_stack *a)
{
	struct s_stack	*ptr;
	int				max;
	int				i;
	int				index;

	ptr = *a;
	max = ptr->cindex;
	index = 0;
	i = 0;
	while (ptr)
	{
		if (ptr->cindex > max)
		{
			max = ptr->cindex;
			index = i;
		}
		ptr = ptr->next;
		i++;
	}
	return (index);
}

int	find_size(t_stack *a)
{
	struct s_stack	*ptr;
	int				i;

	i = 0;
	ptr = *a;
	if (!ptr)
		return (0);
	while (ptr->next)
	{
		i++;
		ptr = ptr->next;
	}
	return (i + 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriyas <rriyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:42:55 by rriyas            #+#    #+#             */
/*   Updated: 2022/06/15 19:52:51 by rriyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	largest(t_stack *a)
{
	struct s_stack	*ptr;
	int				max;

	ptr = *a;
	max = ptr->val;
	while (ptr)
	{
		if (ptr->val > max)
			max = ptr->val;
		ptr = ptr->next;
	}
	return (max);
}

int	smallest(t_stack *a)
{
	struct s_stack	*ptr;
	int				min;

	ptr = *a;
	min = ptr->val;
	while (ptr)
	{
		if (ptr->val < min)
			min = ptr->val;
		ptr = ptr->next;
	}
	return (min);
}

int	num_length(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (1 + i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	char	*temp;
	int		l1;

	l1 = ft_strlen(s1);
	i = -1;
	if (!s1 || !s2)
		return (NULL);
	temp = malloc(l1 + ft_strlen(s2) + 1);
	if (!temp)
		return (NULL);
	while (s1[++i])
		temp[i] = s1[i];
	i = 0;
	while (s2[i])
	{
		temp[l1 + i] = s2[i];
		i++;
	}
	temp[l1 + i] = 0;
	free(s1);
	return (temp);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

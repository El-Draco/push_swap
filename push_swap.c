/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriyas <rriyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:23:00 by rriyas            #+#    #+#             */
/*   Updated: 2022/06/17 15:34:22 by rriyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//bubble sort on array:
int	*sorted_array(t_stack *a, int size)
{
	int				*arr;
	int				i;
	int				j;
	struct s_stack	*ptr_a;

	ptr_a = *a;
	i = 0;
	arr = malloc(size * sizeof(int));
	while (ptr_a)
	{
		arr[i++] = ptr_a->val;
		ptr_a = ptr_a->next;
	}
	i = 0;
	while (i < size)
	{
		j = -1;
		while (++j < size - 1)
			if (arr[j] > arr[j + 1])
				ft_swap(&arr[j], &arr[j + 1]);
		i++;
	}
	return (arr);
}

void	assign_indices(t_stack *a, int *arr, int size)
{
	int				i;
	struct s_stack	*ptr;

	if (size == 0)
		return ;
	i = 0;
	ptr = *a;
	while (i < size)
	{
		ptr = *a;
		while (ptr)
		{
			if (ptr->val == arr[i])
				ptr->cindex = i;
			ptr = ptr->next;
		}
		i++;
	}
}

int	check_dupes(t_stack *a)
{
	struct s_stack	*ptr_i;
	struct s_stack	*ptr_j;

	ptr_i = *a;
	while (ptr_i)
	{
		ptr_j = ptr_i->next;
		while (ptr_j)
		{
			if (ptr_i->val == ptr_j->val)
				return (-1);
			ptr_j = ptr_j->next;
		}
		ptr_i = ptr_i->next;
	}
	return (1);
}

int	validate_args(int flag, t_stack *a)
{
	if (flag == -1 || check_dupes(a) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		flag;
	int		size;

	a = NULL;
	b = NULL;
	flag = parse_args(argv, argc, &a, &b);
	size = find_size(&a);
	if (size == 0)
		return (0);
	if (validate_args(flag, &a) == -1)
	{
		clear_stack(&a);
		clear_stack(&b);
		return (0);
	}
	radi_sort(&a, &b, size);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}

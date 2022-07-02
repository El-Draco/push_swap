/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriyas <rriyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:24:51 by rriyas            #+#    #+#             */
/*   Updated: 2022/06/17 15:49:50 by rriyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	skip_beg(char *str, int *neg)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		*neg *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (i);
}

long	ft_atoi(char *str, int *flag)
{
	long	num;
	int		i;
	int		neg;

	num = 0;
	neg = 1;
	i = skip_beg(str, &neg);
	if (str[i] && str[i] != ' ')
	{
		while (str[i] && str[i] != ' ')
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				*flag = -1;
			num = num * 10 + (str[i++] - '0');
		}
	}
	else
		*flag = -1;
	return (neg * num);
}

//fn to combine all arguments into one string
//and then split them into an array of strings
//with each string corresponding to a number in the stack
char	**prepare_numbers(int argc, char **argv)
{
	int		i;
	char	**all_nums;
	char	*num;

	num = malloc(sizeof(char) + 1);
	*num = ' ';
	*(num + 1) = '\0';
	i = 0;
	while (++i < argc)
	{
		num = ft_strjoin(num, argv[i]);
		num = ft_strjoin(num, " ");
	}
	i = 0;
	while (num[i])
	{
		if (num[i] == '\t')
			num[i] = ' ';
		i++;
	}
	all_nums = ft_split(num, ' ');
	free(num);
	return (all_nums);
}

//fn that iterates through the array of numbers and pushes them into
//stack a in the right order:
int	prepare_a(char **all_nums, int flag, t_stack *a, t_stack *b)
{
	struct s_stack	*temp;
	int				i;
	long			num;

	i = 0;
	while (all_nums[i])
	{
		temp = malloc(sizeof(struct s_stack));
		num = ft_atoi(all_nums[i], &flag);
		if (num < -2147483648 || num > 2147483647)
			flag = -1;
		temp->val = num;
		temp->next = NULL;
		temp->prev = NULL;
		push_to(b, &temp, 'x');
		i++;
	}
	while (*b)
		push_to(a, b, 'x');
	return (flag);
}

//fn that parses and validates the arguments of the program:
int	parse_args(char **argv, int argc, t_stack *a, t_stack *b)
{
	char			**all_nums;
	int				i;
	int				flag;

	i = 1;
	flag = 1;
	all_nums = prepare_numbers(argc, argv);
	i = 0;
	flag = prepare_a(all_nums, flag, a, b);
	i = -1;
	while (all_nums[++i])
		free(all_nums[i]);
	free(all_nums);
	return (flag);
}

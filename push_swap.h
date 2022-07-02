/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriyas <rriyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:27:29 by rriyas            #+#    #+#             */
/*   Updated: 2022/06/17 15:34:15 by rriyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

struct s_stack
{
	int				cindex;
	int				val;
	struct s_stack	*next;
	struct s_stack	*prev;
};

typedef struct s_stack*	t_stack;

//sort_large.c
int		min(int a, int b);
void	sort_100(t_stack *a, t_stack *b);
void	sort_500(t_stack *a, t_stack *b);
void	semi_to_full(t_stack *a, t_stack *b);
void	radi_sort(t_stack *a, t_stack *b, int count);

//stack.c
void	swap_first_two(t_stack *s, char ch);
void	rotate(t_stack *s, char ch);
void	rev_rotate(t_stack *s, char ch);
void	push_to(t_stack *dest, t_stack *src, char ch);
void	smart_rotate(t_stack *a, int size, int until, char stack);

//push_swap_utils.c:
int		ft_strlen(const char *s);
void	clear_stack(t_stack *s);
int		sorted(t_stack *a);
int		index_largest(t_stack *a);
int		find_size(t_stack *a);

//chunk.c
int		find_num_from_bot(t_stack *a, int size, int chunk, int npc);
int		find_num_from_top(t_stack *a, int size, int chunk, int npc);
int		smart_picker(int s, int l, int size);
int		check_exists(t_stack *a, int size, int chunk, int npc);
void	chunk(t_stack *a, t_stack *b, int chunk, int npc);

//parse.c:
int		skip_beg(char *str, int *neg);
long	ft_atoi(char *str, int *flag);
char	**prepare_numbers(int argc, char **argv);
int		prepare_a(char **all_nums, int flag, t_stack *a, t_stack *b);
int		parse_args(char **argv, int argc, t_stack *a, t_stack *b);

//push_swap.c
int		*sorted_array(t_stack *a, int size);
void	assign_indices(t_stack *a, int *arr, int size);
int		check_dupes(t_stack *a);
int		validate_args(int flag, t_stack *a);
void	free_heap(t_stack *a, t_stack *b);

//sort_small.c
void	display_stack(t_stack *s);
void	sort_three(t_stack *a, t_stack *b);
int		index_smallest(t_stack *a);
int		find_smallest_greater_than(t_stack *a, int b_top);
void	sort_five(t_stack *a, t_stack *b);

//split.c:
char	*ft_mystrlcpy(char *dest, const char *src, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		num_of_words(const char *str, char charset);
char	**do_stuff(const char *s, char c, char **array);
char	**ft_split(const char *s, char c);

//push_swap_utils2.c
int		largest(t_stack *a);
int		smallest(t_stack *a);
int		num_length(int n);
char	*ft_strjoin(char *s1, char const *s2);
void	ft_swap(int *a, int *b);

//sort_extra_large.c
void	sort_extra(t_stack *a, t_stack *b, int size);

#endif

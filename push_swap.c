#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define true 1
#define false 0
// goose
int ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int ft_min(int *a, int *b)
{
    if (*a < *b)
        return *a;
    return *b;
}
// goose
struct node
{
    int val;
    struct node *next;
};

typedef struct node *stack;

void push(stack *s, int x)
{
    struct node *temp;

    temp = malloc(sizeof(struct node));
    temp->val = x;
    if (!*s)
    {
        *s = temp;
        temp->next = NULL;
    }
    else
    {
        temp->next = *s;
        *s = temp;
    }
}
// goose
void pop(stack *s)
{
    struct node *temp;

    if (!*s)
        return;
    temp = *s;
    *s = (*s)->next;
    free(temp);
}

void display_stack(stack *s)
{
    struct node *ptr;

    if (!*s)
        write(1, "NULL\n", 6);
    ptr = *s;
    while (ptr)
    {
        printf("%d\n", ptr->val);
        ptr = ptr->next;
    }
}

void clear_stack(stack *s)
{
    struct node *temp;
    if (!*s)
        return;

    while (*s)
    {
        temp = *s;
        *s = (*s)->next;
        pop(&temp);
    }
}

int is_empty(stack *s)
{
    if (!*s)
        return true;
    return false;
}

void swap_first_two(stack *s)
{
    // goose
    struct node *temp;

    if (!*s || !(*s)->next)
        return;
    temp = (*s)->next;
    (*s)->next = temp->next;
    temp->next = *s;
    *s = temp;
}
//  shift up all elements by one:
void rotate(stack *s)
{
    struct node *temp;
    struct node *ptr;
    if (!*s || !(*s)->next)
        return;
    temp = *s;
    *s = (*s)->next;
    ptr = *s;
    while (ptr->next)
        ptr = ptr->next;
    ptr->next = temp;
    temp->next = NULL;
}
//  shift down all elements by one:
void rev_rotate(stack *s)
{
    struct node *temp;
    struct node *ptr;
    // edge cases:
    if (!*s || !(*s)->next)
        return;
    temp = *s;
    while (temp->next->next)
        temp = temp->next;
    temp->next->next = *s;
    *s = temp->next;
    temp->next = NULL;
}
void push_to(stack *dest, stack *src)
{
    struct node *temp;
    if (!*src)
        return;
    temp = *src;
    *src = (*src)->next;
    temp->next = *dest;
    *dest = temp;
    // push(dest, (*src)->val);
    // pop(src);
}

// algo 1

void sort(stack *a, stack *b, int n)
{
    int i;
    int count;
    int largest;
    struct node *b_ptr;
    count = 0;
    largest = (*a)->val;
    while (*b)
    {
        count = 0;
        b_ptr = *b;
        i = 0;
        if ((*a)->val > (*b)->val)
        {
            write(1, "push a\n", 8);
            push_to(a, b);
            n--;
        }
        else
        {
            while (b_ptr && (*a)->val < b_ptr->val)
            {
                b_ptr = b_ptr->next;
                count++;
            }
            if (count == n && (*a)->val == largest)
            {
                largest = (*b)->val;
                rotate(a);
                write(1, "ra\n", 4);

                push_to(a, b);
                write(1, "push a\n", 8);

                n--;
            }
            else if (count == n && (*a)->next) // correct placement:
            {
                rotate(a);
                write(1, "ra\n", 4);
            }
            else if (count == n)
            {
                push_to(a, b);
                write(1, "push a\n", 8);
                n--;
            }
            else
            {
                if (count <= n / 2) // rotate  up
                {
                    while (++i <= count)
                    {
                        rotate(b);
                        write(1, "rb\n", 4);
                    }
                    push_to(a, b);
                    write(1, "push a\n", 8);
                    n--;
                }
                else // rev_rotate
                {
                    while (++i <= count)
                    {
                        write(1, "rrb\n", 5);
                        rev_rotate(b);
                    }
                    push_to(a, b);
                    write(1, "push a\n", 8);

                    n--;
                }
            }
        }
        // write("Stack a: \n");
        // display_stack(a);
        // write("Stack b: \n");
        // display_stack(b);
    }
    // now we rot until top is largest:
    while ((*a)->val != largest)
    {
        rotate(a);
        write(1, "ra\n", 4);
    }
    rotate(a);
    write(1, "ra\n", 4);
}

void old_push_swap(stack *a, stack *b, int n)
{
    int i;
    int middle;

    if (n <= 1)
        return;
    middle = (n + 1) / 2;
    i = 1;
    // push all except one:
    while (++i <= n)
    {
        push_to(b, a);
        write(1, "push a\n", 8);
    }
    // push_swap(a,b, n-1);
    // equivalent to pushing elemnt to stack b:
    sort(a, b, n - 1);
}


void ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
		i++;
	if (i == n)
		i--;
	return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*temp;
	int		l1;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	i = 0;
	temp = malloc(l1 + ft_strlen(s2) + 1);
	if (!temp)
		return (NULL);
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		temp[l1 + i] = s2[i];
		i++;
	}
	temp[l1 + i] = 0;
	return (temp);
}

void process_old_calls(char *s, int start, int end)
{
    int i;

    if (start == end)
        return ;
    
    //here we print chars from start index to end index:
    i = start;
    while (i <= end)
    {
        write(1,&s[i],1);
        i++;
    }

    //here we delete all printed characters and reallocate memory:
    char *temp;
    temp = malloc(sizeof(char) *(1 + ft_strlen(s) -start - end));
    ft_strcpy(temp,s);
    free(s);
    s = temp;
}


int are_they_redundant(char *f1, char *f2)
{
    int n;
    int len;
    
    if (!f1 || !f2 || ft_strlen(f1) != ft_strlen(f2))
        return false;
        len = ft_strlen(f1);
    if (ft_strncmp(f1, f2, len) == 1 || ft_strncmp(f1, f2, len) == -1)
        return true;
    return false;        
}

void delete_redundant_opers(char *hist, int start, int stop)
{
    int i;
    char *temp;

    i = 0;

}

void check_for_redundancies(char *hist)
{
    static char oper1[5];
    static char oper2[5];
    int start;
    int end;
    int i;

    if (2)
    {
        //first fn call:
        
    }
    i = 0;
    start = 0;
    end = 0;
    //obtain first operation:
    while (hist[i] && hist[i] != '\n')
    {
        oper1[i] = hist[i];
        i++;
    }
    //count number of times operation appears consecutively:
    int f1_count = 1;
    i++;
    int oper_len = ft_strlen(oper1);
    while (hist[i] && ft_strncmp(oper1, hist+i, oper_len))
    {
        i += oper_len;
        f1_count++;
    }


    //now we obtain the second operation if any:
    while (hist[i] && hist[i] != '\n')
    {
        oper2[i] = hist[i];
        i++;
    }
    //count number of times operation appears consecutively:
    int f2_count = 1;
    oper_len = ft_strlen(oper2);
    i++;
    while (hist[i] && ft_strncmp(oper1, hist+i, oper_len))
    {
        i += oper_len;
        f2_count++;
    }

    if(are_they_redundant(oper1, oper2))
    {
        int del_count;
        //we delete the redundant operations
        del_count = ft_min(&f1_count, &f2_count);
    }
    else
    {
        process_old_calls(hist,0, end);
    }
}

void fn_call_history(char *new_oper)
{
    int i;
    static char *hist;
    char *temp;

    if (!hist)
        hist = malloc(sizeof(char) * (1 + ft_strlen(new_oper)));
    else
    {
        temp = malloc(sizeof(char) * (1 + ft_strlen(new_oper) + ft_strlen(hist)));
        ft_strcpy(temp, hist);
        free(hist);
        hist = temp;
    }
    //concat new operation:    
    while (new_oper)
    {
        hist[i] = new_oper[i];
        i++;
    }

    //check for redundancies:
    check_for_redundancies(hist);
}


void push_swap1(stack *a, stack *b, int n)
{
    int i;
    int half;

    i = 0;
    if (n <= 1)
        return;
    while (i < n-1)
    {
        push_to(b, a);
        write(1, "pb\n", 4);
        i++;
    }
    // note that we keep a ALWAYS sorted, b is merely a holder of remaining elements
    struct node *ptr;
    int count;
    int pushed;

    pushed = 0;
    n = 1;

    while (*b)
    {
        ptr = *a;
        count = 0;

        if (!*a || (*a)->val > (*b)->val)
        {
            push_to(a, b);
            write(1, "pa\n", 4);
        }
        else
        {
            i = 0;
            while (ptr && ptr->val < (*b)->val)
            {
                count++;
                // push_to(a, b);
                ptr = ptr->next;
            }
            // if count == n we have a special case
            if (count == n)
            {
                push_to(a, b);
                write(1, "pa\n", 4);
                rotate(a);
                write(1, "ra\n", 4);

            }

            // if count <= n / 2
            else if (count <= n / 2)
            {
                while (++i <= count)
                {
                    rotate(a);
                    write(1, "ra\n", 4);
                }
                push_to(a, b);
                write(1, "pa\n", 4);
                i = 0;
                while (++i <= count)
                {
                    rev_rotate(a);
                    write(1, "rra\n", 4);
                }
            }

            // if count > n / 2
            else
            {
                while (++i <= n - count)
                {
                    write(1, "rra\n", 4);
                    rev_rotate(a);
                }
                push_to(a, b);
                write(1, "pa\n", 4);
                i = 0;
                while (++i <= n - count)
                {
                    rotate(a);
                    write(1, "ra\n", 4);
                }
            }
        }
        pushed++;
        n++;
    }
}

void push_swap2(stack *a, stack *b, int n)
{
    int i;
    int count;
    struct node *ptr;
    int b_c;

    b_c = 0;
    while (*a)
    {
        ptr = *b;
        if (!ptr || (*a)->val > ptr->val)
        {
            push_to(b, a);
            write(1, "pb\n", 4);
        }
        else
        {
            count = 0;
            while (ptr && (*a)->val < ptr->val)
            {
                count++;
                ptr = ptr->next;
            }
            i = 0;
            if (count == b_c)
            {
                push_to(b, a);
                write(1, "pa\n", 4);
                rotate(b);
                write(1, "rb\n", 4);
            }

            else if (!(*b)->next)
            {
                push_to(b, a);
                write(1, "pb\n", 4);
                swap_first_two(b);
                write(1, "sb\n", 4);
            }

            else if (count <= b_c / 2)
            {
                while (++i <= count)
                {
                    rotate(b);
                    write(1, "rb\n", 4);
                }
                push_to(b, a);
                write(1, "pb\n", 4);

                i = 0;
                while (++i <= count)
                {
                    rev_rotate(b);
                    write(1, "rrb\n", 4);
                }
            }
            else
            {
                while (++i <= b_c - count)
                {
                    write(1, "rrb\n", 4);
                    rev_rotate(b);
                }
                push_to(b, a);
                write(1, "pb\n", 4);
                i = 0;
                while (++i <= b_c - count)
                {
                    rotate(b);
                    write(1, "rb\n", 4);
                }
            }
        }
        n--;
        b_c++;
    }
    while (*b)
    {
        push_to(a, b);
        write(1, "pa\n", 4);
    }
}

int main(int argc, char **argv)
{
    stack a = NULL;
    stack b = NULL;
    //  dont forget to check for invalid arguments in the return val of stack_init:
    //  stack_init(&a, argc, &argv);
    int i;

    int count = 0;
    int len = ft_strlen(argv[1]);
    int x;
    int j;
    char *s = argv[1];
    i = len - 1;

    while (i >= 0)
    {
        j = i;
        while (j >= 0 && s[j] != ' ')
            j--;
        if (j == -1)
            j++;
        x = atoi(s + j);
        i = j - 1;
        push(&a, x);
        count++;
    }
    push_swap1(&a, &b, count);
    // printf("\n\n");
    //display_stack(&a);
    //display_stack(&b);

    //
    return 0;
}
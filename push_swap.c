#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#define true 1
#define false 0

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

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

// void display_both(stack *a, stack *b)
// {
//     struct node *a_ptr,*b_ptr;

//     a_ptr = *a;
//     b_ptr = *b;
//     while (ptr)
//     {
//         write("%d\n", ptr->val);
//         ptr = ptr->next;
//     }
// }

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

// shift up all elements by one:
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

// shift down all elements by one:
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

// void sort_stack(stack *a, stack *b)
// {
//     int a_top;

//     while (*a)
//     {
//         a_top = (*a)->val;
//         if (*b == NULL || a_top < (*b)->val)
//             push_to(b, a);
//         else
//         {
//             pop(a);
//             while (a_top > (*b)->val)
//                 push_to(a, b);
//             push(b, a_top);
//         }
//         *a = (*a)->next;
//     }
// }
/*
void merge_stacks(stack *a, int a_count, stack *b)
{
    int count;
    int i;

    count = 0;
    if (!*a)
        push_to(a, b);

    while (*b)
    {
        i = -1;
        while ((*a)->val < (*b)->val)
            count++;

        if (count < a_count / 2)
        {
            while (++i < count)
                rev_rotate(a);
            push_to(a, b);
            i = -1;
            while (++i < count)
                rotate(a);
        }
        else if (count == 0)
        {
            push_to(a,b);
        }

        else
        {
            while (++i < count)
                rotate(a);
            push_to(a, b);
            i = -1;
            while (++i < count)
                rev_rotate(a);
        }

        (*b) = (*b)->next;
    }
}

void copy_stack(stack *dest, stack *src, int n)
{
    int i;

    i = 0;
}

stack actual_push_swap(stack a, int n)
{
    struct node *b;
    int half;
    int i;

    // here we duplicate stacks:

    b = NULL;
    // base case:
    if (n > 1)
    {
        half = (n + 1) / 2;
        i = 1;
        // 1. push half elements to b:
        while (i <= half)
        {
            push_to(&b, &a);
            i++;
        }
        // stack temp = NULL;

        push_swap(a, half);
        push_swap(b, n - half);
        merge_stacks(&a, half, &b);
    }
    return a;
}
*/

// void push_swap(stack *a, int n)
// {
//     struct node *ptr;
//     if (n <= 1)
//         return;
//     int middle;
//     int i;

//     i = 0;
//     middle = (n + 1) / 2;
//     while (++i <= middle)

//         push_swap2((*a)->next, middle);
// }

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

void push_swap(stack *a, stack *b, int n)
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
            if (count == b_c)
            {
                push_to(b, a);
                write(1, "pa\n", 4);
                rotate(b);
                write(1, "rb\n", 4);
            }

            i = 0;
            if (!(*b)->next)
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
                while (++i <= b_c - count + 1)
                {
                    write(1, "rrb\n", 4);
                    rev_rotate(b);
                }
                push_to(b, a);
                write(1, "pb\n", 4);
                i = 0;
                while (++i <= b_c - count + 2)
                {
                    rotate(b);
                    write(1, "rb\n", 4);
                }
            }
        }
        // printf("Stack a: \n");
        // display_stack(a);
        // printf("Stack b: \n");
        // display_stack(b);
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
    }
    push_swap2(&a, &b, count);
    // printf("\n\n");
    // display_stack(&a);

    return 0;
}
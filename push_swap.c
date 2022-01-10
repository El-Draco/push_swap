#include <stdio.h>
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
//         printf("%d\n", ptr->val);
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

int stack_init(stack *s, int argc, char ***argv)
{
    int i;

    i = argc - 1;
    while (i >= 1)
    {
        push(s, atoi(*argv[i]));
        i--;
    }
    return 0;
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

void sort_stack(stack *a, stack *b)
{
    int a_top;

    while (*a)
    {
        a_top = (*a)->val;
        if (*b == NULL || a_top < (*b)->val)
            push_to(b, a);
        else
        {
            pop(a);
            while (a_top > (*b)->val)
                push_to(a, b);
            push(b, a_top);
        }
        *a = (*a)->next;
    }
}

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
    while (/* condition */)
    {
        /* code */
    }
    
}

stack actual_push_swap(stack a, int n)
{
    struct node *b;
    int half;
    int i;

    //here we duplicate stacks:


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

void push_swap(stack *a, int n)
{
    struct node *ptr;
    if (n <=1)
        return ;
    int middle;
    int i;

    i = 0;
    middle = (n+1)/2;
    while (++i <= middle)
        
    
    push_swap2((*a)->next, middle);

}

int main(int argc, char **argv)
{
    stack a = NULL;
    // stack b = NULL;
    //  dont forget to check for invalid arguments in the return val of stack_init:
    //  stack_init(&a, argc, &argv);
    int i;

    i = argc;
    while (--i >= 1)
        push(&a, atoi(argv[i]));

    display_stack(&a);

    // push_to(&b, &a);
    // push_to(&b, &a);
    // push_to(&b, &a);

    // printf("\n\n");
    // display_stack(&a);
    // printf("\n\n");

    // display_stack(&b);

    a = push_swap(a, 6);
    display_stack(&a);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void print_array(int a[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d  ", a[i]);
    printf("\n");
}

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int a[], int size)
{
    // look for the smallest element and add it to the end of the sorted elements:

    int smallest;
    for (int i = 0; i < size - 1; i++)
    {
        smallest = i;
        for (int j = i; j < size; j++)
        {
            if (a[j] < a[smallest])
                smallest = j;
        }
        if (a[i] != a[smallest] && i < smallest)
            my_swap(&a[i], &a[smallest]);
    }
}

// My insertion sort lol...
//  void insertion_sort(int a[], int size)
//  {
//      int ele;
//      for (int i = 0; i < size; i++)
//      {
//          //we pick ele and add to sorted list but position it correctly:
//          ele = i;
//          for (int j = 0; j < i; j++)
//          {
//              if (a[ele < a[j]])
//                  my_swap(&a[ele], &a[j]);
//          }
//          printf("i = %d: ",i);
//          print_array(a,size);
//      }
//  }

void insertion_sort(int a[], int size)
{
    int j;
    // j's initial value is essentially what u picked to move to the sorted list
    // so u loop backwards and swap when necessary and stop the moment u place it in the right location
    for (int i = 1; i < size; i++)
    {
        // we pick ele and add to sorted list but position it correctly:
        j = i;
        while (j > 0 && a[j] < a[j - 1])
        {
            my_swap(&a[j], &a[j - 1]);
            j--;
        }

        printf("i = %d: ", i);
        print_array(a, size);
    }
}

void bubble_sort(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
            if (a[j + 1] < a[j])
                my_swap(&a[j], &a[j + 1]);
    }
}

// void merge(int a[], int start, int stop )
// {
//     int middle = (1 + stop) / 2;

//     int k = 0;

//     while (start <= stop && middle <= stop)
//     {
//         if (a[start] > a[middle])
//         {
//             a[k] = a[middle];
//             middle++;
//         }
//         else
//         {
//             a[k] = a[start];
//             start++;
//         }
//         k++;
//     }
// }

void merge(int a[], int start, int stop)
{
    int k = start;
    int middle = (start + stop) / 2;
    const int nL = middle - start + 1;
    const int nR = stop - middle;
    // if (nL <= 0 || nR <= 0)
    // {
    //     return;
    // }
    int *L;
    int *R;
    if (nL > 0)
        L = malloc(sizeof(int) * nL);
    if (nR > 0)
        R = malloc(sizeof(int) * nR);

    // copy data from a to L,R:
    for (int i = 0; i < nL; i++)
        L[i] = a[start + i];
    for (int i = 0; i < nR; i++)
        R[i] = a[1 + middle + i];

    int l = 0, r = 0;

    while (k <= stop && l < nL && r < nR)
    {
        if (L[l] < R[r])
            a[k] = L[l++];
        else
            a[k] = R[r++];
        k++;
    }
    // copy remaining L
    while (l < nL)
    {
        a[k++] = L[l++];
    }
    while (r < nR)
    {
        a[k++] = R[r++];
    }

    // copy remaining R:

    free(L);
    free(R);
}

void merge_sort(int a[], int start, int stop)
{
    // stopping condition:
    int middle = (start + stop) / 2;

    if (start < stop)
    {
        merge_sort(a, start, middle);
        merge_sort(a, middle + 1, stop);
        merge(a, start, stop);
    }
}

int partition(int a[], int l, int r)
{
    int piv = r;
    int i, j = l;
    i = l;
    while (j < r)
    {
        if (a[j] < a[piv])
        {
            my_swap(&a[j], &a[i]);
            i++;
        }
        j++;
    }
    //if (i != l)
        my_swap(&a[piv], &a[i]);

    return i;
}

void quick_sort(int a[], int l, int r)
{
    int piv;
    if (l < r)
    {
        piv = partition(a, l, r);
        quick_sort(a, l, piv-1);
        quick_sort(a, piv + 1, r);
    }
}

int main(int argc, char **argv)
{
    int size = atoi(argv[1]);
    int *a = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        a[i] = atoi(argv[2 + i]);
    // selection_sort(a,size);
    quick_sort(a, 0, size - 1);
    print_array(a, size);
    free(a);
    return 0;
}
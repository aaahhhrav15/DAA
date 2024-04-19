#include <stdio.h>
void merge(int a[], int beg, int end);
void mergeSort(int a[], int beg, int mid, int end);

void main()
{
    int n, a[10];
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    } 

    merge(a, 0, n-1);

    printf("Sorted elements are\n");
    for (int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
}

void merge(int a[], int beg, int end)
{
    int mid = (beg+end)/2;
    if (beg < end)
    {
        merge(a, beg, mid);
        merge(a, mid + 1, end);
        mergeSort(a, beg, mid, end);
    }
}
    
void mergeSort(int a[], int beg, int mid, int end)
{
    int i = beg, j = mid + 1, index = beg, temp[10];

    while (i <= mid && j <= end)
    {
        if (a[i] < a[j])
        {
            temp[index] = a[i];
            i++;
        }
        else
        {
            temp[index] = a[j];
            j++;
        }
        index++;
    }

    while (i <= mid)
    {
        temp[index] = a[i];
        i++;
        index++;
    }

    while (j <= end)
    {
        temp[index] = a[j];
        j++;
        index++;
    }

    for (int k = beg; k <= end; k++)
    {
        a[k] = temp[k];
    }
}
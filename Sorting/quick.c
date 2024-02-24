#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) 
{
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) 
    {
        if (array[j] <= pivot) 
        {
            i++;
            swap(&array[i], &array[j]); 
        }
    }
    swap(&array[i + 1], &array[high]); 
    return (i + 1);
}

void quickSort(int array[], int low, int high) 
{
    if (low < high) 
    {
        int loc = partition(array, low, high);
        quickSort(array, low, loc - 1);
        quickSort(array, loc + 1, high);
    }
}

int main()
{
    int n,temp,val;
    clock_t start,end;
    printf("Enter the no. of elements in the array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val);
        a[i]=val;
    }
    start=clock();
    quickSort(a, 0, n - 1);
    end=clock();
    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("%.7f ms taken \n",time_taken);
    return 0;
}
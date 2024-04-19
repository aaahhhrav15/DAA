#include <stdio.h>

void findSubsets(int arr[], int n, int m, int index, int sum, int subset[], int subsetSize) {
    if (sum == m) 
    {
        printf("Subset found: ");
        for (int i = 0; i < subsetSize; i++) 
        {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    if (index == n || sum > m) 
    {
        return;
    }

    subset[subsetSize] = arr[index];
    findSubsets(arr, n, m, index + 1, sum + arr[index], subset, subsetSize + 1);

    findSubsets(arr, n, m, index + 1, sum, subset, subsetSize);
}

int main() 
{
    int n, m;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the sum to be searched: ");
    scanf("%d", &m);

    int subset[n]; 
    findSubsets(arr, n, m, 0, 0, subset, 0);

    return 0;
}

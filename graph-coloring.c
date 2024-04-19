#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of bertices of graph\n");
    scanf("%d", &n);
    int arr[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("Enter 1 if vertex %d and %d are connected else 0 :", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }
    
    return 0;
}
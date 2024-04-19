#include<stdio.h>


int min(int a, int b)
{
    return a < b? a : b;
}

int main()
{
    int n;
    printf("Enter the number of rows in matrix\n");
    scanf("%d",&n);
    int arr[n][n];
    printf("Enter %d elements of the matrix.\n",n*n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                arr[i][j] = min(arr[i][j], (arr[i][k]+arr[k][j]));
            }
        }
    }

    printf("The resultant matrix is \n\n");
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }


    return 0;
}
#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of vertices of graph\n");
    scanf("%d", &n);
    int arr[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("Enter 1 if vertex %d and %d are connected else 0 : ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }
    int color[n];
    for(int i=0; i<n; i++)
    {
        color[i]=0;
    }
    int m;
    printf("Enter the number of colors\n");
    scanf("%d", &m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i][j]==1 && color[j]!=0)
            {
                color[i]=color[j];
            }
        }
        if(color[i]==0)
        {
            color[i]=1;
        }
    }
    for(int i=0; i<n; i++)
    {
        printf("Color of vertex %d is %d\n", i+1, color[i]);
    }
    
    return 0;
}
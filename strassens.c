//Program to implement strassens matrix multiplication
#include<stdio.h>

int main()
{
    int n,m,p,q;
    printf("Enter the number of rows and columns of the first matrix\n");
    scanf("%d %d",&n,&m);
    int a[n][m];
    printf("Enter the elements of the first matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the number of rows and columns of the second matrix\n");
    scanf("%d %d",&p,&q);
    int b[p][q];
    printf("Enter the elements of the second matrix\n");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    if(m!=p)
    {
        printf("Matrix multiplication not possible\n");
        return 0;
    }
    int c[n][q];
    
    

    return 0;
}
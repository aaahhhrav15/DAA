#include<stdio.h>

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int n,m;
    printf("Enter the number of objects\n");
    scanf("%d",&n);
    int weight[n],profit[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter weight %d ",i+1);
        scanf("%d",&weight[i]);
        printf("Enter profit %d ",i+1);
        scanf("%d",&profit[i]);
    }
    printf("Enter the capacity of the knapsack\n");
    scanf("%d",&m);

    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(weight[i-1]<=j)
            {
                dp[i][j]=max(profit[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    printf("Maximum profit is %d\n",dp[n][m]);
    printf("Objects selected are\n");
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(dp[i][j]!=dp[i-1][j])
        {
            printf("Object %d\n",i);
            j=j-weight[i-1];
            i--;
        }
        else
        {
            i--;
        }
    }
        
    return 0;
}

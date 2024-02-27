#include<stdio.h>

int jobSequence(int n,int profit[], int deadline[])
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(profit[j]<profit[j+1])
            {
                int temp=profit[j];
                profit[j]=profit[j+1];
                profit[j+1]=temp;

                temp=deadline[j];
                deadline[j]=deadline[j+1];
                deadline[j+1]=temp;
            }
        }
    }

    int maxDeadline=0;
    for(int i=0;i<n;i++)
    {
        if(maxDeadline<deadline[i])
        {
            maxDeadline=deadline[i];
        }
    }

    int slot[maxDeadline];
    for(int i=0;i<maxDeadline;i++)
    {
        slot[i]=0;
    }

    int totalProfit=0;
    for(int i=0;i<n;i++)
    {
        for(int j=deadline[i]-1;j>=0;j--)
        {
            if(slot[j]==0)
            {
                slot[j]=1;
                totalProfit+=profit[i];
                break;
            }
        }
    }
    return totalProfit;
}
int main()
{
    int n;
    printf("Enter the number of jobs\n");
    scanf("%d",&n);
    int profit[n],deadline[n];
    for(int i=0;i<n;i++)
    {
        printf("For Job %d \n",i+1);
        printf("Enter profit\n");
        scanf("%d",&profit[i]);
        printf("Enter deadline\n");
        scanf("%d",&deadline[i]);
    }

    int ans=jobSequence(n,profit,deadline);

    printf("Maximum profit is %d",ans);

    return 0;
}
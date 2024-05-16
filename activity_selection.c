#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of activities\n");
    scanf("%d",&n);
    int start[n],end[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter start time of activity %d ",i+1);
        scanf("%d",&start[i]);
        printf("Enter end time of activity %d   ",i+1);
        scanf("%d",&end[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(end[j]>end[j+1])
            {
                int temp=end[j];
                end[j]=end[j+1];
                end[j+1]=temp;
                temp=start[j];
                start[j]=start[j+1];
                start[j+1]=temp;
            }
        }
    }
    printf("Activities selected are\n");
    int finishTime=0;
    for(int j=0;j<n;j++)
    {
        if(start[j]>=finishTime)
        {
            printf("Activity %d with start time %d and end time %d\n",j+1,start[j],end[j]);
            finishTime=end[j];
        }
    }

    return 0;
}
#include<stdio.h>

float knapsack(int n,float weight[],float profit[],float M, float X[])
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(X[j]<X[j+1])
            {
                float temp=X[j];
                X[j]=X[j+1];
                X[j+1]=temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
                
                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;
            }
        }
    }
    int i=0;
    float totalProfit=0;
    while(M>0)
    {
        if(weight[i]>M)
        {
            totalProfit+=(float)M*X[i];
            M=0;
        }
        else
        {
            totalProfit+=(float)weight[i]*X[i];
            M=M-weight[i];
        }
        i++;
    }
    return totalProfit;
}

int main()
{
    int n;
    float M;
    printf("Enter the number of objects\n");
    scanf("%d",&n);
    float weight[n],profit[n];
    float X[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter weight %d ",i+1);
        scanf("%f",&weight[i]);
        printf("Enter profit %d ",i+1);
        scanf("%f",&profit[i]);
        X[i]=(float)profit[i]/weight[i];
    }

    printf("Enter knapsack size\n");
    scanf("%f",&M);

    float ans=knapsack(n,weight,profit,M,X);

    printf("Maximum profit is %f",ans);
    return 0;
}
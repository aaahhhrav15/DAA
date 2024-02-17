#include<stdio.h>
int max,min;

void maxmin(int arr[],int low,int high)
{
    int max1,min1;
    if(low==high)
    {
        max=min=arr[low];
    }
    else if(low==high-1)
    {
        if(arr[low]<arr[high])
        {
            max=arr[high];
            min=arr[low];
        }
        else
        {
            min=arr[high];
            max=arr[low];
        }
    }
    else
    {
        int mid=(low+high)/2;
        maxmin(arr,low,mid);
        max1=max;
        min1=min;
        maxmin(arr,mid+1,high);
        if(max1>max)
        {
            max=max1;
        }
        if(min1<min)
        {
            min=min1;
        }
        
    }
}

int main()
{
    int n,low,high;
    printf("Enter the no. of elements\n");
    scanf("%d",&n);
    int arr[n];
    low=0,high=n-1;
    printf("Enter the elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    max=min=arr[0];
    maxmin(arr,low,high);
    printf("Maximum element is %d\n",max);
    printf("Minimum element is %d\n",min);
    return 0;
}
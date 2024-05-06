#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    int exp=1;
    int temp[n];
    while(max/exp>0)
    {
        int count[10]={0};
        for(int i=0;i<n;i++)
        {
            count[(arr[i]/exp)%10]++;
        }
        for(int i=1;i<10;i++)
        {
            count[i]+=count[i-1];
        }
        for(int i=n-1;i>=0;i--)
        {
            temp[--count[(arr[i]/exp)%10]]=arr[i];
        }
        for(int i=0;i<n;i++)
        {
            arr[i]=temp[i];
        }
        exp*=10;
    }
    printf("Sorted array is\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
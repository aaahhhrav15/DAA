#include <stdio.h>

int main()
{
    int n,val,j,temp;
    printf("Enter the no. of elements in the array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val);
        a[i]=val;
    }
    for(int i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && temp<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }

    printf("The sorted array is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;    
}

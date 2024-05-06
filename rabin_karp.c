#include<stdio.h>
int main()
{
    char text[100],pattern[100];
    printf("Enter the text\n");
    scanf("%s",text);
    printf("Enter the pattern\n");
    scanf("%s",pattern);
    int n=0,m=0;
    for(int i=0;text[i]!='\0';i++)
    {
        n++;
    }
    for(int i=0;pattern[i]!='\0';i++)
    {
        m++;
    }   
    int q=101;
    int d=256;
    int h=1;
    for(int i=0;i<m-1;i++)
    {
        h=(h*d)%q;
    }
    int p=0;
    int t=0;
    for(int i=0;i<m;i++)
    {
        p=(d*p+pattern[i])%q;
        t=(d*t+text[i])%q;
    }
    for(int i=0;i<=n-m;i++)
    {
        if(p==t)
        {
            int j=0;
            for(j=0;j<m;j++)
            {
                if(text[i+j]!=pattern[j])
                {
                    break;
                }
            }
            if(j==m)
            {
                printf("Pattern found at index %d\n",i);
            }
        }
        if(i<n-m)
        {
            t=(d*(t-text[i]*h)+text[i+m])%q;
            if(t<0)
            {
                t=t+q;
            }
        }
    }
    return 0;
}
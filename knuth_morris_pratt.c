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
    int lps[m];
    lps[0]=0;
    int len=0;
    int i=1;
    while(i<m)
    {
        if(pattern[i]==pattern[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    i=0;
    int j=0;
    while(i<n)
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            printf("Pattern found at index %d\n",i-j);
            j=lps[j-1];
        }
        else if(i<n && text[i]!=pattern[j])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    
    return 0;
}
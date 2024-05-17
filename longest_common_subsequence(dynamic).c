#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs_length(char X[], char Y[], int m, int n, char lcs[])
{
    int L[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else
            {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    i = m;
    j = n;
    int index = L[m][n];
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    return L[m][n];
}

int main()
{
    char s1[100], s2[100], lcs[100]; 
    printf("Enter String 1:\n");
    scanf("%s", s1);
    printf("Enter String 2:\n");
    scanf("%s", s2);

    int m = strlen(s1);
    int n = strlen(s2);

    printf("Length of Longest Common Subsequence: %d\n", lcs_length(s1, s2, m, n, lcs));
    printf("Longest Common Subsequence: %s\n", lcs);
    return 0;
}

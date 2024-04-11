#include <stdio.h>

int main()
{
    int n;
    printf("Enter no. of matrices:\n");
    scanf("%d", &n);

    printf("Enter %d order of dimension\n", n);
    int arr[n + 1];
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int matrix[n][n];
    int s[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
            s[i][j] = 0;
        }
    }

    for (int d = 1; d < n; d++)
    {
        for (int i = 0; i < n - d; i++)
        {
            int j = i + d;
            int min = 32767;
            for (int k = i; k < j; k++)
            {
                int q = matrix[i][k] + matrix[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1];
                if (q < min)
                {
                    min = q;
                    s[i][j] = k;
                }
            }
            matrix[i][j] = min;
        }
    }

    printf("%d", matrix[0][n - 1]);
    return 0;
}
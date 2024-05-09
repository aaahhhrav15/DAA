#include <stdio.h>
#include <stdlib.h>

int find(int parent[], int i)
{
    while (parent[i] != 0)
    {
        i = parent[i];
    }
    return i;
}


int uni(int parent[], int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    int i, j, a, b, u, v, n, ne = 1;
    int cost[100][100];
    int min, mincost = 0;
    int parent[10] = {0};

    printf("\nEnter the no. of vertices:");
    scanf("%d", &n);
    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }

    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n)
    {
        for (i = 1; i <= n; i++)
        {
            min = 999;
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(parent, u);
        v = find(parent, v);
        if (uni(parent, u, v))
        {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n\tMinimum cost = %d\n", mincost);
    return 0;
}

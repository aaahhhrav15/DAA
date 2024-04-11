#include <stdio.h>

int main() {
    int stages = 4;
    int n = 8, min;
    int cost[9], d[9], path[9];
    int c[9][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 2, 1, 3, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 2, 3, 0, 0},
    {0, 0, 0, 0, 0, 0, 4, 2, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 7},
    {0, 0, 0, 0, 0, 0, 0, 0, 4},
    {0, 0, 0, 0, 0, 0, 0, 0, 5},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

    cost[n] = 0;
    for (int i = n - 1; i >= 1; i--) 
    {
        min = 1000000000; 
        for (int k = i + 1; k <= n; k++) 
        {
            if (c[i][k] != 0 && c[i][k] + cost[k] < min) 
            {
                min = c[i][k] + cost[k];
                d[i] = k;
            }
        }
        cost[i] = min;
    }

    path[1] = 1;
    path[stages] = n;
    for (int i = 2; i < stages; i++) 
    {
        path[i] = d[path[i - 1]];
    }

    printf("Optimal Path:\n");
    for (int i = 1; i < stages; i++) 
    {
        printf("%d -> ", path[i]);
    }
    printf("%d\n", path[stages]);
    printf("\n");
    printf("Minimum Cost: %d\n", cost[1]);

    return 0;
}
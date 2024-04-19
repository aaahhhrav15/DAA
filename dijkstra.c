#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void dijkstra(int s, int n, int cost[n][n], int dist[n]) 
{
    int visited[n], count, min, next;

    for (int i = 0; i < n; i++) 
    {
        dist[i] = cost[s][i];
        visited[i] = 0;
    }

    visited[s] = 1;
    count = 1;

    while (count < n) 
    {
        min = INT_MAX;
        next = -1;

        for (int i = 0; i < n; i++) 
        {
            if (!visited[i] && dist[i] < min) 
            {
                min = dist[i];
                next = i;
            }
        }

        if (next == -1) break;

        visited[next] = 1;
        count++;

        for (int i = 0; i < n; i++) 
        {
            if (!visited[i] && cost[next][i] != INT_MAX && dist[next] + cost[next][i] < dist[i]) 
            {
                dist[i] = dist[next] + cost[next][i];
            }
        }
    }
}

int main() {
    int n, s;
    printf("Enter the number of vertices of the graph: ");
    scanf("%d", &n);
    int cost[n][n], dist[n];

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("Enter the weight between vertices %d and %d: ", i + 1, j + 1); 
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) 
            {
                cost[i][j] = INT_MAX;
            }
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &s);
    s--; 

    dijkstra(s, n, cost, dist);

    printf("Shortest distances from source vertex %d:\n", s + 1); 
    for (int i = 0; i < n; i++) 
    {
        if (dist[i] == INT_MAX) 
        {
            printf("Vertex %d: Unreachable\n", i + 1); 
        } 
        else 
        {
            printf("Vertex %d: %d\n", i + 1, dist[i]); 
        }
    }

    return 0;
}

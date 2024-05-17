#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

void BellmanFord(int graph[][3], int V, int E, int src) 
{
    int dis[V];

    // Initialization: Set all distances to infinity except the source vertex
    for (int i = 0; i < V; i++)
    {
        dis[i] = INF;
    }
    dis[src] = 0;

    // Relax edges repeatedly for V-1 times
    for (int i = 0; i < V - 1; i++) 
    {
        for (int j = 0; j < E; j++) 
        {
            if (dis[graph[j][0]] != INF && dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])
            {
                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < E; i++) 
    {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
        if (dis[x] != INF && dis[x] + weight < dis[y])
        {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Print shortest distances
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d\t\t%d\n", i, dis[i]);
    }
}

int main()
{
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    
    int graph[E][3];
    printf("Enter source, destination, and weight for each edge:\n");
    for(int i = 0; i < E; i++)
    {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &graph[i][0], &graph[i][1], &graph[i][2]);
    }

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    BellmanFord(graph, V, E, src);

    return 0;
}

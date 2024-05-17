#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

void Dijkstra(int graph[][3], int V, int E, int src) 
{
    int dis[V];
    for (int i = 0; i < V; i++) 
    {
        dis[i] = INF;
    }
    dis[src] = 0;

    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < E; j++) 
        {
            if (dis[graph[j][0]] != INF && dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]] && graph[j][2] >= 0) 
            {
                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
            }
        }
    }

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

    Dijkstra(graph, V, E, src);

    return 0;
}

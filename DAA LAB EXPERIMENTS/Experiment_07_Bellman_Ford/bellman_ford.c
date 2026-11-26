#include <stdio.h>

#define V 5
#define E 8
#define INF 9999

struct Edge {
    int src, dest, weight;
};

int main() {
    struct Edge edges[E] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int dist[V];
    int i, j;

    for (i = 0; i < V; i++)
        dist[i] = INF;

    dist[0] = 0;

    for (i = 0; i < V - 1; i++) {
        for (j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    printf("Shortest distances from vertex 0:\n");

    for (i = 0; i < V; i++)
        printf("Vertex %d: %d\n", i, dist[i]);

    return 0;
}
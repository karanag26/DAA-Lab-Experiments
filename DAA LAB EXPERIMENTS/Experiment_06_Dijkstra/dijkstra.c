#include <stdio.h>

#define INF 9999

int main() {
    int graph[5][5] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int dist[5], visited[5] = {0};
    int i, j, min, u;

    for (i = 0; i < 5; i++)
        dist[i] = INF;

    dist[0] = 0;

    for (i = 0; i < 5; i++) {
        min = INF;
        u = -1;

        for (j = 0; j < 5; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < 5; j++) {
            if (graph[u][j] && !visited[j] &&
                dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("Shortest distances from vertex 0:\n");

    for (i = 0; i < 5; i++)
        printf("Vertex %d: %d\n", i, dist[i]);

    return 0;
}
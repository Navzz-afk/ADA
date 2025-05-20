#include <stdio.h>

#define INF 999

void dijkstra(int n, int cost[10][10], int src) {
    int i, j, u, dis[10], vis[10], min;


    for (i = 1; i <= n; i++) {
        dis[i] = cost[src][i];
        vis[i] = 0;
    }

    vis[src] = 1;

    for (i = 1; i < n; i++) {
        min = INF;
        u = -1;


        for (j = 1; j <= n; j++) {
            if (vis[j] == 0 && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }

        if (u == -1) break;

        vis[u] = 1;


        for (j = 1; j <= n; j++) {
            if (vis[j] == 0 && dis[u] + cost[u][j] < dis[j]) {
                dis[j] = dis[u] + cost[u][j];
            }
        }
    }

    printf("Shortest paths from vertex %d:\n", src);
    for (i = 1; i <= n; i++) {
        if (dis[i] == INF)
            printf("%d -> %d = INF\n", src, i);
        else
            printf("%d -> %d = %d\n", src, i, dis[i]);
    }
}

int main() {
    int src, j, cost[10][10], n, i;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 999 for no connection):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(n, cost, src);

    return 0;
}

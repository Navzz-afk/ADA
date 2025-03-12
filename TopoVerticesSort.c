#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
bool visited[MAX];
int stack[MAX];
int top = -1;
int n;


void push(int v) {
    stack[++top] = v;
}


void dfs(int node) {
    visited[node] = true;


    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }


    push(node);
}


void topologicalSort() {

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }


    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }


    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {

    printf("Enter number of vertices: ");
    scanf("%d", &n);


    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }


    topologicalSort();

    return 0;
}

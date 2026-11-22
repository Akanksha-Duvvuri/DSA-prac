#include<stdio.h>
#define MAX 100

int adj[MAX][MAX], visited[MAX];
int stack[MAX], top = -1;
int n;

void dfs(int v){
    visited[v] = 1;

    for(int i=0; i<n; i++){
        if(adj[v][i] && !visited[i]){
            dfs(i);
        }
    }

    stack[++top] = v;
}

void topologicalSort(){
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    printf("topological order: ");

    while(top != -1){
        printf("%d ", stack[top--]);
    }
}

int main(){
    int m, u, v;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topologicalSort();
    return 0;
}
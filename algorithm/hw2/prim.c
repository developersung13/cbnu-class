#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
 
#define MAX_VERTICES 20
#define MAX_EDGES 30
#define INF 1000L
 
int weight[MAX_VERTICES][MAX_VERTICES];
int selected[MAX_VERTICES];
int dist[MAX_VERTICES];
 
int get_min_vertex(int n) {
  int v, i;
   
  for (i = 0; i < n; i++) {
    if (selected[i] == FALSE) {
      v = i;
      break;
    }
  }
 
  for (i = 0; i < n; i++) {
    if (selected[i] == FALSE && (dist[i] < dist[v]))
      v = i;
  }
 
  return(v);
}
 
void prim(int s, int n) {
  int i, u, v;
 
  for (u = 0; u < n; u++) {
    dist[u] = INF;
    selected[u] = FALSE;
  }
 
  dist[s] = 0;
   
  for (i = 0; i < n; i++) {
    u = get_min_vertex(n);
    selected[u] = TRUE;
 
    if (dist[u] == INF) return;
     
    printf("%d ", u);
 
    for (v = 0; v < n; v++) {
      if (weight[u][v] != INF) {
        if (selected[v] == FALSE && weight[u][v] < dist[v])
          dist[v] = weight[u][v];
      }
    }
  }
}

void generate_graph() {
    int edgesAdded = 0;

    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            weight[i][j] = INF;
        }
    }

    while (edgesAdded < MAX_EDGES) {
        int u = rand() % MAX_VERTICES;
        int v = rand() % MAX_VERTICES;
        if (u != v && weight[u][v] == INF) {
            int random_weight = rand() % 100 + 1;
            weight[u][v] = random_weight;
            weight[v][u] = random_weight;
            edgesAdded++;
        }
    }
}

 
void main() {
    clock_t start, end;
    double cpu_time_used;
    srand(time(NULL));
    generate_graph();
    start = clock();
    prim(0, MAX_VERTICES);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("\nPrim's algorithm took %f milliseconds to execute \n", cpu_time_used);
}
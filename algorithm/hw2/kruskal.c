#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int start;
	int end;
	int weight;
} edge;

typedef struct {
	int parent;
	int depth;
} universe;

#define VERTEX_NUM 20
#define EDGE_NUM 30

int A_matrix[5][5] = { {0,1,3,0,0}, {1,0,3,6,0} , {3,3,0,4,2}, {0,6,4,0,5},{0,0,2,5,0} };

void kruskal(int n, int m, edge* E, edge* F);
void input(int vertex1, int vertex2, int w);
void initial(int n);
int find(int i);
void makeset(int i);
int equal(int p, int q);
void merge(int p, int q);

edge edge_info[EDGE_NUM];
universe U[VERTEX_NUM + 1];

int indexs = 0;
int f_index = 0;

int main() {
    edge result[EDGE_NUM];
    clock_t start, end;
    double cpu_time_used;
    int kruscal_MST[VERTEX_NUM][VERTEX_NUM] = {0};

    srand(time(NULL));

    while (indexs < EDGE_NUM) {
        int vertex1 = rand() % VERTEX_NUM + 1;
        int vertex2 = rand() % VERTEX_NUM + 1;
        int weight = rand() % 100 + 1;

        if (vertex1 == vertex2) {
            continue;
        }

        int duplicate = 0;
        for (int i = 0; i < indexs; i++) {
            if ((edge_info[i].start == vertex1 && edge_info[i].end == vertex2) ||
                (edge_info[i].start == vertex2 && edge_info[i].end == vertex1)) {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate) {
            input(vertex1, vertex2, weight);
        }
    }

    start = clock();
    kruskal(VERTEX_NUM, EDGE_NUM, edge_info, result);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;

    printf("Kruskal's algorithm took %f milliseconds to execute \n", cpu_time_used);

    for (int i = 0; i < f_index; i++) {
        kruscal_MST[result[i].start - 1][result[i].end - 1] = result[i].weight;
        kruscal_MST[result[i].end - 1][result[i].start - 1] = result[i].weight;
    }

    printf("  1 2 3 4 5  -> vertex number in the MST \n");
    for (int i = 0; i < VERTEX_NUM; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < VERTEX_NUM; j++) {
            printf("%d ", kruscal_MST[i][j]);
        }
        printf("\n");
    }
    printf("ㄴ vertex number in the MST \n");
}


void input(int vertex1, int vertex2, int w) {
	edge_info[indexs].start = vertex1;
	edge_info[indexs].end = vertex2;
	edge_info[indexs].weight = w;
	indexs += 1;
}

void kruskal(int n, int m, edge* E, edge* F) {
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (E[i].weight > E[j].weight)
			{
				edge temp = E[i];
				E[i] = E[j];
				E[j] = temp;
			}
		}
	}

	for (int i = 0; i < VERTEX_NUM; i++) {
		for (int j = 0; j < VERTEX_NUM - 1 - i; j++) {

			if (E[i].weight == E[i + 1].weight) {
				if (E[i].start > E[i + 1].start) {
					edge temp = E[i];
					E[i] = E[i + 1];
					E[i + 1] = temp;
				}
			}
		}

	}

	for (int i = 1; i < VERTEX_NUM + 1; i++) {
		U[i].parent = 0;
		U[i].depth = 0;
	}

	for (int i = 0; i < m; i++) {
		F[i].start = 0;
		F[i].end = 0;
		F[i].weight = 0;
	}

	initial(VERTEX_NUM);

	int find_start = 0;

	while (find_start < VERTEX_NUM) {
		int i, j, p, q;
		edge e = E[find_start];

		i = E[find_start].start;
		j = E[find_start].end;

		p = find(i);
		q = find(j);

		if (!equal(p, q))
		{
			merge(p, q);
			F[f_index] = E[find_start];
			f_index += 1;
		}

		find_start++;

		int count = 0;

		for (int i = 1; i < EDGE_NUM + 1; i++) {
			if (U[i].parent == i)
				count++;
		}

		if (count == 1) break;
	}
}

void initial(int n) {
	for (int i = 1; i < n + 1; i++) {
		makeset(i);
	}
}

void makeset(int i) {
	U[i].parent = i;
	U[i].depth = 0;
}

int find(int i) {
	int j;
	j = i;

	while (U[j].parent != j) {
		j = U[j].parent;
	}
	return j;
}

void merge(int p, int q) {
	if (U[p].depth == U[q].depth) {
		U[p].depth = U[q].depth;
		U[q].parent = p;
	} else if (U[q].depth < U[p].depth) {
		U[q].parent = p;
	} else {
		U[p].parent = q;
	}
}

int equal(int p, int q) {
	if (p == q) return 1;
	else return 0;
}
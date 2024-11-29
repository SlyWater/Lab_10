#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <queue> 
using namespace std;

int** createG(int size) {
    int** G = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; ++i) {
        G[i] = (int*)malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            G[i][j] = (rand() % 2) ? rand() % 10 : 0;
            G[j][i] = (i == j) ? 0 : G[i][j];
        }
    }
    return G;
}

int** createGO(int size) {
    int** G = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; ++i) {
        G[i] = (int*)malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            G[i][j] = (rand() % 2) ? rand() % 10 : 0;
            G[j][i] = (i == j) ? 0 : G[j][i];
        }
    }
    return G;
}

void printG(int** G, int size) {
    printf("  ");
    for (int i = 0; i < size; ++i) printf("%2d ", i);
    printf("\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", i);
        for (int j = 0; j < size; ++j) {
            printf("%2d ", G[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void DiFS(int** G, int size, int* dist, int s) {
    queue <int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
        s = q.front();
        q.pop();

        for (int i = 0; i < size; ++i) {
            if (G[s][i] && dist[i] == -1) {
                q.push(i);
                dist[i] = dist[s] + G[s][i];

            }
        }
    }
}

void createDist(int** G, int size, int** D) {
    int* dist = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) dist[j] = -1;
        DiFS(G, size, dist, i);
        for (int j = 0; j < size; ++j) D[i][j] = dist[j];
    }
}


int main() {
    srand(time(NULL));
    int n = 4;
    int** G = createGO(n);
    printG(G, n);
    int** D = (int**)malloc(n * sizeof(int*));
    int* ecc = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        D[i] = (int*)malloc(n * sizeof(int));
    }
    createDist(G, n, D);
    printG(D, n);


    return 0;
}
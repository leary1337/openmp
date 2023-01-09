#include <omp.h>
#include <cstdio>
#include <cmath>

#define THREAD_NUM 8
#define size 1000
int a[size][size];
int b[size][size];
int c[size][size];

void generate_matrix() {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            a[i][j] = rand() % 100;
            b[i][j] = rand() % 100;
        }
    }
}

int main() {
    int i, j, k;
    generate_matrix();

    double startTime = omp_get_wtime();
#pragma omp parallel for num_threads(THREAD_NUM)
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            for (k = 0; k < size; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("Time: %lf\n", omp_get_wtime() - startTime);
    return 0;
}
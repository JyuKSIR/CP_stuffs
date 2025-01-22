#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5000

int ar[N+1][N+1];

int main() {
    
	clock_t start_time = clock();

    srand(time(0));

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
                if(i<=j) ar[i][j] = ar[j][i] = rand() % 6;
        }
    }

    long long edge = 0,sumdeg = 0;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (ar[i][j]){
                if (i == j) {
                    edge += ar[i][j];
                    sumdeg += 2 * ar[i][j];
                }
				else if(i<j){
                    edge += ar[i][j];
                }
                if(i!=j) sumdeg+=ar[i][j];
            }
        }
    }
	clock_t end_time = clock();

    printf("Number of edges: %lld\n", edge);
    printf("Sum of degrees: %lld\n", sumdeg);

	(sumdeg == 2*edge) ? printf("Handshaking theorum holds\n") : printf("Handshaking theorum didn't hold\n");

    double execution_time_ms = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000;

    printf("Execution time: %.3f ms\n", execution_time_ms);

    return 0;
}

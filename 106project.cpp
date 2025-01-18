#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int n = 5000;
int ar[n+1][n+1];
int deg[n+1];

int main() {
    srand(time(0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(i!=j) ar[i][j] = ar[j][i] =  rand() % 2;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            //cout << ar[i][j] << " ";
        }
        //cout << "\n";
    }

    long long edge = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (ar[i][j] == 1) {
                edge++;
            }
        }
    }
    long long sumdeg = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ar[i][j] == 1) {
                deg[i]++;
            }
        }
        sumdeg += deg[i];
    }

    cout << "\nnumber of edges: " << edge << endl;
    cout << "degrees of vertices:" << "\n";
    for (int i = 1; i <= n; ++i) {
        //cout << "vertex " << i << ": " << deg[i] << endl;
    }
    cout << "sum of degrees: " << sumdeg << endl;

    return 0;
}



















#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5000

int ar[N + 1][N + 1];
int deg[N + 1];

int main() {
    srand(time(0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j) {
                ar[i][j] = ar[j][i] = rand() % 2;
            }
        }
    }

    long long edge = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (ar[i][j] == 1) {
                edge++;
            }
        }
    }
    long long sumdeg = 0;
    for (int i = 1; i <= N; i++) {
        deg[i] = 0;
        for (int j = 1; j <= N; j++) {
            if (ar[i][j] == 1) {
                deg[i]++;
            }
        }
        sumdeg += deg[i];
    }
    printf("\nNumber of edges: %lld\n", edge);
    printf("Sum of degrees: %lld\n", sumdeg);

    return 0;
}

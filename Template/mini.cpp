#include <chrono>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random directed graph represented by an adjacency matrix
vector<vector<int>> generateRandomGraph(int n) {
    vector<vector<int>> graph(n, vector<int>(n, 0));

    // Seed for random number generation
    srand(time(NULL));

    // Generating random edges
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Randomly decide whether there is an edge from i to j
            graph[i][j] = rand() % 2;
        }
    }

    return graph;
}

int main() {
    int n = 3000;

    // Start time measurement
    auto start = chrono::steady_clock::now();

    // Generate random directed graph
    vector<vector<int>> graph = generateRandomGraph(n);

    // Calculate in-degrees and out-degrees
    vector<int> inDegree(n, 0);
    vector<int> outDegree(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            outDegree[i] += graph[i][j];
            inDegree[j] += graph[i][j];
        }
    }

    // Check if sum of in-degrees equals sum of out-degrees
    int sumInDegrees = 0, sumOutDegrees = 0;
    for (int i = 0; i < n; ++i) {
        sumInDegrees += inDegree[i];
        sumOutDegrees += outDegree[i];
    }

    // End time measurement
    auto end = chrono::steady_clock::now();
    // Calculate duration in milliseconds
    auto diff = end - start;
    cout << "Time taken: " << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    // Display results
    cout << "Sum of in-degrees: " << sumInDegrees << endl;
    cout << "Sum of out-degrees: " << sumOutDegrees << endl;

    return 0;
}

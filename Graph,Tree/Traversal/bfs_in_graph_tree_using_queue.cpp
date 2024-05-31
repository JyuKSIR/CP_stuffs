//-----> **breadth first search/level order traversal**
//reference video --> https://www.youtube.com/watch?v=M8jdDR5kV3k&t=875s

// **input**   
// 7 12        
// 0 1
// 0 6
// 0 2
// 2 3
// 2 6
// 6 4
// 1 6
// 1 4
// 1 5
// 4 5
// 4 3
// 5 3
// **output**
// parent vertex: 0
// child vertex: 1 6 2 
// parent vertex: 1
// child vertex: 0 6 4 5 
// parent vertex: 2
// child vertex: 0 3 6 
// parent vertex: 3
// child vertex: 2 4 5 
// parent vertex: 4
// child vertex: 6 1 5 3 
// parent vertex: 5
// child vertex: 1 4 3 
// parent vertex: 6
// child vertex: 0 2 4 1 
// Breadth first search order: 0 1 6 2 4 5 3 
// The level of vertex 0 is: 0
// The level of vertex 1 is: 1
// The level of vertex 2 is: 1
// The level of vertex 3 is: 2
// The level of vertex 4 is: 2
// The level of vertex 5 is: 2
// The level of vertex 6 is: 1


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N=100;

vector<int> visited(N);

vector<vector<int>> graph(N);

vector<int> level(N);


void bfs(int starting_vertex){

    cout << "Breadth first search order: ";

    queue<int> q;

    q.push(starting_vertex);

    visited[starting_vertex] = 1;

    while(!q.empty()){

        int current_vertex = q.front();

        q.pop();

        cout << current_vertex << " ";

        for(auto child_vertex : graph[current_vertex]){

            if(visited[child_vertex] == 0){

                q.push(child_vertex);

                visited[child_vertex] = 1;

                level[child_vertex] = level[current_vertex] + 1;

            }
        }
    }
    cout << "\n";
}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int vertices,edges;

    cin >> vertices >> edges;
    //taking input of the graph/tree
    for(int i=0; i<edges; i++){

        int vertex1;

        int vertex2;

        cin >> vertex1 >> vertex2;

        graph[vertex1].push_back(vertex2);

        graph[vertex2].push_back(vertex1);
    }
    //printing graph/tree

    for(int i=0; i<vertices; i++){

        cout << "parent vertex: " << i << "\n";

        cout << "child vertex: ";

        for(auto x : graph[i]){

            cout << x << " ";
        }
        cout << "\n";
    }

    //starting the breadth first search/level order search

    bfs(0); //starting vertex = 0

    //level of each vertex;

    for(int i=0; i<vertices; i++){

        cout << "The level of vertex " << i << " is: " << level[i] << "\n";
    }

    return 0;
}

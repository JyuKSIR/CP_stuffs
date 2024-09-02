// Lowest Common Ancestor
//reference ----> https://www.youtube.com/watch?v=il2HXsJPGO4&list=PLauivoElc3ghxyYSr_sVnDUc_ynPk6iXE&index=10

//**Input**

// 13 12
// 1 2
// 1 3
// 1 13
// 2 5
// 5 6
// 5 7
// 5 8
// 8 12
// 3 4
// 4 9
// 4 10
// 10 11
// 6 7

// ** Output**

// The lowest common ancestor of node 6 and node 7 is 5


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N=100;

vector<vector<int>> graph(N);

vector<int> level(N);

vector<int> parent(N);

void dfs(int v, int par = -1){
    parent[v] = par;
    for(int child : graph[v]){
        if(child == par){
            continue;
        }
        dfs(child,v);
    }
}

vector<int> path(int v){
    vector<int> ans;
    while( v != -1){
        ans.push_back(v);
        v = parent[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


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

    dfs(1);

    int x,y;
    cin >> x >> y;
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);

    int min_ln = min(path_x.size(),path_y.size());

    int lca = -1;

    for(int i=0; i<min_ln; i++){
        if(path_x[i] == path_y[i]){
            lca = path_x[i];
        }
        else{
            break;
        }
    }
    cout << "The lowest common ancestor of node " << x << " and node " << y << " is " << lca << "\n";
}
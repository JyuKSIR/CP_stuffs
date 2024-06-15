//topological sort using dfs
//https://www.youtube.com/watch?v=dis_c84ejhQ - references
//graph sould be directed and acyclic
// if you get the dfs ordering in a directed acyclic and if you reverse it you will get the topological order
//**input**
// 5 6
// 1 2
// 1 4
// 2 3
// 4 5
// 2 4
// 4 3
// **output**
// parent: 1
// child: 2 4 
// parent: 2
// child: 3 4 
// parent: 3
// child: 
// parent: 4
// child: 5 3 
// parent: 5
// child: 
// order: 1
// parent: 1 child: 2
// order: 2
// parent: 2 child: 3
// order: 3
// parent: 2 child: 4
// order: 4
// parent: 4 child: 5
// order: 5
// parent: 4 child: 3
// parent: 1 child: 4
// topological order: 1 2 4 5 3 
#include<bits/stdc++.h>
using namespace std;

const int N=100;

vector<int> graph[N];

int vis[N];

vector<int> topo_order;

void dfs_function(int node){
    cout << "order: " <<node << "\n";
    vis[node]=1;
    for(int child : graph[node]){
        cout<<"parent: "<<node<<" child: "<<child<<"\n";
        if(vis[child]!=1){
            dfs_function(child);
        }  
    }
    topo_order.push_back(node);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0; i<edges; ++i){
        int node1;
        int node2;
        cin>>node1>>node2;
      graph[node1].push_back(node2);
    }
    for(int i=1; i<=nodes; ++i){
        cout << "parent: " << i << "\n" <<"child: ";
        for(int x : graph[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    for(int i=1; i<=nodes; i++){ // if there is node not connected to any nodes of graph
        if(vis[i]==0){
            dfs_function(i);
        }
    }
    reverse(topo_order.begin(),topo_order.end());
    cout << "topological order: ";
    for(int y : topo_order){
        cout << y << " ";
    }
    return 0;
}

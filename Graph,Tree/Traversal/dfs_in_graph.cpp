//depth_first_search in graph
//https://www.youtube.com/watch?v=9_ftWKch6vI&list=PLauivoElc3ghxyYSr_sVnDUc_ynPk6iXE&index=4-references
//**input**
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
//**output**
// parent : 0
// child: 1 6 2 
// parent : 1
// child: 0 6 4 5 
// parent : 2
// child: 0 3 6 
// parent : 3
// child: 2 4 5 
// parent : 4
// child: 6 1 5 3 
// parent : 5
// child: 1 4 3 
// parent : 6
// child: 0 2 4 1 
// order: 0
// parent: 0 child: 1
// order: 1
// parent: 1 child: 0
// parent: 1 child: 6
// order: 6
// parent: 6 child: 0
// parent: 6 child: 2
// order: 2
// parent: 2 child: 0
// parent: 2 child: 3
// order: 3
// parent: 3 child: 2
// parent: 3 child: 4
// order: 4
// parent: 4 child: 6
// parent: 4 child: 1
// parent: 4 child: 5
// order: 5
// parent: 5 child: 1
// parent: 5 child: 4
// parent: 5 child: 3
// parent: 4 child: 3
// parent: 3 child: 5
// parent: 2 child: 6
// parent: 6 child: 4
// parent: 6 child: 1
// parent: 1 child: 4
// parent: 1 child: 5
// parent: 0 child: 6
// parent: 0 child: 2
// dfs order: 0 1 6 2 3 4 5 

#include<bits/stdc++.h>
using namespace std;

const int N=100;

vector<int> graph[N];

int vis[N];

vector<int> dfs_order;

void dfs_function(int node){
    cout << "order: " <<node << "\n";
    dfs_order.push_back(node);
    vis[node]=1;
    for(int child : graph[node]){
        cout<<"parent: "<<node<<" child: "<<child<<"\n";
        if(vis[child]!=1){
            dfs_function(child);
        }  
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //taking input and output of graph;
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0; i<edges; ++i){
        int node1;
        int node2;
        cin>>node1>>node2;
      graph[node1].push_back(node2);
      graph[node2].push_back(node1);
    }
    for(int i=0; i<nodes; ++i){
        cout << "parent : " <<i << "\n" <<"child: ";
        for(int x : graph[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    //Depth first search in the graph;
    //let the dfs in graph starts with node: 0
    dfs_function(0);
    cout << "dfs order: ";
    for(int y : dfs_order){
        cout << y << " ";
    }
    return 0;
}

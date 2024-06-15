//depth_first_search in graph
//https://www.youtube.com/watch?v=9_ftWKch6vI&list=PLauivoElc3ghxyYSr_sVnDUc_ynPk6iXE&index=4-references
#include<bits/stdc++.h>
using namespace std;

const int N=100;

vector<int> graph[N];

int vis[N];

void dfs_function(int node){
    cout<<node<<"\n"; //order of dfs
    vis[node]=1;
    for(int child : graph[node]){
        cout<<"parent: "<<node<<" child: "<<child<<"\n";
        if(vis[child]!=1){
            dfs_function(child); //keep calling the function till the nodes are visited
        }  
    }
}

int main(){
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
        cout << "parent : " <<i << "\n" <<"child: " << "\n";
        for(int x : graph[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    //Depth first search in the graph;
    //let the dfs in graph starts with node: 0
    dfs_function(0);

    return 0;
}

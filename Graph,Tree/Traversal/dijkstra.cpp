//**input**
// 7 11 1 2
// 1 3 3
// 1 6 2
// 3 6 2
// 3 4 4
// 3 5 1
// 4 2 1
// 5 2 2
// 5 6 3
// 6 7 5
// 7 2 2
// 6 2 6
// **output**
// The dijkstra traversal order: 1 6 3 5 5 2 4 7 2 
// Taken shortest time from node 1 to 2 is: 6

// references
// -->https://www.youtube.com/watch?v=EFg3u_E6eHU
// -->https://www.youtube.com/watch?v=F3PNsWE6_hM&t=57s

#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int,int>> g[N]; // while storing the graph --> node first,weight second

int dijkstra(int source, int dest){

    cout << "The dijkstra traversal order: ";

    vector<int> vis(N,0); //making visited array elements 0
    vector<int> dist(N,INF); // making the distance infinite

    set<pair<int,int>> st; //in function --> weight first,node second | cause it will be sorted by weight

    st.insert({0,source});
    dist[source] = 0;

    while(!st.empty()){
        auto node = *st.begin();
        int n_dist = node.first;
        int n = node.second;
        cout << n << " "; //printig the order | keep tracks where it's going
        st.erase(st.begin());
        if(vis[n]) continue;
        vis[n] = 1;

        for(auto child : g[n]){

           int child_n = child.first;
           int wt = child.second;

           if(dist[n] + wt < dist[child_n]){   // if distance is minimum then the previous distance put it in
            dist[child_n] = dist[n] + wt;
            st.insert({dist[child_n],child_n}); //put in the set
           }
        }
    }
    return dist[dest];
}

int main(){

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n,m,s,t;
  cin >> n >> m >> s >> t;
  for(int i=0; i<m; i++){
    int x,y,wt;
    cin >> x >> y >> wt;
    g[x].push_back({y,wt});
    g[y].push_back({x,wt});
  }
  
  int ans = dijkstra(s,t);

  cout <<"\nTaken shortest time from node " << s << " to " << t << " is: " << ans;

  return 0;
}

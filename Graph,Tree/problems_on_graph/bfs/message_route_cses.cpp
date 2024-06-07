#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

vector<int> visited,par,lev;


#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

vector<int> bfs(int parent){

    vector<int> b_f_s;

    queue<int> q;
    
    q.push(parent);

    visited[parent]=1;

    while(!q.empty()){

        int par_v = q.front();

        q.pop();

        b_f_s.push_back(par_v);
        
        for(auto chi_v : graph[par_v]){
           
           if(!visited[chi_v]){

            q.push(chi_v);

            visited[chi_v]=1;

            par[chi_v] = par_v;

            lev[chi_v] = lev[par_v] + 1;

           }
        }
    }
    return b_f_s;
}

void solve(){
    
    vector<int> check;

    vector<int> ans;

    int n,m,flag=0,temp=0;
    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1, 0);
    par.resize(n + 1, 0);
    lev.resize(n + 1, 0);


    while(m--){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    check = bfs(1);
    
    for(int i=0; i<check.size(); i++){

        if(n == check[i]){

            flag++;
        }
    }
    if(flag==1){

        for(int i=n; i>=1; i=temp){

            ans.push_back(i);

            temp = par[i];
        }
        reverse(ans.begin(),ans.end());

        cout << ans.size() << "\n";

        for(auto x : ans){

            cout << x << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE";
    }
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}

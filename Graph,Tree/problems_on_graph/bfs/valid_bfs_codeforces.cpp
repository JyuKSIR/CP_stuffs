//https://codeforces.com/contest/1037/problem/D

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 10e5+5;
vector<vector<int>> graph(N);
vector<int> visited(N);
vector<int> parent(N);
vector<int> level(N);

void bfs(int start_node){

   queue<int> q;

   q.push(start_node);
   visited[start_node]=1;

   while(!q.empty()){
     int first = q.front();
     q.pop();
     for(int b : graph[first]){
        if(visited[b]==0){
            q.push(b);
            visited[b]=1;
            parent[b]=first;
            level[b]=level[first]+1;
        }
     }
   }
}
bool check(vector<int> &check){
    int depth = 0;
    for (auto v : check){
        if (level[v] != depth){
            depth++;
            if (level[v] != depth){
                return false;
            }
        }
    }
    return true;
}
bool check2(vector<int> &check2){

    queue<int> q1;

    q1.push(1);

    for (auto u : check2){

        if (u == q1.front()){
            
            continue;
        }
        else{

            while (parent[u] != q1.front()){

                q1.pop();

                if (q1.empty()){
                    return false;
                }
            }
            q1.push(u);

        }
    }
        return true;
}


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int nodes;
    cin >> nodes;
    for(int i=0; i<nodes-1; i++){
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<int> input(nodes);

    for(int i=0; i<nodes; i++){
        cin >> input[i];
    }

    bfs(1);

    // for(int i=1; i<=nodes; i++){
    //     cout << "child :" << i << "\n" << "parent :" << parent[i] << "\n"; 
    // }
    
    // for(int i=1; i<=nodes; i++){
    //     cout << "child :" << i << "\n" << "level :" << level[i] << "\n"; 
    // }
    
    // for(int i=1; i<=nodes; i++){
    //     cout << "node: " << i << "\n";
    //     cout << "child nodes: ";
    //     for(int a : graph[i]){
    //         cout << a << " ";
    //     }
    //     cout << "\n";
    // }

    if(check(input) && check2(input)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}

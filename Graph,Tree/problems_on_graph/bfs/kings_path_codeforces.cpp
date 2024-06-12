#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

map<int, map<int, int>> allow; //2d map automatically 0 while declaring
map<int, map<int, int>> vis;   // can't take array or vector for memory related issue
map<int, map<int, int>> lev;

void allow_paths(int row, int col1, int col2){  //the allowed paths on chessboard
    for(int i = col1; i <= col2; i++){
        allow[row][i] = 1;
    }
}

vector<pair<int,int>> king_moves = {{1,1}, {-1,-1}, {1,0}, {0,1}, {1,-1}, {-1,1}, {-1,0}, {0,-1}}; // king can move such a way

int bfs(int ix1, int iy2, int fx1, int fy2){
    queue<pair<int,int>> q;
    q.push(make_pair(ix1, iy2));
    vis[ix1][iy2] = 1;
    lev[ix1][iy2] = 0;
    
    while(!q.empty()){
        pair<int,int> p = q.front();
        int par_x = p.first;
        int par_y = p.second;
        q.pop();
        
        for(auto move : king_moves){
            int chi_x = par_x + move.first;   //movement of king
            int chi_y = par_y + move.second;   // movement of king
            
            if(allow[chi_x][chi_y] == 1 && vis[chi_x][chi_y] == 0){
                q.push(make_pair(chi_x, chi_y));
                vis[chi_x][chi_y] = 1;
                lev[chi_x][chi_y] = lev[par_x][par_y] + 1;
                
                if(chi_x == fx1 && chi_y == fy2) {
                    return lev[chi_x][chi_y]; //level will be the minimum distance
                }
            }
        }
    }
    
    return -1;
}

void solve(){
    int ix, iy, fx, fy, n, r, c1, c2; // r = row, c1 = initial column, c2 = final column
    cin >> ix >> iy >> fx >> fy;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> r >> c1 >> c2;
        allow_paths(r, c1, c2);
    }
    
    int ans = bfs(ix, iy, fx, fy);
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}

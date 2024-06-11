//https://www.youtube.com/watch?v=WOV3LYhPews&t=847s
// reference
//Nakanj_SPOJ

#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

int lev[8][8];
int vis[8][8];

void reset(){ //resets visited array and level array to o
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      vis[i][j]=0;
      lev[i][j]=0;
    }
  }
}
bool valid(int c,int d){  //if the position is valid or not or in the chessboard or not
    return c>=0 && c<8 && d>=0 && d<8;
}
vector<pair<int,int>> movements = {{-1,2},{1,2},{-1,-2},{1,-2},{2,-1},{2,1},{-2,-1},{-2,1}}; // possible movements of knight

int bfs(int k,int l,int m,int n){  //initial position (k,l) , final position (m,n)

  queue<pair<int,int>> q;
  q.push(make_pair(k,l));
  vis[k][l]=1;

  while(!q.empty()){
    pair<int,int> p = q.front();
    int a = p.first;
    int b = p.second;
    q.pop();
    for(auto movement : movements){
      int chi_a = a + movement.first;   // adding the movement vectors element with parent and make it child
      int chi_b = b + movement.second;
      if(!valid(chi_a,chi_b)){  //if not valid don't run the code block
        continue;
      }
      if(!vis[chi_a][chi_b]){
        q.push(make_pair(chi_a,chi_b));
        vis[chi_a][chi_b] = 1;
        lev[chi_a][chi_b] = lev[a][b] + 1;
      }
    }
  }
  return lev[m][n]; // level of final position

}

void solve(){
    
    reset();
    string s1,s2;
    int x1,y1,x2,y2;
    cin >> s1 >> s2;
    x1 = s1[0] - 'a';
    y1 = s1[1] - '1';
    x2 = s2[0] - 'a';
    y2 = s2[1] - '1';
    cout << bfs(x1,y1,x2,y2)<< "\n";

}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin>>t;
  while(t--){
    solve();
  }

  return 0;
}

// *** Floyd Warshall Algorithm 

// Reference
// --> https://www.youtube.com/watch?v=5MEZXOyaRmk

// **input**
// 6 9
// 1 2 1
// 1 3 5
// 2 3 2
// 3 5 2
// 2 5 1
// 2 4 2
// 4 5 3
// 4 6 1
// 5 6 2
// **output**
// 0  1  3  3  2  4  
// inf 0  2  2  1  3  
// inf inf 0  inf 2  4  
// inf inf inf 0  3  1  
// inf inf inf inf 0  2  
// inf inf inf inf inf 0  


#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

const int N = 500;
const int inf = 1e9;

int dis[N][N];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i == j){
                dis[i][j] = 0;
            }
            else{
                dis[i][j] = inf;
            }
        }
    }

    int n,m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int x,y,wt; cin >> x >> y >> wt;
        dis[x][y] = wt;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                // for negative weighted graph
                if(dis[i][k] != inf && dis[j][k] != inf){
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
                }
                // for positive weighted graph
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dis[i][j] == inf){
                cout << "inf ";
            }
            else{
                cout << dis[i][j] << "  ";
            }
        }
        cout << "\n";
    }

  return 0;
}

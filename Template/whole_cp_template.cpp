#include <iostream>     // Input/output stream objects
#include <fstream>       // File stream objects
#include <sstream>      // String stream objects
#include <iomanip>      // Input/output manipulators
#include <string>         // String class and functions
#include <vector>        // Dynamic array
#include <list>              // Doubly linked list
#include <set>              // Set container
#include <map>            // Map container
#include <queue>           // Queue container
#include <stack>             // Stack container
#include <algorithm>     // Algorithms on sequences (e.g., sort, find)
#include <cmath>           // Mathematical functions
#include <ctime>            // Date and time functions
#include <cstdlib>          // General purpose functions (e.g., memory management)
#include <cstring>          // C-style string functions
#include <cctype>           // Character classification functions
#include <cassert>          // Assert function for debugging
#include <exception>     // Standard exceptions
#include <functional>     // Function objects
#include <iterator>         // Iterator classes
#include <limits>             // Numeric limits
#include <locale>             // Localization and internationalization
#include <numeric>         // Numeric operations (e.g., accumulate)
#include <random>          // Random number generators
#include <stdexcept>      // Standard exception classes
#include <typeinfo>         // Runtime type information
#include <utility>              // Utility components (e.g., std::pair)
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <complex>
#include <deque>
#include <cstdio>
#include <memory.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl
#define ll long long
#define ld long double
#define vt vector
#define pb push_back
#define mp make_pair
#define f(a) (a).begin()
#define l(a) (a).end()
#define full(a) (a).begin(), (a).end()
#define sort(a) sort(full(a))
#define each(x,b) for (auto &x : b)
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"

void solve(){

    

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





#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 10e5+5;
vector<vector<int>> graph(N);
vector<int> visited(N);

void bfs(int start_node){
   queue<int> q;

   q.push(start_node);
   visited[start_node]=1;

   while(!q.empty()){
     int first = q.front();
     cout << first << "\n";
     q.pop();
     //cout << first << "\n";
     for(int b : graph[start_node]){
        if(visited[b]==0){
            q.push(b);
            visited[b]=1;
        }
     }

   }
}

int main(){
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
    int temp = input[0];

    for(int i=0; i<nodes; i++){
        if(temp > input[i]){
            temp = input[i];
        }
    }
    cout << temp << "\n";
    bfs(temp);

    for(int i=0; i<nodes; i++){
        cout << "node: " << i+1 << "\n";
        cout << "child nodes: ";
        for(int a : graph[i]){
            cout << a << " ";
        }
        cout << "\n";
    }

}


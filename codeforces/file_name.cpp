#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl
#define ll long long
#define ld long double
#define vt vector
#define pb push_back
#define mp make_pair
#define first(a) (a).begin()
#define last(a) (a).end()
#define full(a) (a).begin(), (a).end()
#define sort(a) sort(full(a))
#define each(x,b) for (auto &x : b)
#define max(c,d) (c>d?c:d)
#define min(c,d) (c<d?c:d)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

void solve(){

   int n,k,remove=0;
   string s;
   cin>>n>>s;
   k=s.size();
   for(int i=0; i<k; ++i){
    if(s[i]=='x' && s[i+1]=='x' && s[i+2]=='x'){
        s.erase(first(s)+(i+2));
        --i;
    }
   }
  remove=k-s.size();
  cout<<remove; 
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

    solve();

  return 0;
}
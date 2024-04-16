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

    int n,k,x=0,step=0;
    cin>>n>>k;

    vt<int>v;

    for(int i=0; i<n; ++i){
        int a;
        cin>>a;
        v.pb(a);
    }
    sort(v);
    if(k==0){
        cout<<v[0]-1;
    }
    else{
        for(int i=0; i<v[n-1]; ++i){
        step=0;
           for(int j=0; j<n; ++j){
              if(i>=v[j]){
                step++;
              }
        }
        if(step==k){
            x=i;
            break;
        }
    }
        if(x==0){
        cout<<"-1";
        }
        else{
        cout<<x;
        }
    }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
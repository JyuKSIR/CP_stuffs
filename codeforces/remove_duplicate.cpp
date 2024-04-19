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
    int n, ar[n], arr[1000];
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>ar[i];
    }
    vt<int>v;
    fill(arr, arr+1000,0);
    for(int i=n-1; i>=0; --i){
        if(arr[ar[i]]==0){
           arr[ar[i]]=1;
           v.pb(ar[i]);
         }
    }
    reverse(full(v));
    cout<<v.size()<<"\n";
    each(a,v){
      cout<<a<<" ";
    }   
 }
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

void solve(){
    vector<pair<string,int>>v;
    int n,max;
    cin>>n;
    string s,output;
    cin>>s;
    for(int i=0; i<n-1; ++i){
        string a;
        a.clear();
        a=s.substr(i,2);//first parameter(where to start, number of character)
        //cout<<a<<endl;
        v.pb(make_pair(a,0));
    }
    /*for(int i=0; i<v.size(); ++i){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }*/
    for(int i=0; i<v.size(); ++i){
        for(int j=0; j<n-1; ++j){
            string b;
            b.clear();
            b=s.substr(j,2);
            if(v[i].first==b){
                v[i].second++;
            }
        }
    }
    /*for(int i=0; i<v.size(); ++i){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }*/
    max=v[0].second;
    output=v[0].first;
    for(int i=0; i<v.size(); ++i){
        if(max<v[i].second){
            max=v[i].second;
            output=v[i].first;
        }
    }
  cout<<output;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //int t;
    //cin>>t;
    //while(t--){
        solve();
    //}

  return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

ll bc,sc,cc;
ll kb,ks,kc,pb,ps,pc,mh;

bool f(ll z){

	ll nb=z*bc,ns=z*sc,nc=z*cc;
	ll nmb=nb-kb,nms=ns-ks,nmc=nc-kc;
	ll nm=0;
	if(nmb>0) nm+=pb*nmb;
	if(nms>0) nm+=ps*nms;
	if(nmc>0) nm+=pc*nmc;
	
    if(nm<=mh) return 0;
    else return 1;	
}

void solve(){

   string s; cin >> s;
   cin >> kb >> ks >> kc >> pb >> ps >> pc >> mh;
   for(char c:s){
	   if(c == 'B') bc++;
	   if(c == 'S') sc++;
	   if(c == 'C') cc++;   
   }
   ll l=1,r=1e13;
   while(l<=r){
	   ll m = (r+l)/2;
	   if(f(m)) r = m-1;
       else l = m+1;	   
   }
   cout << r << "\n";

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

       solve();

  return 0;
}

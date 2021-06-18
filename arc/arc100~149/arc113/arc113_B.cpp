#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second<<'\n'; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';




ll modPow(ll a,ll e,ll p){
  if(e==0) return 1;
  if(e%2==0){
    ll res=modPow(a,e/2,p);
    return (res*res)%p;
  }else{
    ll res=modPow(a,e-1,p);
    res=(res*a)%p;
    return res;
  }
}


int main() {
  ll a,b,c;
  cin>>a>>b>>c;


  a%=10;
  if(a==0){
    cout<<0<<endl;
  }else if(a==1){
    cout<<1<<endl;
  }else if(a==2){
    ll n=modPow(b,c,4);
    n--;
    if(n<0) n+=4;

    vector<int> ans={2,4,8,6};
    cout<<ans[n]<<endl;

  }else if(a==3){
    ll n=modPow(b,c,4);
    n--;
    if(n<0) n+=4;

    vector<int> ans={3,9,7,1};
    cout<<ans[n]<<endl;

  }else if(a==4){
    ll n=modPow(b,c,2);
    n--;
    if(n<0) n+=2;

    vector<int> ans={4,6};
    cout<<ans[n]<<endl;

  }else if(a==5){
    ll n=modPow(b,c,1);
    n--;
    if(n<0) n+=1;

    vector<int> ans={5};
    cout<<ans[n]<<endl;

  }else if(a==6){
    ll n=modPow(b,c,1);
    n--;
    if(n<0) n+=1;

    vector<int> ans={6};
    cout<<ans[n]<<endl;

  }else if(a==7){
    ll n=modPow(b,c,4);
    n--;
    if(n<0) n+=4;

    vector<int> ans={7,9,3,1};
    cout<<ans[n]<<endl;

  }else if(a==8){
    ll n=modPow(b,c,4);
    n--;
    if(n<0) n+=4;

    vector<int> ans={8,4,2,6};
    cout<<ans[n]<<endl;

  }else if(a==9){
    ll n=modPow(b,c,2);
    n--;
    if(n<0) n+=2;

    vector<int> ans={9,1};
    cout<<ans[n]<<endl;

  }
}
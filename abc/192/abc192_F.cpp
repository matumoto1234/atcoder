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

ll n,x;
vector<ll> a;
vector<ll> rui;

vector<vector<ll>> dp;
ll dfs(int l,int r){
  cout<<l<<' '<<r<<endl;
  ll k=r-l;
  if(l+1==r){
    if((a[l]*k)!=0&&x%(a[l]*k)==0){
      return x/(a[l]*k);
    }else{
      return INF64-1;
    }
  }

  ll &res=dp[l][r];
  if(res!=INF64) return res;
  ll sum=(rui[r]-rui[l])*k;
  if(sum!=0&&x%sum==0){
    res=x/sum;
  }

  range(m,l,r){
    res=min(res,dfs(l,m));
  }
  return res;
}

int main() {
  cin>>n>>x;

  a.resize(n);
  rui.resize(n+1);
  dp.assign(n,vector<ll>(n+1,INF64));

  range(i,0,n){
    cin>>a[i];
  }

  range(i,0,n) rui[i+1]=rui[i]+a[i];

  cout<<dfs(0,n)<<endl;
}
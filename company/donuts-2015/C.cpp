#include <bits/stdc++.h>
#include <atcoder/segtree.hpp>
using namespace atcoder;
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ull = unsigned long long;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr char newl = '\n';

int op(int a,int b){ return max(a,b); }
int e(){ return -INF32; }

vector<int> compress(vector<int> a){
  int n=a.size();
  vector<int> res=a;
  sort(a.begin(),a.end());
  map<int,int> mp;
  for(int i=0;i<n;i++){
    mp[a[i]]=i;
  }
  for(int i=0;i<n;i++){
    res[i]=mp[res[i]];
  }
  return res;
}

constexpr int MAXN = 100000;
int n;
vector<int> h;
segtree<int,op,e> seg(MAXN);
vector<int> ans;
int dfs(int i){
  int idx=seg.prod(h[i],n);
  cerr<<"i:"<<i<<" idx:"<<idx<<endl;
  if(idx==i){
    ans[i]=i;
    return ans[i];
  }

  int &res=ans[i];
  if(res!=-1) return res;
  res=0;

  res+=i-idx;
  res+=dfs(idx);
  return res;
}

int main() {
  cin>>n;
  h.resize(n);
  range(i,0,n){
    cin>>h[i];
  }

  h=compress(h);

  range(i,0,n){
    seg.set(h[i],i);
  }

  ans.assign(n,-1);
  rrange(i,0,n){
    dfs(i);
  }
  range(i,0,n){
    cout<<ans[i]<<newl;
  }
}
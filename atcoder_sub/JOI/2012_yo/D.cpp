#include <bits/stdc++.h>
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
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

const int MOD = 10000;

vector<int> pre;
vector<vector<vector<int>>> dp;
int n,k;
int dfs(int i,int j,int k){
  int &res=dp[i][j][k];
  if(i==n-1){
    if(pre[i]==-1) res=1;
    else if(pre[i]==j) res=0;
    res=1;
  }
  if(res!=-1) return res;

  res=0;
  range(l,0,3){
    if(l==j&&l==k) continue;
    if(pre[i+1]!=-1 && pre[i+1]!=l) continue;
    //if(i==1) cout<<"l:"<<l<<" j:"<<j<<" k:"<<k<<newl;
    res+=dfs(i+1,l,j);
    res%=MOD;
  }
  return res;
}

int main() {
  cin>>n>>k;
  pre.assign(n,-1);
  range(i,0,k){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    pre[a]=b;
  }

  dp.assign(n,vector<vector<int>>(3,vector<int>(3,-1)));
  int ans=0;
  range(j,0,3) range(k,0,3){
    if(pre[0]!=-1 && pre[0]!=k) continue;
    if(pre[1]!=-1 && pre[1]!=j) continue;
    ans+=dfs(1,j,k);
    ans%=MOD;
  }
  cout<<ans<<endl;
}
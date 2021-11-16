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
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr int dy[] = {0,-1,1,0,-1,1,-1,1};
constexpr int dx[] = {-1,0,0,1,-1,-1,1,1};
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = (int)1e9 + 7;
constexpr char newl = '\n';

set<int> ngs;

vector<vector<int>> dp(301,vector<int>(101,-1));
bool dfs(int n,int cnt){
  if(n==0 && cnt<=100) return true;
  if(n<0 || cnt>100) return false;

  if(ngs.find(n)!=ngs.end()) return false;

  int &res=dp[n][cnt];
  if(res!=-1) return res;
  res=0;
  res|=dfs(n-1,cnt+1);
  res|=dfs(n-2,cnt+1);
  res|=dfs(n-3,cnt+1);
  return res;
}

int main() {
  int n;
  cin>>n;

  range(i,0,3){
    int ng;
    cin>>ng;
    ngs.insert(ng);
  }

  cout<<(dfs(n,0)?"YES":"NO")<<endl;
}
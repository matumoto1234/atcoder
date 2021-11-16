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
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

int main() {
  int n,c;
  cin>>n>>c;
  const int MAXN = 100000+2;
  vector<vector<int>> imos(c,vector<int>(MAXN,0));
  range(i,0,n){
    int s,t,d;
    cin>>s>>t>>d;
    d--;
    imos[d][s]++;
    imos[d][t]--;
  }

  range(i,0,c) range(j,1,MAXN){
    imos[i][j]+=imos[i][j-1];
  }

  range(i,0,c) range(j,1,MAXN){
    if(imos[i][j]&&imos[i][j+1]==0){
      imos[i][j+1]=1;
      j++;
    }
  }

  int ans=0;
  range(j,1,MAXN){
    int sum=0;
    range(i,0,c){
      sum+=imos[i][j];
    }
    chmax(ans,sum);
  }
  cout<<ans<<endl;
}
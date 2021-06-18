#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
using ll = long long;
using lP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF = INT64_MAX / 2LL;
const int inf = INT32_MAX / 2;

const int h=5;
vector<vector<int>> s;
// j列目をcol色に塗ったときのコスト
ll cost(int j,int col){
  ll res=0;
  range(i,0,h){
    if(s[i][j]!=col) res++;
  }
  return res;
}

int ctoi(char c){
  if(c=='R') return 0;
  if(c=='B') return 1;
  if(c=='W') return 2;
  return 3;
}

int main() {
  int w;
  cin>>w;
  s.assign(h,vector<int>(w));
  vector<string> input(h);
  range(i,0,h){
    cin>>input[i];
    range(j,0,w){
      s[i][j]=ctoi(input[i][j]);
    }
  }

  vector<vector<ll>> dp(3,vector<ll>(w,INF));
  range(col,0,3){
    dp[col][0]=cost(0,col);
  }

  range(i,1,w){
    range(col,0,3) range(ncol,0,3){
      if(col==ncol) continue;
      chmin(dp[ncol][i],cost(i,ncol)+dp[col][i-1]);
    }
  }
  ll ans=INF;
  range(col,0,3){
    chmin(ans,dp[col][w-1]);
  }
  cout<<ans<<endl;
}
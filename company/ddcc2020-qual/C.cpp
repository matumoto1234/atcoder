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

int group;
vector<vector<int>> groups;
vector<string> s;
void divide(int sy,int sx){
  int l=sx,r=sx;
  rrange(i,0,sx){
    if(s[sy][i]=='#' || groups[sy][i] != -1) break;
    l=i;
  }

  range(i,sx+1,s[0].size()){
    if(s[sy][i]=='#' || groups[sy][i] != -1) break;
    r=i;
  }

  // cerr<<"group:"<<group<<" l:"<<l<<" r:"<<r<<endl;

  int u=sy,d=sy;

  rrange(i,0,sy){
    bool valid=true;
    range(j,l,r+1){
      if(s[i][j]=='#' || groups[i][j] != -1){
        valid=false;
        break;
      }
    }
    if(!valid) break;
    u=i;
  }

  range(i,sy+1,s.size()){
    bool valid=true;
    range(j,l,r+1){
      if(s[i][j]=='#' || groups[i][j] != -1){
        valid=false;
        break;
      }
    }
    if(!valid) break;
    d=i;
  }

  range(i,u,d+1){
    range(j,l,r+1){
      groups[i][j]=group;
    }
  }
}

int main() {
  int h,w,k;
  cin>>h>>w>>k;

  s = vector<string>(h);

  range(i,0,h){
    cin>>s[i];
  }

  group=1;
  groups = vector<vector<int>>(h,vector<int>(w,-1));
  range(i,0,h){
    range(j,0,w){
      if(s[i][j]=='#'){
        divide(i,j);
        group++;
      }
    }
  }

  range(i,0,h){
    cout<<groups[i]<<newl;
  }
}
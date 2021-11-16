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

vector<string> line_symmetry(const vector<string> &s){
  vector<string> res=s;
  range(i,0,res.size()){
    reverse(res[i].begin(),res[i].end());
  }
  return res;
}

vector<string> line_symmetry2(const vector<string> &s){
  vector<string> res=s;
  reverse(res.begin(),res.end());
  return res;
}

vector<string> point_symmetry(const vector<string> &s){
  vector<string> res=s;
  range(i,0,res.size()){
    reverse(res[i].begin(),res[i].end());
  }
  reverse(res.begin(),res.end());
  return res;
}

int stodir(string w){
  if(w=="R") return 3;
  if(w=="L") return 0;
  if(w=="U") return 1;
  if(w=="D") return 2;
  if(w=="RU") return 6;
  if(w=="RD") return 7;
  if(w=="LU") return 4;
  if(w=="LD") return 5;
  return INF32;
}

int main() {
  int x,y;
  string w;
  cin>>x>>y>>w;
  x--,y--;

  vector<string> s(9);
  range(i,0,9){
    cin>>s[i];
  }

  auto ps=point_symmetry(s);
  auto ls2 = line_symmetry2(s);

  vector<vector<char>> ns(27,vector<char>(27));
  range(i,0,9) range(j,0,9){
    ns[i+1][j+1]=ps[i][j%9];
  }
  range(i,0,9) range(j,9,18){
    ns[i+1][j]=ls2[i][j%9];
  }
  range(i,0,9) range(j,18,27){
    ns[i+1][j-1]=ps[i][j%9];
  }

  auto ls = line_symmetry(s);
  range(i,9,18) range(j,0,9){
    ns[i][j+1]=ls[i%9][j];
  }

  range(i,9,18) range(j,9,18){
    ns[i][j]=s[i%9][j%9];
  }

  range(i,9,18) range(j,18,27){
    ns[i][j-1]=ls[i%9][j%9];
  }

  range(i,18,27) range(j,0,9){
    ns[i-1][j+1]=ps[i%9][j%9];
  }
  range(i,18,27) range(j,9,18){
    ns[i-1][j]=ls2[i%9][j%9];
  }
  range(i,18,27) range(j,18,27){
    ns[i-1][j-1]=ps[i%9][j%9];
  }

  x+=9;
  y+=9;

  // range(i,0,27) cerr<<ns[i]<<endl;

  int dir=stodir(w);
  string ans="";
  range(i,0,4){
    ans+=ns[y][x];
    y+=dy[dir];
    x+=dx[dir];
  }
  cout<<ans<<endl;
}
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

char itoc(int i){
  if(i==0) return 'x';
  if(i==1) return '.';
  return 'o';
}

int main() {
  int a,b;
  cin>>a>>b;
  vector<int> p(a),q(b);
  vector<int> pin(10,0);
  range(i,0,a){
    cin>>p[i];
    pin[p[i]]=1;
  }

  range(i,0,b){
    cin>>q[i];
    pin[q[i]]=2;
  }
  
  vector<string> ans(4);
  range(i,7,11){
    if(i==10){
      ans[0]+=itoc(pin[0]);
      break;
    }
    ans[0]+=itoc(pin[i]);
    ans[0]+=' ';
  }

  ans[1]+=' ';
  range(i,4,7){
    ans[1]+=itoc(pin[i]);
    if(i!=6) ans[1]+=' ';
  }

  ans[2]+=' ';
  ans[2]+=' ';
  range(i,2,4){
    ans[2]+=itoc(pin[i]);
    if(i!=3) ans[2]+=' ';
  }

  ans[3]+=' ';
  ans[3]+=' ';
  ans[3]+=' ';
  range(i,1,2){
    ans[3]+=itoc(pin[i]);
    if(i!=1) ans[3]+=' ';
  }

  range(i,0,4){
    cout<<ans[i]<<endl;
  }
}
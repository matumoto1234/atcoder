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

int main() {
  int n;
  string s;
  int q;
  cin>>n>>s>>q;

  int si=0;
  range(i,0,q){
    int t,a,b;
    cin>>t>>a>>b;
    if(t==2){
      si+=n;
      si%=2*n;
      continue;
    }
    a--;
    b--;

    int i1=(si+a)%(2*n);
    int i2=(si+b)%(2*n);
    swap(s[i1],s[i2]);
  }
  range(i,0,2*n){
    int idx=(si+i)%(2*n);
    cout<<s[idx];
  }
  cout<<newl;
}
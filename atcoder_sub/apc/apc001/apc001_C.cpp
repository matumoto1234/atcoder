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

int main() {
  int n;
  cin>>n;

  cout<<0<<endl;
  string s;
  cin>>s;
  vector<bool> p(2,0);
  if(s=="Vacant"){
    return 0;
  }

  if(s=="Male"){
    p[0]=1;
    p[1]=0;
  }else{
    p[0]=0;
    p[1]=1;
  }

  int l,r;
  l=0;
  r=n;
  range(_,0,19){
    int mid=(l+r)/2;
    cout<<mid<<endl;
    cin>>s;
    if(s=="Vacant") break;
    if(s=="Male"){
      if(p[mid%2]==1) l=mid;
      else r=mid;
    }else{
      if(p[mid%2]==0) l=mid;
      else r=mid;
    }
  }
}
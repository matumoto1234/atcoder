#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using LP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int t;
  cin>>t;
  range(i,0,t){
    ll l,r;
    cin>>l>>r;
    ll n=r-l-l+1;
    if(n<=0){
      cout<<0<<'\n';
      continue;
    }
    cout<<(n+1)*n/2<<'\n';
  }
}

/* memo
A-B=C
A=B+C
BとCは最小でL,足してL+L
よって、L <= A <= Rを満たすには
Rは2L以上でなくてはならない。
*/
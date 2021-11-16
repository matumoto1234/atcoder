#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second<<'\n'; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

// 1-indexed
class SmallestPrimeFactor {
public:
  SmallestPrimeFactor(int N):ps(N + 1,1){
    build();
  }

  vector<int> factorize(int x){
    vector<int> res;
    while(ps[x]!=1){
      res.push_back(ps[x]);
      x/=ps[x];
    }
    return res;
  }

  int operator[](int i) { return ps[i]; }

private:
  vector<int> ps;

  void build() {
    for (long long i = 2; i < ps.size(); i++) {
      if (ps[i] != 1) continue;
      ps[i] = i;
      for (long long j = i * i; j < ps.size(); j += i) {
        if (ps[j] != 1) continue;
        ps[j] = i;
      }
    }
  }
};
int main() {
  SmallestPrimeFactor spf(51);
  vector<int> ps;
  range(i,0,51){
    if(spf[i]==i){
      ps.emplace_back(i);
    }
  }

  ll n;
  cin>>n;
  vector<ll> x(n);
  range(i,0,n){
    cin>>x[i];
  }

  ll ans=INF64;
  int sz=ps.size();
  range(i,0,1<<sz){
    vector<bool> bit(sz,false);
    range(j,0,sz){
      if(i>>j&1) bit[j]=true;
    }

    ll seki=1;
    range(j,0,sz){
      if(bit[j]) seki*=ps[j];
    }

    bool flg=true;
    range(j,0,n){
      if(gcd(seki,x[j])==1) flg=false;
    }

    if(flg) chmin(ans,seki);
  }

  cout<<ans<<endl;
}
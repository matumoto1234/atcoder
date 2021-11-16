#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;

// 1-indexed
class FastPrimeFactor {
public:
  FastPrimeFactor(int N):ps(N + 1,1){
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
  int n;
  cin>>n;

  FastPrimeFactor pf(n);
  vector<int> cnt(n+1,0);
  range(i,1,n+1){
    vector<int> v=pf.factorize(i);
    for(int x:v){
      cnt[x]++;
    }
  }
  const ll MOD = 1e9+7LL;
  ll ans=1;
  range(i,0,n+1){
    if(cnt[i]==0) continue;
    ans*=cnt[i]+1;
    ans%=MOD;
  }
  cout<<ans<<endl;
}

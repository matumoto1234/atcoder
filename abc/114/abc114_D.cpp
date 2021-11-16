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


// 1-indexed
class SmallestPrimeFactor {
public:
  SmallestPrimeFactor(int N):ps(N + 1,1){
    build();
  }

  vector<int> factorize_v(int x){
    vector<int> res;
    while(ps[x]!=1){
      res.push_back(ps[x]);
      x/=ps[x];
    }
    return res;
  }

  map<int,int> factorize_map(int x){
    map<int,int> res;
    while(ps[x]!=1){
      res[ps[x]]++;
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
  ll n;
  cin>>n;
  SmallestPrimeFactor pf(n);

  map<int,int> factors;
  range(i,2,n+1){
    vector<int> primes=pf.factorize_v(i);
    for(int p:primes){
      factors[p]++;
    }
  }

  int cnt3,cnt5,cnt15,cnt25,cnt75;
  cnt3=cnt5=cnt15=cnt25=cnt75=0;
  for(auto &[v,e]:factors){
    e++;
    if(e>=3) cnt3++;
    if(e>=5) cnt5++;
    if(e>=15) cnt15++;
    if(e>=25) cnt25++;
    if(e>=75) cnt75++;
  }

  int ans=0;
  ans+=cnt5*(cnt5-1)*(cnt3-2)/2;
  ans+=cnt15*(cnt5-1);
  ans+=cnt25*(cnt3-1);
  ans+=cnt75;

  cout<<ans<<endl;
}
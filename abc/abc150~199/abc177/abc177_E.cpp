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
class PrimeFactor {
public:
  PrimeFactor(int N):ps(N + 1,1){
    build();
  }

  vector<int> factorization(int x){
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

const int MAX = 1000000;

int n;
vector<int> a;
bool pairwise(){
  set<int> s;
  PrimeFactor p(MAX);
  range(i,0,n){
    vector<int> v=p.factorization(a[i]);
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int x:v){
      if(s.find(x)!=s.end()) return false;
      s.insert(x);
    }
  }
  return true;
}

bool setwise(){
  int accum_gcd=a[0];
  range(i,1,n){
    accum_gcd=__gcd(a[i],accum_gcd);
  }
  return accum_gcd==1;
}

int main() {
  const string ans1="pairwise coprime";
  const string ans2="setwise coprime";
  const string ans3="not coprime";

  cin>>n;
  a.resize(n);
  range(i,0,n){
    cin>>a[i];
  }
  if(pairwise()){
    cout<<ans1<<endl;
  }else if(setwise()){
    cout<<ans2<<endl;
  }else{
    cout<<ans3<<endl;
  }
}
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

vector<long long> divisor(long long n){
  vector<long long> res;
  for(long long i=1;i*i<=n;i++){
    if(n%i==0){
      res.push_back(i);
      if(i*i!=n) res.push_back(n/i);
    }
  }
  sort(res.begin(),res.end());
  return res;
}

int main() {
  int n;
  cin>>n;
  int ans=0;
  range(i,1,n+1){
    vector<ll> a=divisor((ll)i);
    if(i%2==1&&(int)a.size()==8){
      ans++;
    }
  }
  cout<<ans<<endl;
}
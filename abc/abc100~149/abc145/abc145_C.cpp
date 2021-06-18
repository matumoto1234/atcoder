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

long double dist(Pll a,Pll b){
  return sqrtl((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

ll factorial(ll a){
  if(a==0) return 1;
  return factorial(a-1)*a;
}

int main() {
  int n;
  cin>>n;
  vector<Pll> citys(n);
  range(i,0,n){
    cin>>citys[i].first>>citys[i].second;
  }

  vector<int> idx(n);
  iota(idx.begin(),idx.end(),0);

  long double sum=0;
  do{
    range(i,0,n-1){
      sum+=dist(citys[idx[i]],citys[idx[i+1]]);
    }
    //cerr<<sum<<endl;
  }while(next_permutation(idx.begin(),idx.end()));

  //cerr<<factorial(n)<<endl;
  //cerr<<sum<<endl;

  long double ans = (long double)sum/(long double)factorial(n);
  cout<<fixed<<setprecision(10);
  cout<<ans<<endl;
}
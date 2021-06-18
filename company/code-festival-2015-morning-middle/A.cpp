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

template <class T,bool (*is_valid)(T, T)>
struct BinarySearch{
  T valid_;
  T invalid_;
  BinarySearch(){};
  BinarySearch(T v,T iv):valid_(v),invalid_(iv){}

  void set_valid(T v,T iv){
    valid_=v;
    invalid_=iv;
  }

  T build(T target){
    auto valid=valid_;
    auto invalid=invalid_;

    while(abs(invalid-valid)>1){
      auto mid = (valid + invalid) / 2;
      if (is_valid(mid,target)) valid = mid;
      else invalid = mid;
    }
    return valid;
  }
};

ll n,k,m,r;
ll sum=0;
bool is_valid(ll mid,ll target){
  return sum+mid>=k*r;
}

int main() {
  cin>>n>>k>>m>>r;
  vector<ll> s(n,0);
  range(i,0,n-1) cin>>s[i];

  sort(s.rbegin(),s.rend());

  range(i,0,k-1) sum+=s[i];

  if(sum+s[k-1]>=r*k){
    cout<<0<<endl;
    return 0;
  }

  if(sum+m<r*k){
    cout<<-1<<endl;
    return 0;
  }

  BinarySearch<ll,is_valid> bs(m,-1);

  cout<<bs.build(-1)<<endl;
}
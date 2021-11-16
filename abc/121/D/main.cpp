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

// [0,x]をxorする
ll solve(ll x){
  ll length=x+1;

  // x xor (x+1) = 1のようにペアを作る
  if(length%2==0){
    ll pairnum=length/2;

    // 1をpairの個数だけxorした結果
    if(pairnum%2==0){
      return 0;
    }else{
      return 1;
    }
  }else{
    // lengthが奇数の場合、xだけペアがない
    ll pairnum=length/2;

    if(pairnum%2==0){
      return 0^x;
    }else{
      return 1^x;
    }
  }
}

int main() {
  ll a,b;
  cin>>a>>b;
  // [a,b]の範囲
  // [0,b]から[0,a-1]の逆演算をする
  // xorの逆演算はxor
  ll ans=solve(a-1)^solve(b);
  cout<<ans<<endl;
}
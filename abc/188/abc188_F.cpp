#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
using ll = long long;
using LP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF = INT64_MAX / 2LL;
const int inf = INT32_MAX / 2;

map<ll,ll> mp;
ll x;
ll solve(ll y){
  if(x==y) return 0;
  if(x>y) return abs(x-y);
  //cerr<<x<<' '<<y<<" mp[y]:"<<mp[y]<<endl;

  ll res=mp[y];
  if(res!=0) return res;
  res=mp[y]=INF;

  if(y%2==0) {
    res=min(solve(y/2)+1,abs(x-y));
  }
  else res = min(solve(y-1)+1, solve(y+1)+1);

  return mp[y] = res;
}

int main() {
  ll y;
  cin>>x>>y;

  x=abs(x);
  y=abs(y);

  cout<<solve(y)<<endl;
}
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

ll solve(ll y,ll m,ll d){
  /*
  if(m==2&&d==29){
    m=3;
    d=1;
  }
  */
  if(m<=2){
    y--;
    m+=12;
  }
  ll res=0;
  res+=365*y;
  res+=y/4;
  res-=y/100;
  res+=y/400;
  res+=(306*(m+1))/10;
  res+=d;
  res-=429;
  return res;
}

bool isuru(ll y){
  if(y%4==0){
    if(y%100==0&&y%400!=0) return false;
    return true;
  }
  return false;
}

int main() {
  ll y,m,d;
  cin>>y>>m>>d;
  cout<<solve(2014,5,17)-solve(y,m,d)<<endl;
}
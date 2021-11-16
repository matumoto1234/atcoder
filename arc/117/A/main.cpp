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

int main() {
  int a,b;
  cin>>a>>b;

  vector<ll> ans;
  if(a>b){
    range(i,0,min(a,b)){
      ll v=1e8-(i*101);
      ans.emplace_back(v);
      ans.emplace_back(-v);
    }
    a-=b;
    int sum=(a+1)*a/2;
    ans.back()-=sum;

    for(int i=1;i<=a;i++){
      ans.emplace_back(i);
    }
  }else{
    range(i,0,min(a,b)){
      ll v=1e8-(i*101);
      ans.emplace_back(-v);
      ans.emplace_back(v);
    }
    b-=a;
    int sum=(b+1)*b/2;
    ans.back()+=sum;

    for(int i=1;i<=b;i++){
      ans.emplace_back(-i);
    }
  }

  sort(ans.begin(),ans.end());

//  ll sum=0;
//  range(i,0,ans.size()){
//    sum+=ans[i];
//  }
//  cerr<<"sum:"<<sum<<" size:"<<ans.size()<<endl;
//  cerr<<"front:"<<ans.front()<<" back:"<<ans.back()<<endl;

  cout<<ans<<endl;
}
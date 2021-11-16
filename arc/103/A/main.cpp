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
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr char newl = '\n';

int main() {
  int n;
  cin>>n;
  vector<vector<P>> vs(2,vector<P>(100001));
  range(i,0,n){
    int v;
    cin>>v;
    auto &[cnt,val]=vs[i%2][v];
    cnt++;
    val=v;
  }

  range(i,0,2){
    sort(vs[i].rbegin(),vs[i].rend());
  }

  int ans;
  if(vs[0][0].second!=vs[1][0].second){
    int sum=0;
    sum+=vs[0][0].first;
    sum+=vs[1][0].first;
    cerr<<vs[0][0]<<endl;
    cerr<<vs[1][0]<<endl;
    ans=sum;
  }else{
    int sum1=0;
    sum1+=vs[0][0].first;
    sum1+=vs[1][1].first;

    int sum2=0;
    sum2+=vs[0][1].first;
    sum2+=vs[1][0].first;

    ans=max(sum1,sum2);
  }
  ans=n-ans;
  cout<<ans<<endl;
}
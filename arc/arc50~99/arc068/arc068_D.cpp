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
  int n;
  cin>>n;
  const int MAXA=1e5;
  vector<int> cnt(MAXA+2,0);
  range(i,0,n){
    int a;
    cin>>a;
    cnt[a]++;
  }

  cnt[0]=cnt[MAXA+1]=INF32;
  int ans=0;
  int l=1,r=MAXA;
  while(l<=r){
    while(cnt[l]<=1) l++;
    while(cnt[r]<=1) r--;
    if(l>r) break;
    if(l!=r){
      cnt[l]--;
      cnt[r]--;
    }else{
      if(cnt[l]==2) ans=-1,cnt[l]--;
      else cnt[l]-=2;
    }
  }

  range(i,1,MAXA+1){
    ans+=cnt[i];
  }
  cout<<ans<<endl;
}
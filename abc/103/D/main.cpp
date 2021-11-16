#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using LP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  vector<vector<int>> v(n);
  range(i,0,m){
    int a,b;
    cin>>a>>b;
    v[b-1].push_back(a-1);
  }

  int ans=0;
  int erase_pos=-1;
  range(i,0,n) {
    for(int a:v[i]) {
      if(erase_pos>a) continue;
      erase_pos=i;
      ans++;
    }
  }
  cout<<ans<<endl;
}
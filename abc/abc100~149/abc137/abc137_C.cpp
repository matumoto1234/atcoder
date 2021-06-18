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
  int n;
  cin>>n;
  vector<string> s(n);
  range(i,0,n){
    cin>>s[i];
    sort(s[i].begin(),s[i].end());
  }
  sort(s.begin(),s.end());
  s.push_back("zzzzzzzzzzzzzzzZZZZz");

  ll ans=0;
  ll cnt=1;
  range(i,1,n+1){
    if(s[i]==s[i-1]){
      cnt++;
    }else{
      ans+=(cnt*(cnt-1))/2;
      cnt=1;
    }
  }
  cout<<ans<<endl;
}
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
  int t,n;
  cin>>t>>n;
  queue<int> a;
  range(i,0,n){
    int A;
    cin>>A;
    a.push(A);
  }
  int m;
  cin>>m;
  queue<int> b;
  range(i,0,m){
    int B;
    cin>>B;
    b.push(B);
  }
  if(n<m){
    cout<<"no"<<endl;
    return 0;
  }

  bool ans=true;
  range(i,0,m){
    if(a.front()>b.front()){
      ans=false;
      break;
    }

    while(!a.empty()){
      if(b.front()-a.front()>t){
        a.pop();
        continue;
      }
      break;
    }
    if(a.empty()){
      ans=false;
      break;
    }
    a.pop();
    b.pop();
  }
  cout<<(ans?"yes":"no")<<endl;
}
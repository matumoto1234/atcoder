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
  vector<string> w(n);
  range(i,0,n){
    cin>>w[i];
  }

  int ans=-1;
  char pre=w[0].front();
  set<string> words;

  range(i,0,n){
    if(pre!=w[i].front() || words.find(w[i])!=words.end()){
      ans=i%2;
      break;
    }
    pre=w[i].back();
    words.insert(w[i]);
  }

  if(ans==-1) cout<<"DRAW"<<endl;
  else if(ans==0) cout<<"LOSE"<<endl;
  else if(ans==1) cout<<"WIN"<<endl;
}
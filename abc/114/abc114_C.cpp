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

int n;
int dfs(string s,bool flg3,bool flg5,bool flg7){
  if(s!=""&&stoll(s)>n) return 0;

  int res=0;
  if(flg3&&flg5&&flg7) {
    res++;
  }

  res+=dfs(s+"3",true,flg5,flg7);

  res+=dfs(s+"5",flg3,true,flg7);

  res+=dfs(s+"7",flg3,flg5,true);

  return res;
}

int main() {
  cin>>n;
  cout<<dfs("",false,false,false)<<endl;
}
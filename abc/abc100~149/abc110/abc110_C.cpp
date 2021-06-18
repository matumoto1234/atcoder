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
  string s,t;
  cin>>s>>t;
  vector<int> cnt1(26,0);
  vector<int> cnt2(26,0);
  range(i,0,s.size()){
    int idx=s[i]-'a';
    cnt1[idx]++;
  }

  range(i,0,t.size()){
    int idx=t[i]-'a';
    cnt2[idx]++;
  }

  map<int,int> mp1;
  map<int,int> mp2;
  range(i,0,26){
    mp1[cnt1[i]]++;
  }

  range(i,0,26){
    mp2[cnt2[i]]++;
  }

  if(mp1!=mp2){
    cout<<"No"<<endl;
  }else{
    cout<<"Yes"<<endl;
  }
}
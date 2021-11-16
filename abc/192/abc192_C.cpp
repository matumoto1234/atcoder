#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second<<'\n'; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

using ull = unsigned long long;
int n,k;

ull s_toll(string s){
  ull res=0;
  range(i,0,s.size()){
    res*=10;
    res+=s[i]-'0';
  }
  return res;
}

ull g1(string s){
  sort(s.begin(),s.end(),greater<char>());
  return s_toll(s);
}

ull g2(string s){
  sort(s.begin(),s.end());
  return s_toll(s);
}

string itos(ull x){
  string res;
  while(x>0){
    res.push_back(x%10+'0');
    x/=10;
  }
  reverse(res.begin(),res.end());
  return res;
}

ull solve(string a,int i){
  if(i==k) return s_toll(a);

  ull x=g1(a)-g2(a);
  return solve(itos(x),i+1);
}

int main() {
  string s;
  cin>>s>>k;
  cout<<solve(s,0)<<endl;
}
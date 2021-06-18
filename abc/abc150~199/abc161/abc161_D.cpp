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

void carry(string &s,int i){
  if((int)s.size()-1==i){
    if(s[i]=='9'){
      s+='1';
      s[i]='0';
    }else{
      s[i]=s[i]+1;
    }
    return;
  }

  s[i]=s[i]+1;
  if(abs(s[i+1]-s[i])>1 || s[i]>'9'){
    carry(s,i+1);
    s[i]=max<char>('0',s[i+1]-1);
  }
}

void next_num(string &s){
  carry(s,0);
}

void debug(string s){
  reverse(s.begin(),s.end());
  cerr<<s<<newl;
}

int main() {
  int k;
  cin>>k;

  string s="0";
  while(k){
    k--;

    next_num(s);
    //debug(s);
  }
  reverse(s.begin(),s.end());
  cout<<s<<endl;
}
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

bool find(vector<char> &c,char target){
  range(i,0,c.size()){
    if(c[i]==target) return true;
  }
  return false;
}

int main() {
  vector<string> s(3);
  cin>>s[0]>>s[1]>>s[2];

  vector<char> c;
  range(i,0,3) range(j,0,s[i].size()){
    if(!find(c,s[i][j])) c.emplace_back(s[i][j]);
  }

  if((int)c.size()>10){
    cout<<"UNSOLVABLE"<<endl;
    return 0;
  }

  sort(c.begin(),c.end());

  map<char,int> mp;

  vector<ll> ns(3,0);

  bool ans=false;
  int sz=c.size();

  vector<int> idx(10);
  iota(idx.begin(),idx.end(),0);

  do{
    ns.assign(3,0);
    range(i,0,sz) mp[c[i]]=idx[i];

    bool flg=false;
    range(i,0,3){
      range(j,0,s[i].size()){
        ns[i]*=10;
        ns[i]+=mp[s[i][j]];
        if(ns[i]==0&&j==0) flg=true;
      }
    }

    if(flg) continue;

    // cout<<ns[0]<<' '<<ns[1]<<' '<<ns[2]<<endl;
    if(ns[0]+ns[1]==ns[2]){
      ans=true;
      break;
    }
  }while(next_permutation(idx.begin(),idx.end()));

  if(ans){
    range(i,0,3){
      cout<<ns[i]<<endl;
    }
  }else{
    cout<<"UNSOLVABLE"<<endl;
  }
}
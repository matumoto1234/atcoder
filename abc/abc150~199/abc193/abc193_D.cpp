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

template <typename T1,typename T2>
T1 Pow(T1 a,T2 e){
  if(e==0) return 1;
  if(e%2==0){
    T1 res=Pow(a,e/2);
    return res*res;
  }
  return Pow(a,e-1)*a;
}

bool battle(string s,string t){
  vector<int> cnt1(10,0),cnt2(10,0);
  range(i,0,5){
    cnt1[s[i]-'0']++;
    cnt2[t[i]-'0']++;
  }

  int v1=0,v2=0;
  range(i,1,10){
    v1+=i*Pow(10,cnt1[i]);
    v2+=i*Pow(10,cnt2[i]);
  }
  return v1>v2;
}

int main() {
  ll k;
  string s,t;
  cin>>k>>s>>t;

  vector<ll> rem(10,k);
  range(i,0,4){
    rem[s[i]-'0']--;
    rem[t[i]-'0']--;
  }

  ll all=(9*k-8)*(9*k-9);
  ll win=0;
  range(i,1,10){
    range(j,1,10){
      s[4]=i+'0';
      t[4]=j+'0';
      if(battle(s,t)){
        if(i==j) win+=rem[i]*(rem[j]-1);
        else win+=rem[i]*rem[j];
      }
    }
  }
  cout<<fixed<<setprecision(10);
  cout<<(double)win/(double)all<<endl;
}
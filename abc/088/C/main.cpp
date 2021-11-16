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

int main() {
  int n=3;
  int c[3][3];
  range(i,0,n) range(j,0,n) {
    cin>>c[i][j];
  }

  bool ans=false;
  range(i1,0,101){
    if(i1>c[0][0]||i1>c[0][1]||i1>c[0][2]) break;
    range(i2,0,101){
      if(i2>c[1][0]||i2>c[1][1]||i2>c[1][2]) break;
      range(i3,0,101){
        if(i3>c[2][0]||i3>c[2][1]||i3>c[2][2]) break;
        range(j1,0,101){
          if(i1+j1>c[0][0]||i2+j1>c[1][0]||i3+j1>c[2][0]) break;
          if(i1+j1!=c[0][0]||i2+j1!=c[1][0]||i3+j1!=c[2][0]) continue;
          range(j2,0,101){
            if(i1+j2>c[0][1]||i2+j2>c[1][1]||i3+j2>c[2][1]) break;
            if(i1+j2!=c[0][1]||i2+j2!=c[1][1]||i3+j2!=c[2][1]) continue;
            range(j3,0,101){
              if(i1+j3>c[0][2]||i2+j3>c[1][2]||i3+j3>c[2][2]) break;
              if(i1+j3!=c[0][2]||i2+j3!=c[1][2]||i3+j3!=c[2][2]) continue;

              ans=true;
              goto END;
            }
          }
        }
      }
    }
  } 
END:
  cout<<(ans?"Yes":"No")<<endl;
}
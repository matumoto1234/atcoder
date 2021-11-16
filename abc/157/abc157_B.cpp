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

int a[3][3];
bool hit[3][3]={0};
void mark(int b){
  range(i,0,3) range(j,0,3){
    if(a[i][j]==b) hit[i][j]=true;
  }
}

bool check(){
  range(i,0,3){
    int sum=0;
    range(j,0,3){
      if(hit[i][j]) sum++;
    }
    if(sum>=3) return true;
  }

  range(j,0,3){
    int sum=0;
    range(i,0,3){
      if(hit[i][j]) sum++;
    }
    if(sum>=3) return true;
  }

  int sum=0;
  range(i,0,3){
    if(hit[i][i]) sum++;
  }
  if(sum>=3) return true;

  sum=0;
  range(i,0,3){
    if(hit[i][3-i-1]) sum++;
  }
  if(sum>=3) return true;

  return false;
}

int main() {
  range(i,0,3) range(j,0,3){
    cin>>a[i][j];
  }

  int n;
  cin>>n;
  range(i,0,n){
    int b;
    cin>>b;
    mark(b);
  }
  
  cout<<(check()?"Yes":"No")<<endl;
}
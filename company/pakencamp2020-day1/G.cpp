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

struct query{
  int l,r,x;
  query(){}
  query(int l,int r,int x):l(l),r(r),x(x){}
};

int n,m;
vector<query> qs;
bool solve(vector<bool> &a){
  range(i,0,m){
    int cnt=0;
    range(j,qs[i].l,qs[i].r){
      if(a[j]) cnt++;
    }
    if(cnt!=qs[i].x) return false;
  }
  return true;
}

int main() {
  cin>>n>>m;

  range(i,0,m){
    int l_,r_,x_;
    cin>>l_>>r_>>x_;
    l_--;
    qs.emplace_back(l_,r_,x_);
  }

  int ans=-1;
  range(i,0,1<<n){
    int num=0;
    vector<bool> a(n,false);
    range(j,0,n){
      if((i>>j)&1){
        a[j]=true;
        num++;
      }
    }
    if(solve(a)) chmax(ans,num);
  }
  cout<<ans<<endl;
}
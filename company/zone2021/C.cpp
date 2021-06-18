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
constexpr int dy[] = {0,-1,1,0,-1,1,-1,1};
constexpr int dx[] = {-1,0,0,1,-1,-1,1,1};
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = (int)1e9 + 7;
constexpr char newl = '\n';

struct status{
  int a,b,c,d,e;
  int idx;

};

bool cmp_a(const status &l,const status &r){ return l.a<r.a; }
bool cmp_b(const status &l,const status &r){ return l.b<r.b; }
bool cmp_c(const status &l,const status &r){ return l.c<r.c; }
bool cmp_d(const status &l,const status &r){ return l.d<r.d; }
bool cmp_e(const status &l,const status &r){ return l.e<r.e; }

status res_max(status x, status y){
  status res;
  res.a=max(x.a,y.a);
  res.b=max(x.b,y.b);
  res.c=max(x.c,y.c);
  res.d=max(x.d,y.d);
  res.e=max(x.e,y.e);
  return res;
}

int main() {
  int n;
  cin>>n;

  vector<status> vs(n);
  range(i,0,n){
    cin>>vs[i].a>>vs[i].b>>vs[i].c>>vs[i].d>>vs[i].e;
    vs[i].idx=i;
  }

  vector<vector<status>> sorted(5,vs);
  sort(sorted[0].rbegin(),sorted[0].rend(),cmp_a);
  sort(sorted[1].rbegin(),sorted[1].rend(),cmp_b);
  sort(sorted[2].rbegin(),sorted[2].rend(),cmp_c);
  sort(sorted[3].rbegin(),sorted[3].rend(),cmp_d);
  sort(sorted[4].rbegin(),sorted[4].rend(),cmp_e);

  int ans=0;
  range(i,0,n){
    range(j,i+1,n){

      status ma=res_max(vs[i],vs[j]);
      
      range(k,0,5){
        range(l,0,3){
          if(sorted[k][l].idx==i || sorted[k][l].idx==j) continue;
          status temp=res_max(ma,sorted[k][l]);

          chmax(ans,min({temp.a,temp.b,temp.c,temp.d,temp.e}));
        }
      }
    }
  }
  cout<<ans<<endl;
}
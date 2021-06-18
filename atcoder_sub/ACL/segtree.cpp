#include <bits/stdc++.h>
#include <atcoder/segtree.hpp>
using namespace atcoder;
using namespace std;

#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
using ll = long long;
using lP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF = INT64_MAX / 2LL;
const int inf = INT32_MAX / 2;

int op(int a,int b){
  return max(a,b);
}

int e(){
  return -inf;
}

int target;

bool f(int x){
  return target>x;
}

int main() {
  int n,q;
  cin>>n>>q;
  vector<int> a(n);
  range(i,0,n){
    cin>>a[i];
  }

  segtree<int,op,e> st(a);
  range(i,0,q){
    int t,x,y;
    cin>>t>>x>>y;
    switch(t){
    case 1:
      x--;
      st.set(x,y);
      break;
    case 2:
      x--;
      cout<<st.prod(x,y)<<endl;
      break;
    case 3:
      target=y;
      x--;
      cout<<st.max_right<f>(x)+1<<endl;
      break;
    }
  }
}
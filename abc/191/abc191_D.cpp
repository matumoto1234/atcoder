#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
using ll = long long;
using LP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF = INT64_MAX / 2LL;
const int inf = INT32_MAX / 2;

using cint = boost::multiprecision::cpp_int;

int main() {
  long double X,Y,R;
  cin>>X>>Y>>R;
  X*=10000;
  Y*=10000;
  R*=10000;
  cint x=(ll)X;
  cint y=(ll)Y;
  cint r=(ll)R;

  for(cint i=-r;i<=r;i+=10000){
    
  }
}
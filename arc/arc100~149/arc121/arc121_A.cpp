#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define range(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1 )
#define rrange(i, l, r) for ( int i = (int)(r)-1; i >= (int)(l); (i) -= 1 )
#define debug(...) debug_func(0, #__VA_ARGS__, __VA_ARGS__)
template <typename T> void debug_func(int cnt, T name) { cerr << endl; }
template <typename T1,typename T2, typename... T3> void debug_func(int cnt, const T1 &name,const T2 &a, const T3&... b) { cerr << name[cnt] << ":" << a << " "; debug_func(cnt + 2, name, b...); }
template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << p.first << ' ' << p.second; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { for ( pair<T1, T2> x : v ) { os << x << "\n"; } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { if(!v.empty()) { os << v.front(); v.pop(); } while (!v.empty()) { os << " " << v.front(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { if(!v.empty()) { os << v.top(); v.pop(); } while (!v.empty()) { os << " " << v.top(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
using ull = unsigned long long;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr int dy[] = { 0, -1, 1, 0, -1, 1, -1, 1 };
constexpr int dx[] = { -1, 0, 0, 1, -1, -1, 1, 1 };
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = (int)1e9 + 7;
constexpr char newl = '\n';
// clang-format on

ll dist(P p1,P p2){
  return max(abs(p1.first-p2.first), abs(p1.second-p2.second));
}

int main() {
  int n;
  cin >> n;
  vector<pair<P,int>> xy(n),yx(n);
  range(i,0,n){
    auto &[x,y]=xy[i].first;
    cin>>x>>y;
    yx[i].first.first=y;
    yx[i].first.second=x;
    xy[i].second=i;
    yx[i].second=i;
  }
  sort(xy.begin(),xy.end());
  sort(yx.begin(),yx.end());
  
  map<P,int> mp;
  chmax(mp[P(xy[0].second,xy[n-1].second)],dist(xy[0].first,xy[n-1].first));
  chmax(mp[P(xy[0].second,xy[n-2].second)],dist(xy[0].first,xy[n-2].first));
  chmax(mp[P(xy[1].second,xy[n-1].second)],dist(xy[1].first,xy[n-1].first));

  chmax(mp[P(yx[0].second,yx[n-1].second)],dist(yx[0].first,yx[n-1].first));
  chmax(mp[P(yx[0].second,yx[n-2].second)],dist(yx[0].first,yx[n-2].first));
  chmax(mp[P(yx[1].second,yx[n-1].second)],dist(yx[1].first,yx[n-1].first));

  vector<ll> ds;
  for(auto [idx,dis]:mp){
    ds.emplace_back(dis);
  }
  sort(ds.rbegin(),ds.rend());
  cout<<ds[1]<<endl;
}
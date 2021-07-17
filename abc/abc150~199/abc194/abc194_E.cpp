#include <bits/stdc++.h>
using namespace std;


// {{{

// clang-format off
#define _over_load(_1,_2,_3,_4,NAME,...) NAME
#define range(...) _over_load(__VA_ARGS__, range4, range3, range2)(__VA_ARGS__)
#define range2(i, r) for ( int i = 0; i < (int)(r); (i) += 1)
#define range3(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1)
#define range4(i, l, r, inc) for ( int i = (int)(l); i < (int)(r); (i) += (inc))
#define rrange(...) _over_load(__VA_ARGS__, rrange4, rrange3, rrange2)(__VA_ARGS__)
#define rrange2(i, r) for ( int i = (int)(r) - 1; i >= 0; (i) -= 1)
#define rrange3(i, l, r) for ( int i = (int)(r) - 1; i >= (int)(l); (i) -= 1)
#define rrange4(i, l, r, inc) for ( int i = (int)(r) - 1; i >= (int)(l); (i) -= inc)
#define debug(...) debug_func(#__VA_ARGS__, __VA_ARGS__)
template <typename T, typename... T2> void debug_func(string_view name, const T &a, T2 &&...rest) { stack<char> bs; string_view lbs = "({[<"; string_view rbs = ")}]>"; int end = name.size(); for ( int i = 0; i < (int)name.size(); i++ ) { if ( lbs.find(name[i]) != string::npos ) { bs.push(name[i]); } if ( rbs.find(name[i]) != string::npos ) { if ( !bs.empty() ) { bs.pop(); } } if ( name[i] == ',' && bs.empty() ) { end = i; break; } } cerr << name.substr(0, end) << ":" << a; if constexpr ( sizeof...(rest) == 0 ) { cerr << endl; } else { cerr << ' '; debug_func(name.substr(name.find_first_not_of(' ', end + 1)), forward<T2>(rest)...); } }
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
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in : v) is >> in; return is; }
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
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

// }}}


template <typename T = long long>
struct mexset {
  set<pair<T, T>> s;

  T inf() { return numeric_limits<T>::max() / 2; }

  mexset() {
    s.emplace(inf(), inf());
    s.emplace(-inf(), -inf());
  }

  bool contains(T x) const {
    auto [lower, upper] = *prev(s.lower_bound(make_pair(x + 1, x + 1)));
    return lower <= x && x <= upper;
  }

  bool insert(T x) {
    if ( contains(x) ) return false;
    auto nit = s.lower_bound(make_pair(x + 1, x + 1));
    auto it = prev(nit);
    auto [l, u] = *it;
    auto [nl, nu] = *nit;
    if ( u == x - 1 ) {
      if ( nl == x + 1 ) {
        s.erase(it);
        s.erase(nit);
        s.emplace(l, nu);
      } else {
        s.erase(it);
        s.emplace(l, x);
      }
    } else {
      if ( nl == x + 1 ) {
        s.erase(nit);
        s.emplace(x, nu);
      } else {
        s.emplace(x, x);
      }
    }
    return true;
  }

  bool erase(T x) {
    if ( !contains(x) ) return false;
    auto it = prev(s.lower_bound(make_pair(x + 1, x + 1)));
    auto [l, u] = *it;
    s.erase(it);
    if ( x != l ) s.emplace(l, x - 1);
    if ( x != u ) s.emplace(x + 1, u);
    return true;
  }

  T mex(T x = 0) const {
    auto [l, u] = *prev(s.lower_bound(make_pair(x + 1, x + 1)));
    if ( l <= x && x <= u ) {
      return u + 1;
    } else {
      return x;
    }
  }
};


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n,m;
  cin>>n>>m;
  vector<int> as(n);
  cin>>as;

  mexset<int> s;
  vector<int> cnt(n,0);

  range(i,0,m){
    int a=as[i];
    s.insert(a);
    cnt[a]++;
  }
  int ans=s.mex();

  range(i,m,n){
    int pre=as[i-m];
    int a=as[i];

    cnt[pre]--;
    if(cnt[pre]==0) s.erase(as[i-m]);

    cnt[a]++;
    s.insert(as[i]);
    chmin(ans,s.mex());
  }
  cout<<ans<<endl;
}
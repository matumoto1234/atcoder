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


vector<ll> to_base(ll n,ll b){
  if ( n == 0 || b <= 1 ) return vector<ll>{ 0 };
  vector<ll> res;
  for ( ; n > 0; n /= b ) {
    res.emplace_back(n % b);
  }
  reverse(res.begin(), res.end());
  return res;
}

// from-ary n -> to-ary n
template <typename T>
vector<T> convert_base(vector<T> n, T from, T to) {
  auto to_base = [&](T n, T b) {
    if ( n == 0 || b <= 1 ) return vector<T>{ 0 };
    vector<T> res;
    for ( ; n > 0; n /= b ) {
      res.emplace_back(n % b);
    }
    reverse(res.begin(), res.end());
    return res;
  };

  auto to_decimal = [&](vector<T> n, T b) {
    T res = 0, x = 1;
    for ( int i = n.size() - 1; i >= 0; i--, x *= b ) {
      res += x * (n[i]);
    }
    return res;
  };

  T temp = to_decimal(n, from);
  return to_base(temp, to);
}

bool is_pow26(ll n){
  ll a=1;
  while(a<=n){
    if(a==n) return true;
    a*=26;
  }
  return false;
}

vector<ll> carry_fix(vector<ll> vs){
  vs.back()--;
  rrange(i,vs.size()){
    if(vs[i]<0 && i>0){
      vs[i-1]--;
      vs[i]+=26;
    }
  }
  debug(vs);
  range(i,vs.size()){
  }
  if(vs[0]<=0){
    vs.erase(vs.begin());
  }
  return vs;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin>>n;
  string ans = "";
  while (n) {
    n--;
    ans += (char)('a' + (n % 26));
    n /= 26;
  }

  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}
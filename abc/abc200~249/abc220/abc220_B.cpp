#include <bits/stdc++.h>
using namespace std;


// {{{

// clang-format off
#define len(x) (static_cast<int>((x).size()))
#define _over_load(_1,_2,_3,_4,NAME,...) NAME
#define range(...) _over_load(__VA_ARGS__, range4, range3, range2)(__VA_ARGS__)
#define range2(i, r) for ( int i = 0; i < static_cast<int>(r); (i) += 1)
#define range3(i, l, r) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += 1)
#define range4(i, l, r, step) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += (step))
#define rrange(...) _over_load(__VA_ARGS__, rrange4, rrange3, rrange2)(__VA_ARGS__)
#define rrange2(i, r) for ( int i = static_cast<int>(r) - 1; i >= 0; (i) -= 1)
#define rrange3(i, l, r) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= 1)
#define rrange4(i, l, r, step) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= (step))
#define whole(f, x, ...) ([&](decltype((x)) container) { return (f)( begin(container), end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)
#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)
template <typename T, typename... T2> void debug_function(string_view name, const T &a, T2 &&...rest) {
  stack<char> bs;
  string_view lbs = "({[<", rbs = ")}]>";
  int end = name.size();
  for ( int i = 0; i < len(name); i++ ) {
    if ( lbs.find(name[i]) != string::npos ) bs.push(name[i]);
    if ( rbs.find(name[i]) != string::npos and !bs.empty() ) bs.pop();
    if ( name[i] == ',' and bs.empty() ) {
      end = i;
      break;
    }
  }
  cerr << name.substr(0, end) << ":" << a;
  if constexpr ( sizeof...(rest) == 0 ) {
    cerr << '\n';
  } else {
    cerr << ' ';
    debug_function(name.substr(name.find_first_not_of(' ', end + 1)), forward<T2>(rest)...);
  }
}
template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b and (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b and (a = b, true); }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << p.first << ' ' << p.second; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { for ( pair<T1, T2> x : v ) { os << "(" << x.first <<", " << x.second << ")" << (v.rbegin()->first == x.first ? "" : ", "); } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { if(!v.empty()) { os << v.front(); v.pop(); } while (!v.empty()) { os << " " << v.front(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { if(!v.empty()) { os << v.top(); v.pop(); } while (!v.empty()) { os << " " << v.top(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { range(i, len(v)) { cout << v[i] << (i == len(v) ? "" : " "); } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { range(i, len(v)) { cout << v[i] << (i == len(v) ? "" : " "); } return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in : v) is >> in; return is; }
struct IoSetup { IoSetup(int x = 15) { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(x); cerr << fixed << setprecision(x); } } iosetup;
using ull = unsigned long long;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr int dy[] = { 0, -1, 1, 0, -1, 1, -1, 1 };
constexpr int dx[] = { -1, 0, 0, 1, -1, -1, 1, 1 };
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = static_cast<int>(1e9) + 7;
constexpr char newl = '\n';
// clang-format on

// }}}


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

vector<int> input(){
  string s;
  cin>>s;
  vector<int> vs(s.size());
  range(i,len(s)){
    vs[i]=s[i]-'0';
  }
  return vs;
}


int main() {
  int k;
  cin>>k;
  vector<int> a=input(),b=input();

  vector<int> na=convert_base(a,k,10);
  vector<int> nb=convert_base(b,k,10);

  auto to_decimal = [&](vector<int> n, ll b) {
    ll res = 0, x = 1;
    for ( int i = n.size() - 1; i >= 0; i--, x *= b ) {
      res += x * (n[i]);
    }
    return res;
  };

  ll v1=to_decimal(na,10);
  ll v2=to_decimal(nb,10);

  cout<<v1*v2<<endl;
}
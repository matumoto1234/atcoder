#include <bits/stdc++.h>
using namespace std;

// {{{

// clang-format off
#define rep(i, n) for (int i = 0; i < (int)(n); i += 1)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i -= 1)
#define range(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1 )
#define rrange(i, l, r) for ( int i = (int)(r)-1; i >= (int)(l); (i) -= 1 )
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
template <typename T> void operator+=(vector<T> &vs, T x) { for ( T &v : vs ) v += x; }
template <typename T> void operator-=(vector<T> &vs, T x) { for ( T &v : vs ) v -= x; }
template <typename T> void operator*=(vector<T> &vs, T x) { for ( T &v : vs ) v *= x; }
template <typename T> void operator/=(vector<T> &vs, T x) { for ( T &v : vs ) v /= x; }
template <typename T> void operator%=(vector<T> &vs, T x) { for ( T &v : vs ) v %= x; }
template <typename T> vector<T> operator+(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v += x; return res; }
template <typename T> vector<T> operator-(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v -= x; return res; }
template <typename T> vector<T> operator*(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v *= x; return res; }
template <typename T> vector<T> operator/(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v /= x; return res; }
template <typename T> vector<T> operator%(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v %= x; return res; }
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

template <typename T>
vector<T> to_base(T n, T b) {
  if ( n == 0 || b <= 1 ) return vector<T>{ 0 };
  vector<T> res;
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

class i128 {
private:
  __int128_t v;

public:

	i128() {}
	i128(const long long &a) { v = a; }
	i128(const string &s) { parse(s); }

	long long long_val() { return (long long)v; }
  __int128_t val() { return v; }
  __int128_t abs() { return v < 0 ? -v : v; }

	void set(const long long &a) { v = a; }

  void parse(const string &s) {
		v = 0;
    for ( char c : s ) {
      if ( isdigit(c) ) v = v * 10 + (c - '0');
    }
    if ( s[0] == '-' ) v *= -1;
  }

  // clang-format off
  i128 operator+(const i128 &a) { return v + a.v; }
  i128 operator-(const i128 &a) { return v - a.v; }
  i128 operator*(const i128 &a) { return v * a.v; }
  i128 operator/(const i128 &a) { return v / a.v; }
  i128 operator%(const i128 &a) { return v % a.v; }
  void operator+=(const i128 &a) { v += a.v; }
  void operator-=(const i128 &a) { v -= a.v; }
  void operator*=(const i128 &a) { v *= a.v; }
  void operator/=(const i128 &a) { v /= a.v; }
  void operator%=(const i128 &a) { v %= a.v; }

  template <typename T> i128 operator+(const T &a) { i128 res = *this; res.v += a; return res; }
  template <typename T> i128 operator-(const T &a) { i128 res = *this; res.v -= a; return res; }
  template <typename T> i128 operator*(const T &a) { i128 res = *this; res.v *= a; return res; }
  template <typename T> i128 operator/(const T &a) { i128 res = *this; res.v /= a; return res; }
  template <typename T> i128 operator%(const T &a) { i128 res = *this; res.v %= a; return res; }
  template <typename T> void operator+=(const T &a) { v += a; }
  template <typename T> void operator-=(const T &a) { v -= a; }
  template <typename T> void operator*=(const T &a) { v *= a; }
  template <typename T> void operator/=(const T &a) { v /= a; }
  template <typename T> void operator%=(const T &a) { v %= a; }

  template <typename T> i128 operator-() { i128 res = *this; res.v *= -1; return res; }

  bool operator<(const i128 &a) { return v < a.v; }
  bool operator>(const i128 &a) { return v > a.v; }
  bool operator<=(const i128 &a) { return v <= a.v; }
  bool operator>=(const i128 &a) { return v >= a.v; }
  bool operator==(const i128 &a) { return v == a.v; }
  bool operator!=(const i128 &a) { return v != a.v; }

  template <typename T> bool operator<(const T &a) { return v < a; }
  template <typename T> bool operator>(const T &a) { return v > a; }
  template <typename T> bool operator<=(const T &a) { return v <= a; }
  template <typename T> bool operator>=(const T &a) { return v >= a; }
  template <typename T> bool operator==(const T &a) { return v == a; }
  template <typename T> bool operator!=(const T &a) { return v != a; }
  // clang-format on



  friend istream &operator>>(istream &is, i128 &v) {
    string s;
    is >> s;
    v.parse(s);
    return is;
  }

  friend ostream &operator<<(ostream &os, const i128 &v) {
    if ( !ostream::sentry(os) ) return os;
    char buf[64];
    char *d = end(buf);
    __uint128_t tmp = (v.v < 0 ? -v.v : v.v);

    do {
      d--;
      *d = char(tmp % 10 + '0');
      tmp /= 10;
    } while ( tmp );
    if ( v.v < 0 ) {
      d--;
      *d = '-';
    }
    int len = end(buf) - d;
    if ( os.rdbuf()->sputn(d, len) != len ) { os.setstate(ios_base::badbit); }
    return os;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  i128 n;
  ll k;
  cin >> n >> k;

  auto vs = to_base<i128>(n, 10);
  rep(i, k) {
    vs = convert_base<i128>(vs, 8, 9);
    for ( auto &v : vs ) {
      if ( v == 8 ) v = 5;
    }
  }

  for ( auto v : vs ) cout << v;
  cout << endl;
}
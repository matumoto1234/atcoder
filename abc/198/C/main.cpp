#include <bits/stdc++.h>
using namespace std;

// {{{ Templates

// clang-format off

// Macros
#define over_load_(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) over_load_(__VA_ARGS__, rep4, rep3, rep2)(__VA_ARGS__)
#define rep2(i, r) for ( int i = 0; i < static_cast<int>(r); (i) += 1)
#define rep3(i, l, r) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += 1)
#define rep4(i, l, r, stride) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += (stride))
#define rrep(...) over_load_(__VA_ARGS__, rrep4, rrep3, rrep2)(__VA_ARGS__)
#define rrep2(i, r) for ( int i = static_cast<int>(r) - 1; i >= 0; (i) -= 1)
#define rrep3(i, l, r) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= 1)
#define rrep4(i, l, r, stride) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= (stride))
#define len(x) (static_cast<int>((x).size()))
#define whole(f, x, ...) ([&](decltype((x)) container) { return (f)( begin(container), end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)
#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)

// Operators
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { bool is_first = true; for (auto x: v) { os << (is_first ? "" : " ") << x; is_first = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { bool is_first = true; while (!v.empty()) { os << (is_first?"":" ")<<v.front(); v.pop(); is_first = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { bool is_first = true; while (!v.empty()) { os << (is_first?"":" ") << v.top(); v.pop(); is_first=false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { rep (i, len(v)) os << v[i] << (i == len(v) - 1 ? "" : " "); return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &v) { for (const auto &vec: v) { os << vec << '\n'; } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { rep (i, len(v)) os << v[i] << (i == len(v) - 1 ? "" : " "); return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { bool is_first = true; for (T x: v) { os << (is_first ? "" : " ") << x; is_first = false; } return os; }
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in: v) { is >> in; } return is; }

// For debug macro
int find_comma_not_bracketed(string_view s){ stack<char> bs; string lbs = "({[", rbs = ")}]"; for (size_t i = 0; i < s.size(); i++) { if (lbs.find(s[i]) != string::npos) bs.push(s[i]); if (rbs.find(s[i]) != string::npos and !bs.empty()) bs.pop(); if (s[i] == ',' and bs.empty()) return i; } return s.size(); }
template <typename T, typename... Ts> void debug_function(string_view name, const T &a, Ts &&...rest) { int end = find_comma_not_bracketed(name); cerr << name.substr(0, end) << ":" << a; if constexpr (sizeof...(rest) == 0) { cerr << '\n'; } else { cerr << ' '; debug_function(name.substr(name.find_first_not_of(' ', end + 1)), forward<Ts>(rest)...); } }

// Functions
template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b and (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b and (a = b, true); }

// Structs
struct IoSetup { IoSetup(int x = 15) { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(x); cerr << fixed << setprecision(x); } } iosetup;

// Type aliases
using ull = unsigned long long;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

// Literals
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr int dy[] = { 0, -1, 1, 0, -1, 1, -1, 1 };
constexpr int dx[] = { -1, 0, 0, 1, -1, -1, 1, 1 };
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = static_cast<int>(1e9) + 7;
constexpr char newl = '\n';

// clang-format on

// }}} Templates


namespace tools {
  using namespace std;
}

#include <cassert>
#include <iostream>
#include <string>

namespace tools {
  namespace int128 {
    __int128_t parse(const string &s) {
      __int128_t res = 0;
      for (char c: s) {
        if (isdigit(c)) res = res * 10 + (c - '0');
      }
      if (s[0] == '-') res *= -1;
      return res;
    }

    istream &operator>>(istream &is, __int128_t &v) {
      string s;
      is >> s;
      v = parse(s);
      return is;
    }

    ostream &operator<<(ostream &os, const __int128_t &v) {
      if (!ostream::sentry(os)) return os;
      char buf[64];
      char *d = end(buf);
      __uint128_t tmp = (v < 0 ? -v : v);

      do {
        d--;
        *d = char(tmp % 10 + '0');
        tmp /= 10;
      } while (tmp);
      if (v < 0) {
        d--;
        *d = '-';
      }
      int len = end(buf) - d;
      if (os.rdbuf()->sputn(d, len) != len) { os.setstate(ios_base::badbit); }
      return os;
    }

    __int128_t gcd(__int128_t a, __int128_t b) {
      __int128_t tmp;
      while (b > 0) {
        tmp = a;
        a = b;
        b = tmp % b;
      }
      return a;
    }

    __int128_t lcm(__int128_t a, __int128_t b) { return a * b / gcd(a, b); }


    namespace template_internal_math {

      __int128_t extgcd(__int128_t a, __int128_t b, __int128_t &x, __int128_t &y) {
        if (b == 0) {
          x = 1;
          y = 0;
          return a;
        }
        __int128_t d = extgcd(b, a % b, y, x);
        y = y - (a / b) * x;
        return d;
      }

    } // namespace template_internal_math

    __int128_t power(__int128_t a, __int128_t e, __int128_t p = -1) {
      assert(p != 0);
      assert(p >= -1);

      if (e < 0) {
        assert(p != -1 and gcd(a, p) == 1);
        __int128_t x, y;
        template_internal_math::extgcd(a, p, x, y);
        a = (x % p + p) % p;
        e *= -1;
      }

      __int128_t res = 1;
      while (e > 0) {
        if (e & 1) {
          res *= a;
          if (p != -1) res %= p;
        }
        a *= a;
        if (p != -1) a %= p;
        e >>= 1;
      }
      return res;
    }
  } // namespace int128
  using namespace int128;
  using i128 = __int128_t;
} // namespace tools
using namespace tools;

bool is_square(i128 x) {
  for (i128 i = 1; i * i <= x; i++) {
    if (i * i == x) return true;
  }
  return false;
}

int main() {
  i128 r, x, y;
  cin >> r >> x >> y;

  i128 R = r * r;
  i128 D = x * x + y * y;

  if (D < R) {
    cout << 2 << endl;
    return 0;
  }
  if (D == R) {
    cout << 1 << endl;
    return 0;
  }

  i128 A = (D + (R - 1)) / R;

  i128 a = sqrtf128(A);

  if (is_square(A)) {
    cout << a << endl;
  } else {
    cout << a + 1 << endl;
  }
}
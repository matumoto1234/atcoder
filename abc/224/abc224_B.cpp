#include <bits/stdc++.h>
using namespace std;

// {{{

// clang-format off
#define _over_load(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) _over_load(__VA_ARGS__, rep4, rep3, rep2)(__VA_ARGS__)
#define rep2(i, r) for ( int i = 0; i < static_cast<int>(r); (i) += 1)
#define rep3(i, l, r) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += 1)
#define rep4(i, l, r, stride) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += (stride))
#define rrep(...) _over_load(__VA_ARGS__, rrep4, rrep3, rrep2)(__VA_ARGS__)
#define rrep2(i, r) for ( int i = static_cast<int>(r) - 1; i >= 0; (i) -= 1)
#define rrep3(i, l, r) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= 1)
#define rrep4(i, l, r, stride) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= (stride))
#define len(x) (static_cast<int>((x).size()))
#define whole(f, x, ...) ([&](decltype((x)) container) { return (f)( begin(container), end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)
#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)
// clang-format on

using ull = unsigned long long;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;

template <typename T, typename... T2>
void debug_function(string_view name, const T &a, T2 &&...rest) {
  stack<char> bs;
  string_view lbs = "({[", rbs = ")}]";
  int end = name.size();
  for (int i = 0; i < len(name); i++) {
    if (lbs.find(name[i]) != string::npos) bs.push(name[i]);
    if (rbs.find(name[i]) != string::npos and !bs.empty()) bs.pop();
    if (name[i] == ',' and bs.empty()) {
      end = i;
      break;
    }
  }
  cerr << name.substr(0, end) << ":" << a;
  if constexpr (sizeof...(rest) == 0) {
    cerr << '\n';
  } else {
    cerr << ' ';
    debug_function(name.substr(name.find_first_not_of(' ', end + 1)), forward<T2>(rest)...);
  }
}

namespace template_helper {
  template <typename T>
  class has_iterator {
    template <typename Container>
    static true_type test(typename Container::iterator *);
    template <typename Container>
    static false_type test(...);

  public:
    static const bool value = decltype(test<T>(0))::value;
  };

  template <typename Container, typename T>
  class has_find {
    template <typename InnerContainer, int dummy = (static_cast<typename enable_if<has_iterator<InnerContainer>::value, InnerContainer>::type::iterator (InnerContainer::*)(const T &)>(&InnerContainer::find), 0)>
    static true_type check(InnerContainer *);
    static false_type check(...);
    static Container *container;

  public:
    static const bool value = decltype(check(container))::value;
  };
} // namespace template_helper

template <typename Container, typename T>
bool contains(const Container &container, const T &x) {
  if constexpr (template_helper::has_find<Container, T>::value) {
    return container.find(x) != end(container);
  } else {
    return find(begin(container), end(container), x) != end(container);
  }
}

template <typename T>
vector<T> make_vector(size_t a, T b) {
  return vector<T>(a, b);
}

template <typename... Ts>
auto make_vector(size_t a, Ts... ts) {
  return vector<decltype(make_vector(ts...))>(a, make_vector(ts...));
}

template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
  return a < b and (a = b, true);
}

template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
  return a > b and (a = b, true);
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << p.first << ' ' << p.second;
  return os;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const map<T1, T2> &v) {
  for (pair<T1, T2> x: v) {
    os << "(" << x.first << ", " << x.second << ")" << (v.rbegin()->first == x.first ? "" : ", ");
  }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, queue<T> v) {
  if (!v.empty()) {
    os << v.front();
    v.pop();
  }
  while (!v.empty()) {
    os << " " << v.front();
    v.pop();
  }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, stack<T> v) {
  if (!v.empty()) {
    os << v.top();
    v.pop();
  }
  while (!v.empty()) {
    os << " " << v.top();
    v.pop();
  }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  rep (i, len(v)) { cout << v[i] << (i == len(v) - 1 ? "" : " "); }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
  for (const auto &vec: v) {
    cout << vec << '\n';
  }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const deque<T> &v) {
  rep (i, len(v)) { cout << v[i] << (i == len(v) - 1 ? "" : " "); }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  bool is_f = true;
  for (T x: v) {
    os << (is_f ? "" : " ") << x;
    is_f = false;
  }
  return os;
}

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  is >> p.first >> p.second;
  return is;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &in: v)
    is >> in;
  return is;
}

struct IoSetup {
  IoSetup(int x = 15) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(x);
    cerr << fixed << setprecision(x);
  }
} iosetup;

struct get_slice {
  static constexpr int init = INT32_MAX;
  get_slice() {}

  template <typename T>
  vector<T> operator()(const vector<T> &v, int r) {
    if (r < 0) r += v.size();
    vector<T> res;
    res.reserve(r);
    for (int i = 0; i < r; i++) {
      res.emplace_back(v[i]);
    }
    return res;
  }

  template <typename T>
  vector<T> operator()(const vector<T> &v, int l, int r, int stride = init) {
    assert(stride != 0);
    if (stride == init) stride = 1;
    vector<T> res;
    int start = (stride > 0 ? l : r - 1);
    for (int i = start; (stride > 0 ? i < r : i >= l); i += stride) {
      if (i >= 0) {
        res.emplace_back(v[i]);
      } else {
        res.emplace_back(v.end()[i]);
      }
    }
    return res;
  }

  string operator()(const string &s, int r) {
    if (r < 0) r += s.size();
    string res;
    res.reserve(r);
    for (int i = 0; i < r; i++) {
      res.push_back(s[i]);
    }
    return res;
  }

  string operator()(const string &s, int l, int r, int stride = init) {
    assert(stride != 0);
    if (stride == init) stride = 1;
    string res;
    res.reserve(abs(r - l) / stride);
    int start = (stride > 0 ? l : r - 1);
    for (int i = start; (stride > 0 ? i < r : i >= l); i += stride) {
      if (i >= 0) {
        res.push_back(s[i]);
      } else {
        res.push_back(s.end()[i]);
      }
    }
    return res;
  }
} sl;

template <typename T>
vector<int> sorted_index(const vector<T> &vs) {
  vector<int> res(vs.size());
  iota(res.begin(), res.end(), 0);
  stable_sort(res.begin(), res.end(), [&](int i, int j) {
    return vs[i] < vs[j];
  });
  return res;
}

vector<int> sorted_index(const string &s) {
  vector<int> res(s.size());
  iota(res.begin(), res.end(), 0);
  stable_sort(res.begin(), res.end(), [&](int i, int j) {
    return s[i] < s[j];
  });
  return res;
}

template <typename T1, typename T2>
vector<pair<T1, T2>> to_pair_vector(const vector<T1> &a, const vector<T2> &b) {
  vector<pair<T1, T2>> res;
  int mi = min(a.size(), b.size());
  int ma = max(a.size(), b.size());
  res.reserve(ma);
  for (int i = 0; i < mi; i++) {
    res.emplace_back(a[i], b[i]);
  }

  for (int i = mi; i < ma; i++) {
    if (a.size() > b.size()) {
      res.emplace_back(a[i]);
    } else {
      res.emplace_back(b[i]);
    }
  }
  return res;
}

vector<char> to_vector(const string &s) {
  vector<char> res;
  res.reserve(s.size());
  for (const char &c: s) {
    res.emplace_back(c);
  }
  return res;
}

template <typename T>
string to_string(const vector<T> &vs, const string &sep = " ") {
  stringstream ss;
  for (int i = 0; i < (int)vs.size(); i++) {
    if (i) ss << sep;
    ss << vs[i];
  }
  return ss.str();
}

template <typename T, size_t length>
array<T, length> to_array(const vector<T> &vs) {
  array<T, length> res;
  for (int i = 0; i < (int)length; i++) {
    res[i] = vs[i];
  }
  return res;
}

template <typename T>
map<T, int> counter(const vector<T> &vs) {
  map<T, int> res;
  for (const T &v: vs) {
    res[v]++;
  }
  return res;
}

map<char, int> counter(const string &s) {
  map<char, int> res;
  for (const char &v: s) {
    res[v]++;
  }
  return res;
}

string join(const vector<string> &strs, const string &sep) {
  string res = "";
  for (int i = 0; i < (int)strs.size(); i++) {
    if (i) res += sep;
    res += strs[i];
  }
  return res;
}

ll extgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = extgcd(b, a % b, y, x);
  y = y - (a / b) * x;
  return d;
}

ll power(ll a, ll e, ll p = -1) {
  assert(p != 0);
  assert(p >= -1);

  if (e < 0) {
    assert(p != -1 and gcd(a, p) == 1);
    ll x, y;
    extgcd(a, p, x, y);
    a = (x % p + p) % p;
    e *= -1;
  }

  ll res = 1;
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

int logarithm(ll base, ll n) {
  assert(base != 0);
  int cnt = 0;
  while (n % base == 0) {
    n /= base;
    cnt++;
  }
  return cnt;
}

ll ceil_div(ll n, ll d) {
  assert(d != 0);
  return n / d + (((n ^ d) >= 0) && (n % d));
}

ll floor_div(ll n, ll d) {
  assert(d != 0);
  return n / d - (((n ^ d) < 0) && (n % d));
}

template <typename T>
vector<T> reversed(const set<T> &s) {
  vector<T> res;
  res.reserve(s.size());
  for (const T &v: s) {
    res.emplace_back(v);
  }
  reverse(res.begin(), res.end());
  return res;
}

template <typename T1, typename T2>
vector<pair<T1, T2>> reversed(const map<T1, T2> &mp) {
  vector<pair<T1, T2>> vs;
  vs.reserve(mp.size());
  for (const auto &[key, val]: mp) {
    vs.emplace_back(key, val);
  }
  reverse(vs.begin(), vs.end());
  return vs;
}

template <typename T>
T reversed(T container) {
  reverse(begin(container), end(container));
  return container;
}

constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr int dy[] = { 0, -1, 1, 0, -1, 1, -1, 1 };
constexpr int dx[] = { -1, 0, 0, 1, -1, -1, 1, 1 };
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = static_cast<int>(1e9) + 7;
constexpr char newl = '\n';

// }}}

bool solve(int h, int w, vector<vector<int>> as) {
  rep (i, h)
    rep (j, w) {
      rep (k, i + 1, h)
        rep (l, j + 1, w) {
          if (as[i][j] + as[k][l] > as[k][j] + as[i][l]) return false;
        }
    }
  return true;
}

int main() {
  int h, w;
  cin >> h >> w;

  auto as = make_vector(h, w, 0);
  for (auto &A: as) {
    cin >> A;
  }

  cout << (solve(h, w, as) ? "Yes" : "No") << endl;
}

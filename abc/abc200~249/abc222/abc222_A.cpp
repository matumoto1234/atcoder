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
#define contains(container, x) (find(begin(container), end(container), x) != end(container))
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
  rep(i, len(v)) { cout << v[i] << (i == len(v) - 1 ? "" : " "); }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const deque<T> &v) {
  rep(i, len(v)) { cout << v[i] << (i == len(v) - 1 ? "" : " "); }
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

template <typename iter>
vector<int> sorted_index(const iter &first, const iter &last) {
  auto tmp = *first;
  vector<decltype(tmp)> a(first, last);
  vector<int> res(a.size());
  iota(res.begin(), res.end(), 0);
  stable_sort(res.begin(), res.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  return res;
}

template <typename T1, typename T2>
vector<pair<T1, T2>> aggregate(const vector<T1> &a, const vector<T2> &b) {
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

template <typename T>
map<T, int> counter(const vector<T> &vs) {
  map<T, int> res;
  for (T v: vs)
    res[v]++;
  return res;
}

template <typename T, size_t length>
array<T, length> to_array(const vector<T> &vs) {
  array<T, length> res;
  for (int i = 0; i < (int)length; i++) {
    res[i] = vs[i];
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

namespace template_internal_math {

  template <typename T>
  T extgcd(T a, T b, T &x, T &y) {
    if (b == 0) {
      x = 1;
      y = 0;
      return a;
    }
    T d = extgcd(b, a % b, y, x);
    y = y - (a / b) * x;
    return d;
  }

} // namespace template_internal_math

ll power(ll a, ll e, ll p = -1) {
  assert(p != 0);
  assert(p >= -1);

  if (e < 0) {
    assert(p != -1 and gcd(a, p) == 1);
    ll x, y;
    template_internal_math::extgcd(a, p, x, y);
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

constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr int dy[] = { 0, -1, 1, 0, -1, 1, -1, 1 };
constexpr int dx[] = { -1, 0, 0, 1, -1, -1, 1, 1 };
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = static_cast<int>(1e9) + 7;
constexpr char newl = '\n';

// }}}




int main() {
  string n;
  cin>>n;
  while(len(n)<4){
    n.insert(n.begin(),'0');
  }
  cout<<n<<endl;
}
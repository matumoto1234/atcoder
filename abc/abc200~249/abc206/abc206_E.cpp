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

struct prime_factor_table {
  vector<int> ps;
  prime_factor_table() {}

  void build(int N) {
    ps.assign(N + 1, 1);
    for ( long long i = 2; i <= N; i++ ) {
      if ( ps[i] != 1 ) continue;
      ps[i] = i;
      for ( long long j = i * i; j <= N; j += i ) {
        if ( ps[j] != 1 ) continue;
        ps[j] = i;
      }
    }
  }

  vector<int> factorize(int x) {
    vector<int> res;
    while ( ps[x] > 1 ) {
      res.emplace_back(ps[x]);
      x /= ps[x];
    }
    return res;
  }

  bool is_prime(int k) {
    if ( k <= 1 ) return false;
    return ps[k] == k;
  }

  int operator[](int i) { return ps[i]; }
};

template <typename T>
map<T, int> counter(const vector<T> &vs) {
  map<T, int> res;
  for ( T v : vs )
    res[v]++;
  return res;
}


vector<int> euler_phi_table(int n) {
  vector<int> euler(n + 1);
  for(int i = 0; i <= n; i++) {
    euler[i] = i;
  }
  for(int i = 2; i <= n; i++) {
    if(euler[i] == i) {
      for(int j = i; j <= n; j += i) {
        euler[j] = euler[j] / i * (i - 1);
      }
    }
  }
  return euler;
}

// 1からnまでの自然数iについてreuler[i]:=[i,n]の互いに素なものの個数
vector<int> reversed_section_euler_phi_table(int n) {
  constexpr int INF = INT32_MAX/2;
  vector<int> factors_count(n+1,0);
  vector<int> res(n+1,n);
  res[0]=0;

  for(long long i=2;i<=n;i++){
    if(factors_count[i]<0) continue;

    for(int j=i;j<=n;j+=i){
      if(factors_count[i]%2==0) res[j]+=n/i;
      else res[j]-=n/i;
    }
    for(int j=i;j<=n;j+=i) factors_count[j]++;
    for(long long j=i*i;j<=n;j+=i*i) factors_count[j]=-INF;
  }

  vector<int> euler = euler_phi_table(n);
  debug(euler);
  for(int i=1;i<=n;i++) res[i]-=euler[i];
  return res;
}

vector<int> naive_euler(int n){
  vector<int> res(n+1,0);
  res[1]=n;
  for(int i=2;i<=n;i++){
    for(int j=i;j<=n;j++){
      if(gcd(i,j)==1) res[i]++;
    }
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int l, r;
  cin >> l >> r;
  vector<int> cnt(r + 1, 0);
  auto euler1 = reversed_section_euler_phi_table(r);
  auto euler2=naive_euler(r);

  debug(euler1);
  debug(euler2);

  auto euler=euler1;

  range(i, 1, r + 1) {
    cnt[i] = r - i + 1;
    cnt[i] -= (r / i) - 1;
    cnt[i] -= euler[i] + 1;
  }

  ll ans = 0;
  range(i, l, r + 1) { ans += cnt[i]; }
  cout << ans * 2 << endl;
}
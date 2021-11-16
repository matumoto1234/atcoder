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

namespace geometry {
  constexpr double EPS = 1e-8;

  bool equals(double a, double b) {
    return fabs(a - b) < EPS;
  }

  struct point {
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    point operator+(point p) { return point(x + p.x, y + p.y); }
    point operator-(point p) { return point(x - p.x, y - p.y); }
    point operator*(double k) { return point(x * k, y * k); }
    point operator/(double k) { return point(x / k, y / k); }
    point &operator+=(point p) { x += p.x; y += p.y; return *this; }
    point &operator-=(point p) { x -= p.x; y -= p.y; return *this; }
    point &operator*=(double k) { x *= k; y *= k; return *this; }
    point &operator/=(double k) { x /= k; y /= k; return *this; }
    point operator-() const { return point(-x, -y); }

    bool operator==(const point &p) const { return (fabs(x - p.x) < EPS) && (fabs(x - p.y) < EPS); }
    bool equals(const point &p) const { return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS; }
    bool operator<(const point &p) const { return x == p.x ? y < p.y : x < p.x; }
    double euclid() { return sqrt(x * x + y * y); }
    double euclid(point p) { p.x -= x, p.y -= y; return p.euclid(); }

    double radian() { return atan2(y, x) + (y < 0 ? 2 * M_PI : 0.0); } // 0~2π
    double radian(point p) { p.x -= x, p.y -= y; return p.radian(); }
    double theta() { return radian() * 180.0 / M_PI; }
    double theta(point p) { return radian(p) * 180.0 / M_PI; }

    friend istream &operator>>(istream &is, point &p) { is >> p.x >> p.y; return is; }
    friend ostream &operator<<(ostream &os, const point &p) { os << p.x << ' ' << p.y; return os; }
  };

  bool comp_x(point a, point b) { return fabs(a.x - b.x) < EPS ? a.y < b.y : a.x < b.x; }
  bool comp_y(point a, point b) { return fabs(a.y - b.y) < EPS ? a.x < b.x : a.y < b.y; }
  double cross(point a, point b) { return a.x * b.y - a.y * b.x; }

  // rotate_clockwise
  point rot_cw(point origin, double radian, point p) {
    p -= origin;
    point res = point(p.x * cos(radian) + p.y * sin(radian),
                      -p.x * sin(radian) + p.y * cos(radian));
    res += origin;
    return res;
  }

  // rotate_counterclockwise
  point rot_ccw(point origin, double radian, point p) {
    p -= origin;
    point res = point(p.x * cos(radian) + p.y * -sin(radian),
                      p.x * sin(radian) + p.y * cos(radian));
    res += origin;
    return res;
  }

  // 線分abをm:nに内分する点
  point internal_division(point a, point b, double m, double n) {
    if ( equals(m + n, 0.0) ) return point(0, 0);
    return point((a.x * n + b.x * m) / (m + n), (a.y * n + b.y * m) / (m + n));
  }

  // 線分abをm:nに外分する点
  point external_division(point a, point b, double m, double n) {
    if ( equals(m - n, 0.0) ) return point(0, 0);
    return point((-n * a.x + m * b.x) / (m - n), (-n * a.y + m * b.y) / (m - n));
  }
}
using namespace geometry;





vector<point> parallel_translation(point ds, vector<point> ps) {
  for ( auto &p : ps )
    p += ds;
  return ps;
}

vector<point> rotate_clockwise_points(point origin, double radian, vector<point> ps) {
  for ( auto &p : ps ) p = rot_cw(origin, radian, p);
  return ps;
}

vector<point> rotate_counterclockwise_points(point origin, double radian, vector<point> ps) {
  for ( auto &p : ps ) p = rot_ccw(origin, radian, p);
  return ps;
}

vector<point> normalization(point p1, point p2, vector<point> ps) {
  p2 -= p1;
  ps = parallel_translation(-p1, ps);
  ps = rotate_clockwise_points(point(0, 0), p2.radian(), ps);
  return ps;
}

int valid_count(vector<point> s,vector<point> t) {
  int res = 0;
  sort(s.begin(),s.end(),comp_x);
  sort(t.begin(),t.end(),comp_x);
  range(i, 0, s.size()) {
    if ( s[i].equals(t[i]) ) res++;
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cerr<<fixed<<setprecision(1);
  cout<<fixed<<setprecision(1);

  int n;
  cin >> n;
  vector<point> s(n), t(n);
  for ( auto &p : s )
    cin >> p;
  for ( auto &p : t )
    cin >> p;

  if ( n == 1 ) {
    cout << "Yes" << endl;
    return 0;
  }


  s = normalization(s[0], s[1], s);

  // choose 2 point in t
  range(i, 0, n) {
    range(j, 0, n) {
      if(i==j) continue;
      auto nt = normalization(t[i], t[j], t);

      if ( valid_count(s, nt) == n ) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
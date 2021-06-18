#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define range(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1 )
#define rrange(i, l, r) for ( int i = (int)(r)-1; i >= (int)(l); (i) -= 1 )
#define debug(x) cerr << "(" << __LINE__ << ") " << #x << ": " << (x) << endl;
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << p.first << ' ' << p.second; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { for ( pair<T1, T2> x : v ) { os << x << (x.first == v.rbegin()->first && x.second == v.rbegin()->second ? "" : "\n"); } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { if(!v.empty()) { os << v.front(); v.pop(); } while (!v.empty()) { os << " " << v.front(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { if(!v.empty()) { os << v.top(); v.pop(); } while (!v.empty()) { os << " " << v.top(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for ( T x : v ) { os << (x == v.front() ? "" : " ") << x; } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { for ( T x : v ) { os << (x == v.front() ? "" : " ") << x; } return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { for ( T x : v ) { os << (x == *v.begin() ? "" : " ") << x; } return os; }
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

const double EPS=1e-10;
struct Point{
  double x,y;
  Point(){}
  Point(double x,double y):x(x),y(y){}
  Point operator+(Point p){ return Point(x+p.x,y+p.y); }
  Point operator-(Point p){ return Point(x-p.x,y-p.y); }
  Point operator*(double k){ return Point(x*k,y*k); }
  Point operator/(double k){ return Point(x/k,y/k); }
  Point &operator+=(Point p){ x+=p.x;y+=p.y; return *this; }
  Point &operator-=(Point p){ x-=p.x;y-=p.y; return *this; }
  Point &operator*=(double k){ x*=k;y*=k; return *this; }
  Point &operator/=(double k){ x/=k;y/=k; return *this; }
  Point operator-() const { return Point(-x,-y); }

  bool operator==(const Point &p) const { return (fabs(x-p.x)<EPS)&&(fabs(x-p.y)<EPS); }
  bool operator<(const Point &p) const { return x==p.x?y<p.y:x<p.x; }
  double euclid(){ return sqrt(x*x+y*y); }
  friend istream &operator>>(istream &is,Point &p) { is>>p.x>>p.y; return is;}
  friend ostream &operator<<(ostream &os,Point &p) { os<<p.x<<' '<<p.y; return os;}
};

bool comp_x(Point a,Point b){ return a.x==b.x?a.y<b.y:a.x<b.x; }
bool comp_y(Point a,Point b){ return a.y==b.y?a.x<b.x:a.y<b.y; }
double cross(Point p1,Point p2){ return p1.x*p2.y-p1.y*p2.x; }

Point rotCW(Point origin,Point p,double rad){
  p.x-=origin.x;
  p.y-=origin.y;
  Point res=Point(p.x*cosl(rad)+p.x*sinl(rad),-p.y*sinl(rad)+p.y*cosl(rad));
  res.x+=origin.x;
  res.y+=origin.y;
  return res;
}

Point rotCCW(Point origin,Point p,double rad){
  p.x-=origin.x;
  p.y-=origin.y;
  Point res=Point(p.x*cos(rad)-p.y*sin(rad),p.x*sin(rad)+p.y*cos(rad));
  res.x+=origin.x;
  res.y+=origin.y;
  return res;
}

bool equal(double a,double b){ return fabs(a-b)<EPS; }

// 線分abをm:nに内分する点
Point internalDivision(Point a,Point b,double m,double n){
  if(equal(m+n,0.0)) return Point(0,0);
  return Point((a.x*n+b.x*m)/(m+n),(a.y*n+b.y*m)/(m+n));
}

// 線分abをm:nに外分する点
Point externalDivision(Point a,Point b,double m,double n){
  if(equal(m-n,0.0)) return Point(0,0);
  return Point((-n*a.x+m*b.x)/(m-n),(-n*a.y+m*b.y)/(m-n));
}

int main() {
  double n;
  cin >> n;
  Point p1,p2;
  cin>>p1>>p2;

  double rad = 360.0*M_PI/(n*180.0);

  // cerr<<fixed<<setprecision(10);
  // cerr<<p1<<p2<<endl;

  // Point center((p2.x+p1.x)/2,(p2.y+p1.y)/2);
  Point center = internalDivision(p1,p2,1,1);
  Point ans = rotCCW(center,p1,rad);
  cout<<fixed<<setprecision(10);
  // cout<<rad<<endl;
  // cout<<center<<endl;
  cout<<ans<<endl;
}
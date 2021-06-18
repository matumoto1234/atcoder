#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define range(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1 )
#define rrange(i, l, r) for ( int i = (int)(r)-1; i >= (int)(l); (i) -= 1 )
#define debug(...) debug_func(0, #__VA_ARGS__, __VA_ARGS__)
template <typename T> void debug_func(int cnt, T name) { cerr << endl; }
template <typename T1,typename T2, typename... T3> void debug_func(int cnt, const T1 &name,const T2 &a, const T3&... b) { cerr << name[cnt] << ":" << a << " "; debug_func(cnt + 2, name, b...); }
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

ll solve(vector<ll> a,vector<ll> b){
  ll res=INF64;
  range(i,0,a.size()){
    int ind=lower_bound(b.begin(),b.end(),a[i])-b.begin();
    if(ind>0) chmin(res,abs(b[ind-1]-a[i]));
    if(ind<(int)b.size()-1) chmin(res,abs(b[ind+1]-a[i]));
    chmin(res,abs(b[ind]-a[i]));
  }
  return res;
}

ll solve2(vector<ll> a){
  int n=a.size();
  ll res=0;
  range(i,0,n){
    res+=abs(a[i]-a[i+1]);
    i++;
  }
  // cerr<<"res:"<<res<<endl;
  return res;
}

// a:奇数, b:偶数
pair<ll,vector<ll>> solve3(vector<ll> a, vector<ll> b){
  ll res=INF64;
  int ai,bi;
  range(i,0,a.size()){
    int ind=lower_bound(b.begin(),b.end(),a[i])-b.begin();
    if(ind>0){
      if(chmin(res,abs(b[ind-1]-a[i]))){
        ai=i;
        bi=ind-1;
      }
    }
    if(ind<(int)b.size()-1){
      if(chmin(res,abs(b[ind+1]-a[i]))){
        ai=i;
        bi=ind+1;
      }
    }
    if(chmin(res,abs(b[ind]-a[i]))){
      ai=i;
      bi=ind;
    }
  }
  // a.erase(a.begin()+ai);
  b.erase(b.begin()+bi);
  return {res,b};
}

// a:奇,b:奇,c:偶
ll solve4(vector<ll> a,vector<ll> b,vector<ll> c){
  auto [valbc, vecbc] = solve3(b,c);
  auto [valac, vecac] = solve3(a,c);
  return min(valbc+solve(a,vecbc), valac+solve(vecac,b));
}

int main() {
  int n;
  cin>>n;
  n*=2;
  vector<ll> r,g,b;
  vector<ll> a(n);
  range(i,0,n){
    char c;
    cin>>a[i]>>c;
    if(c=='R') r.emplace_back(a[i]);
    if(c=='G') g.emplace_back(a[i]);
    if(c=='B') b.emplace_back(a[i]);
  }

  sort(a.begin(),a.end());
  sort(r.begin(),r.end());
  sort(g.begin(),g.end());
  sort(b.begin(),b.end());

  ll ans=0;
  if(r.size()%2 && g.size()%2){
    ans=solve(r,g);
    if(!r.empty() && !g.empty() && !b.empty()) chmin(ans,solve4(r,g,b));
  }
  if(r.size()%2 && b.size()%2){
    ans=solve(r,b);
    if(!r.empty() && !g.empty() && !b.empty()) chmin(ans,solve4(r,b,g));
  }
  if(g.size()%2 && b.size()%2){
    ans=solve(g,b);
    if(!r.empty() && !g.empty() && !b.empty()) chmin(ans,solve4(g,b,r));
  }
  //cerr<<"ans:"<<ans<<endl;
  chmin(ans,solve2(a));

  cout<<ans<<endl;
}
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

vector<vector<int>> G;
vector<bool> used;
bool dfs(int ind,int g){
  used[ind]=true;
  bool res=false;
  for(int to:G[ind]){
    if(used[to]) continue;
    if(to==g) return true;
    res|=dfs(to,g);
  }
  return res;
}

vector<int> vs;
void dfs2(int ind){
  used[ind]=true;
  for(int to:G[ind]){
    if(used[to]) continue;
    vs.emplace_back(to);
    dfs2(to);
  }
}

bool is_valid(vector<int> a){
  range(i,0,a.size()){
    used.assign(a.size(),false);
    if(dfs(a[i],i)) return false;
  }
  return true;
}

int main() {
  int n;
  cin>>n;
  G.resize(n);
  range(i,1,n){
    int p;
    cin>>p;
    p--;
    G[p].emplace_back(i);
  }

  used.assign(n,false);
  vector<vector<int>> arrive(n);
  range(i,1,n){
    vs.clear();
    dfs2(i);
    arrive[i]=vs;
  }
  

  vector<int> a(n);
  iota(a.begin(),a.end(),0);
  do{
    if(!is_valid(a)) continue;
    cerr<<a<<endl;
  }while(next_permutation(a.begin(),a.end()));
}
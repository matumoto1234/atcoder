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


// void naive(int n,vector<ll> as){
//   rep(i,1<<(n-1)){
//     vector<ll> sums;
//     ll sum=0;
//     rep(j,n-1){
//       sum+=as[j];
//       if(i>>j&1){
//         sums.emplace_back(sum);
//         sum=0;
//       }
//     }
//     sum+=as.back();
//     sums.emplace_back(sum);
//     sum=0;

//     bool valid=true;
//     rep(j,sums.size()){
//       if(sums[j]%(j+1)){
//         valid=false;
//         break;
//       }
//     }
//     if(!valid) continue;
//     bitset<10> bit(i);
//     debug(i,bit,sums);
//   }
// }


template <typename T>
struct cumulative_sum_mod {
  vector<T> dat;
  int MOD;
  cumulative_sum_mod(int n,int _MOD) : dat(n + 1), MOD(_MOD) {}

  void set(int k, T x) { dat[k + 1] = x; }

  void build() {
    for ( int i = 0; i < (int)dat.size(); i++ ) {
      dat[i + 1] += dat[i];
      dat[i + 1] %= MOD;
    }
  }

  // [l,r)
  T query(int l, int r) {
    return (T)(((dat[r] - dat[l]) % MOD + MOD ) % MOD);
  }
};


int n;
int ans=0;
void dfs(int mod,int idx,vector<vector<P>> &sections){
  if(idx==n){
    ans++;
    return;
  }

  rep(i,sections[mod].size()){
    auto [l,r]=sections[mod][i];
    if(l==idx){
      dfs(mod+1,r,sections);
    }
  }
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin>>n;
  vector<ll> as(n);
  for(auto &a:as)cin>>a;

  // use [i,n]
  vector<vector<P>> sections(n+5);
  // sections.resize(n+1);
  
  // mod i
  range(i,2,n+1){
    vector<ll> bs=as;
    for(ll &b:bs) b%=i;
    cumulative_sum_mod<ll> sum(bs.size(),i);
    rep(j,bs.size()) sum.set(bs[j],j);

    sum.build();

    range(j,i-1,n){
      range(k,j+1,n+1){
        if(sum.query(j,k)==0){
          P p = make_pair(j,k);
          sections[i].push_back(p);
        }
      }
    }
  }

  range(i,0,sections[2].size()){
    auto [l,r]=sections[2][i];
    dfs(3,r,sections);
  }

  cout<<ans<<endl;
}
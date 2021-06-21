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

class LowLink{
public:
  vector<int> articulations;
  vector<pair<int,int>> bridges;

  LowLink(int V):G(V){}

  void add_edge(int from,int to){ G[from].emplace_back(to); }

  void build(){
    int V=G.size();
    ord.assign(V,-1);
    low.resize(V);

    int k=0;
    for(int i=0;i<V;i++){
      if(ord[i]==-1) dfs(i,k,-1);
    }
    sort(articulations.begin(),articulations.end());
    sort(bridges.begin(),bridges.end());
  }

private:
  vector<vector<int>> G;
  vector<int> ord,low;

  void dfs(int id,int &k,int par){
    ord[id]=low[id]=k;
    k++;

    bool is_articulation=false;
    int child_cnt=0;

    for(int to:G[id]){
      if(ord[to]==-1){
        child_cnt++;
        dfs(to,k,id);

        low[id]=min(low[id],low[to]);
        if(par!=-1&&ord[id]<=low[to]) is_articulation=true;
        if(ord[id]<low[to]) bridges.emplace_back(min(id,to),max(id,to));
      }else if(to!=par){
        low[id]=min(low[id],ord[to]);
      }
    }

    if(par==-1&&child_cnt>=2) is_articulation=true;
    if(is_articulation) articulations.emplace_back(id);
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  LowLink G(n);
  range(i,0,m){
    int a,b;
    cin>>a>>b;
    a--,b--;
    G.add_edge(a,b);
    G.add_edge(b,a);
  }

  G.build();

  cout<<G.bridges.size()<<endl;
}
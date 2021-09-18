#include <bits/stdc++.h>
using namespace std;


// {{{

// clang-format off
#define len(x) ((int)(x).size())
#define _over_load(_1,_2,_3,_4,NAME,...) NAME
#define range(...) _over_load(__VA_ARGS__, range4, range3, range2)(__VA_ARGS__)
#define range2(i, r) for ( int i = 0; i < (int)(r); (i) += 1)
#define range3(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1)
#define range4(i, l, r, inc) for ( int i = (int)(l); i < (int)(r); (i) += (inc))
#define rrange(...) _over_load(__VA_ARGS__, rrange4, rrange3, rrange2)(__VA_ARGS__)
#define rrange2(i, r) for ( int i = (int)(r) - 1; i >= 0; (i) -= 1)
#define rrange3(i, l, r) for ( int i = (int)(r) - 1; i >= (int)(l); (i) -= 1)
#define rrange4(i, l, r, inc) for ( int i = (int)(r) - 1; i >= (int)(l); (i) -= inc)
#define whole(f, x, ...) ([&](decltype((x)) container) { return (f)( begin(container), end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)
#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)
template <typename T, typename... T2> void debug_function(string_view name, const T &a, T2 &&...rest) {
  stack<char> bs;
  string_view lbs = "({[<", rbs = ")}]>";
  int end = name.size();
  for ( int i = 0; i < (int)name.size(); i++ ) {
    if ( lbs.find(name[i]) != string::npos ) bs.push(name[i]);
    if ( rbs.find(name[i]) != string::npos && !bs.empty() ) bs.pop();
    if ( name[i] == ',' && bs.empty() ) {
      end = i;
      break;
    }
  }
  cerr << name.substr(0, end) << ":" << a;
  if constexpr ( sizeof...(rest) == 0 ) {
    cerr << '\n';
  } else {
    cerr << ' ';
    debug_function(name.substr(name.find_first_not_of(' ', end + 1)), forward<T2>(rest)...);
  }
}
template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << p.first << ' ' << p.second; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { for ( pair<T1, T2> x : v ) { os << "(" << x.first <<", " << x.second << ")" << (v.rbegin()->first == x.first ? "" : ", "); } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { if(!v.empty()) { os << v.front(); v.pop(); } while (!v.empty()) { os << " " << v.front(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { if(!v.empty()) { os << v.top(); v.pop(); } while (!v.empty()) { os << " " << v.top(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in : v) is >> in; return is; }
struct IoSetup { IoSetup(int x = 15) { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(x); cerr << fixed << setprecision(x); } } iosetup;
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


bool is_range(int y,int x,int h,int w){
  return 0<=y&&y<h&&0<=x&&x<w;
}

P find_start(vector<vector<int>> &as){
  range(i,5){
    range(j,5){
      if(as[i][j]){
        return make_pair(i,j);
      }
    }
  }
  return make_pair(-1,-1);
}


vector<P> hs;
bool solve(vector<vector<int>> &bit,vector<vector<int>> &as){
  // on line
  // {{{
  range(i,5) {
    int l=0;
    range(j,5){
      if(bit[i][j]){
        l=j;
        break;
      }
    }
    int r=0;
    rrange(j,5){
      if(bit[i][j]){
        r=j;
        break;
      }
    }
    range(j,l+1,r){
      if(bit[i][j]){
        return false;
      }
    }
  }

  range(j,5){
    int u=0;
    range(i,5){
      if(bit[i][j]){
        u=i;
        break;
      }
    }
    int d=0;
    rrange(i,5){
      if(bit[i][j]){
        d=i;
        break;
      }
    }
    range(i,u+1,d){
      if(bit[i][j]){
        return false;
      }
    }
  }
  // }}}


  // is parallel
  // {{{
  range(i,5){
    range(j,5){
      if(!bit[i][j]) break;
      int cnt=0;
      range(d,4){
        int ny=i,nx=j;
        while(is_range(ny,nx,5,5)){
          if(bit[ny][nx]){
            cnt++;
            break;
          }
          ny+=dy[d],nx+=dx[d];
        }
      }
      if(cnt!=2){
        return false;
      }
    }
  }
  // }}}


  // build line
  // {{{
  auto line=make_vector(5,5,0);
  bool flg=false;
  range(i,5){
    range(j,5){
      if(flg){
        line[i][j]=true;
      }
      if(!bit[i][j]) continue;
      flg=!flg;
    }
  }
  flg=false;
  range(j,5){
    range(i,5){
      if(flg){
        line[i][j]=true;
      }
      if(!bit[i][j]) continue;
      flg=!flg;
    }
  }
  // }}}


  // all houses in range
  // {{{
  constexpr int dy2[]={0,0,1,0};
  constexpr int dx2[]={0,0,0,1};
  constexpr int dy3[]={1,0,1,1};
  constexpr int dx3[]={0,1,1,1};

  auto [sy,sx]=find_start(as);
  auto group = make_vector(4,4,0);
  queue<P> q;
  q.emplace(sy,sx);
  group[sy][sx]=1;
  while(!q.empty()){
    auto [y,x]=q.front();
    q.pop();
    range(i,4){
      int ny=y+dy[i],nx=x+dx[i];
      int ny2=y+dy2[i],nx2=x+dx2[i];
      int ny3=y+dy3[i],nx3=x+dx3[i];
      if(!is_range(ny,nx,4,4)) continue;
      if(line[ny2][nx2] and line[ny3][nx3]) continue;
      q.emplace(ny,nx);
      group[ny][nx]=1;
    }
  }

  for(auto [y,x]:hs){
    if(!group[y][x]) return false;
  }
  // }}}
  
  return true;
}


int main() {
  auto as=make_vector(4,4,0);
  range(i,4){
    range(j,4){
      cin>>as[i][j];
    }
  }

  range(i,5){
    range(j,5){
      if(as[i][j]){
        hs.emplace_back(i,j);
      }
    }
  }

  int ans=0;
  range(i,1<<25){
    auto bit=make_vector(5,5,0);
    range(j,25){
      if(i>>j&1){
        bit[j/5][j%5]=1;
      }
    }

    if(solve(bit,as)) ans++;
  }
  cout<<ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ull = unsigned long long;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr char newl = '\n';

constexpr int dy[]={0,1,0,-1},dx[]={1,0,-1,0};
constexpr int limit = 10000000;
int sy,sx;
vector<vector<int>> t(50,vector<int>(50));
vector<vector<int>> p(50,vector<int>(50));

struct before{
  int y,x,v;
  before(){}
  before(int _y,int _x,int _v):y(_y),x(_x),v(_v){}
};
vector<vector<before>> bs(50,vector<before>(50,before(-1,-1,0)));
bool used[50][50];
vector<vector<int>> memo(50,vector<int>(50,-1));

int dfs(int y,int x,int sum,int depth){
  if(depth==limit){
    return sum;
  }

  used[y][x]=true;
  range(i,0,4){
    int ny=y+dy[i],nx=x+dx[i];
    if(ny<0||nx<0||ny>=50||nx>=50) continue;
    if(t[y][x]==t[ny][nx]){
      used[ny][nx]=true;
      break;
    }
  }

  int &res=memo[y][x];
  if(res!=-1) return res;
  res=sum;

  range(i,0,4){
    int ny=y+dy[i],nx=x+dx[i];
    if(ny<0||nx<0||ny>=50||nx>=50) continue;
    if(used[ny][nx]) continue;

    int v=dfs(ny,nx,sum+p[y][x],depth+1);
    if(res<v){
      if(bs[y][x].v<v) bs[y][x]=before(ny,nx,v);
      res=v;
    }
  }

  used[y][x]=false;
  range(i,0,4){
    int ny=y+dy[i],nx=x+dx[i];
    if(ny<0||nx<0||ny>=50||nx>=50) continue;
    if(t[y][x]==t[ny][nx]){
      used[ny][nx]=false;
      break;
    }
  }
  return res;
}

constexpr char dirs[] = {'R','D','L','U'};
char dir_to_c(int y,int x,int ny,int nx){
  ny-=y;
  nx-=x;
  range(i,0,4){
    if(dy[i]==ny&&dx[i]==nx) return dirs[i];
  }
  return 'D';
}

int main() {
  cin>>sy>>sx;
  range(i,0,50) range(j,0,50){
    cin>>t[i][j];
  }
  range(i,0,50) range(j,0,50){
    cin>>p[i][j];
  }

  int v=dfs(sy,sx,0,0);
  //cerr<<v<<endl;

  string ans;
  int y=sy,x=sx;
  vector<vector<bool>> arrived(50,vector<bool>(50,false));
  range(i,0,2500){
    arrived[y][x]=true;
    int by=bs[y][x].y;
    int bx=bs[y][x].x;
    if(by==-1 || bx==-1) break;
    if(arrived[by][bx]) break;
    ans+=dir_to_c(y,x,by,bx);
    y=by;
    x=bx;
  }
  cout<<ans<<endl;
}
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
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

vector<vector<int>> gridBFS(vector<string> &s,char start,const string &wall = "#"){
  const int dy[]={0,1,0,-1},dx[]={1,0,-1,0};
  int h=s.size(),w=s[0].size();
  vector<vector<int>> res(h,vector<int>(w,-1));
  queue<pair<int,int>> q;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]==start){
        q.emplace(i,j);
        res[i][j]=0;
      }
    }
  }
  while(!q.empty()){
    auto p = q.front();
    q.pop();
    for(int i=0;i<4;i++){
      int ny=p.first+dy[i],nx=p.second+dx[i];
      if(ny<0||nx<0||ny>=h||nx>=w) continue;
      if(res[ny][nx]!=-1) continue;
      if(wall.find(s[ny][nx])!=string::npos) continue;
      res[ny][nx]=res[p.first][p.second]+1;
      q.emplace(ny,nx);
    }
  }
  return res;
}

int main() {
  int n;
  cin>>n;
  vector<string> s(n);
  range(i,0,n){
    cin>>s[i];
  }

  int ans=0;
  range(i,0,n) range(j,0,9){
    if(s[i][j]=='x') ans++;
    if(s[i][j]=='o'){
      ans++;
      range(k,i,n){
        if(s[k][j]!='o') break;
        s[k][j]='.';
      }
    }
  }
  
  //range(i,0,n) cout<<s[i]<<endl;
  cout<<ans<<endl;
}
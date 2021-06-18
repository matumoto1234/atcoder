#include<bits/stdc++.h>
using namespace std;
const int INF = 100100100;
const int MAXN = 18;

// 最小値を求めるためにINFで初期化
vector<int> dp(1<<MAXN,INF);
vector<vector<int>> G(MAXN);
int n,m;

bool is_valid(int S){
  vector<vector<bool>> flg(n,vector<bool>(n,false));

  for(int i=0;i<n;i++){
    if((S>>i&1)==0) continue;

    for(int j=0;j<(int)G[i].size();j++){
      flg[i][G[i][j]]=true;
    }
  }

//  for(int i=0;i<n;i++){
//    for(int j=0;j<n;j++){
//      cout<<flg[i][j]<<' ';
//    }
//    cout<<endl;
//  }
//

  for(int i=0;i<n;i++){
    if((S>>i&1)==0) continue;

    for(int j=0;j<n;j++){
      if((S>>j&1)==0) continue;
      if(i==j) continue;

      if(flg[i][j]==false){
        return false;
      }
    }
  }
  return true;
}

int built_count(int S){
  int res=0;
  for(int i=0;i<n;i++){
    if(S>>i&1) res++;
  }
  return res;
}

// dfs(S):=Sの部分集合の中での完全グラフの個数の最小値
int dfs(int S){
  //cerr<<bitset<MAXN>(S)<<endl;
  int &res=dp[S];
  if(res!=INF) return res;
  // 集合に含まれる頂点が0ならば完全グラフはない
  if(S == 0) return res=1;
  if(built_count(S)==1) return res=1;
  // 完全グラフであれば最小値は1
  if(is_valid(S)) return res=1;
  
  // SのSを除いた部分集合(nS)とそれの補集合(T)が欲しい
  // 補集合は~nS&Sでとるか、S-nSでとる
  for(int nS=S;;nS=(nS-1)&S){
    if(nS==S) continue;
    if(nS==0){
      break;
    }
    int T=S-nS;
    res=min(res,dfs(T)+dfs(nS));
  }
  return res;
}

int main(){
  cin>>n>>m;
  if(m==0) {
    cout<<n<<endl;
    return 0;
  }

  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  // 全頂点を集合に含んでスタート
  cout<<dfs((1<<n)-1)<<endl;

//  cout<<is_valid(2)<<endl;
//  cout<<is_valid(3)<<endl;
//  cout<<is_valid(5)<<endl;
//  cout<<is_valid(6)<<endl;
}
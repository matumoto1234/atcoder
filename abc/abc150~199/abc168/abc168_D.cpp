#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000;

vector<vector<int>> G(MAXN);
vector<bool> arrived(MAXN,false);
vector<int> ans(MAXN);
int n,m;

int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  queue<int> Q;
  arrived[0]=true;
  Q.push(0);
  while(!Q.empty()){
    int idx=Q.front();
    Q.pop();
    for(int to:G[idx]){
      if(arrived[to]) continue;
      arrived[to]=true;
      ans[to]=idx;
      Q.push(to);
    }
  }
  for(int i=0;i<n;i++){
    if(arrived[i]==false){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  for(int i=1;i<n;i++){
    cout<<ans[i]+1<<'\n';
  }
}
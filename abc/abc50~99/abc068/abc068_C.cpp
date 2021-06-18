#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> a(n);

  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  vector<int> arrived(n,0);
  arrived[0]=1;
  stack<int> st;
  st.push(0);
  while(!st.empty()){
    int now=st.top();
    st.pop();

    if(arrived[now]==3){
      continue;
    }
    for(int i=0;i<(int)a[now].size();i++){
      if(arrived[a[now][i]]){
        continue;
      }
      arrived[a[now][i]]=arrived[now]+1;
      st.push(a[now][i]);
    }
  }
  if(arrived[n-1]){
    cout<<"POSSIBLE"<<endl;
  }else{
    cout<<"IMPOSSIBLE"<<endl;
  }
  return 0;
}
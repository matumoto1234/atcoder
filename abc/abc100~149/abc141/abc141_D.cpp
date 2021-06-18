#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(n);
  priority_queue<int> que;
  for(int i=0;i<n;i++){
    cin>>a[i];
    que.push(a[i]);
  }
  for(int i=0;i<m;i++){
    int temp=que.top();
    que.pop();
    temp/=2;
    que.push(temp);
  }
  ll sum=0;
  for(int i=0;i<n;i++){
    sum+=que.top();
    que.pop();
  }
  cout<<sum<<endl;
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;

  int minv=0;
  vector<bool> v(200002,false);
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    v[a[i]]=true;
    if(minv==a[i]){
      for(int j=minv+1;j<=200001;j++){
        if(v[j]==false){
          minv=j;
          break;
        }
      }
    }
    cout<<minv<<"\n";
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int a[4];
  int sum=0;
  for(int i=0;i<4;i++){
    cin>>a[i];
    sum+=a[i];
  }
  bool flg=false;
  for(int i=0;i<4;i++){
    for(int j=0;j<(1<<4);j++){
      bitset<4> tmp(j);
      int subsum=0;
      for(int k=0;k<4;k++){
        if(tmp[k]){
          subsum+=a[k];
        }
      }
      if(subsum==sum-subsum){
        flg=true;
        break;
      }
    }
    if(flg){
      break;
    }
  }
  cout<<(flg?"Yes":"No")<<endl;
  return 0;
}
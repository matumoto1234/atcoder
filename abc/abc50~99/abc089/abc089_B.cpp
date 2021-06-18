#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<int> cnt(4,0);
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    switch (s[0])
    {
      case 'G':
      cnt[0]=1;
      break;
      case 'W':
      cnt[1]=1;
      break;
      case 'Y':
      cnt[2]=1;
      break;
      case 'P':
      cnt[3]=1;
      break;
    default:
      break;
    }
  }
  int sum=0;
  for(int i=0;i<4;i++){
    sum+=cnt[i];
    //cout<<cnt[i]<<endl;
  }
  if(sum==3){
    cout<<"Three"<<endl;
  }else{
    cout<<"Four"<<endl;
  }
  return 0;
}
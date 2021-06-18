#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> a(6);
  vector<int> cnt(4,0);
  for(int i=0;i<6;i++){
    cin>>a[i];
    cnt[a[i]-1]++;
  }
  sort(cnt.begin(),cnt.end());
  bool flg=true;
  for(int i=0;i<4;i++){
    //printf("%d\n",cnt[i]);
    if(i<2&&cnt[i]!=1){
      flg=false;
    }
    else if(i>=2&&cnt[i]!=2){
      flg=false;
    }
  }
  cout<<(flg?"YES":"NO")<<endl;
  return 0;
}
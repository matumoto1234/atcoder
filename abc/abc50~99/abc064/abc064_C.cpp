#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, cnt = 0, monster = 0;
  cin>>n;
  vector<int> a(n), list(8, 0);
  for (int i = 0; i < n;i++){
    cin >> a[i];
    if(a[i]>=1&&a[i]<=399){
      list[0]++;
    }else if(a[i]>=400&&a[i]<=799){
      list[1]++;
    }else if(a[i]>=800&&a[i]<=1199){
      list[2]++;
    }else if(a[i]>=1200&&a[i]<=1599){
      list[3]++;
    }else if(a[i]>=1600&&a[i]<=1999){
      list[4]++;
    }else if(a[i]>=2000&&a[i]<=2399){
      list[5]++;
    }else if(a[i]>=2400&&a[i]<=2799){
      list[6]++;
    }else if(a[i]>=2800&&a[i]<=3199){
      list[7]++;
    }else{
      monster++;
    }
  }
  for (int i = 0; i < 8;i++){
    if(list[i]>=1){
      cnt++;
    }
    //cout << list[i] << " list" << endl;
  }
  if(cnt==0){
    cnt++;
    monster--;
  }
  cout << cnt << " " << cnt + monster << endl;
  return 0;
}
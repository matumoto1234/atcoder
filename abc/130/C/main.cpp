#include<bits/stdc++.h>
using namespace std;
using ld = long double;

int main(){
  int a,b,x,y;
  cin>>a>>b>>x>>y;
  cout<<(double)a*(double)b/2.0<<" ";
  if(x+x==a&&y+y==b){
    cout<<1<<endl;
  }else{
    cout<<0<<endl;
  }
  return 0;
}
#include<bits/stdc++.h>
using namespace std;

int a,b,c,x,y;
int solve(){
  int res=0;
  if(a+b<2*c){
    res+=a*x+b*y;
  }else{
    int minxy=min(x,y);
    res+=2*minxy*c;
    x-=minxy;
    y-=minxy;
    if(x>0&&a>2*c){
      res+=2*x*c;
      return res;
    }
    if(y>0&&b>2*c){
      res+=2*y*c;
      return res;
    }
    res+=a*x+b*y;
    return res;
  }
  return res;
}

int main(){
  cin>>a>>b>>c>>x>>y;
  cout<<solve()<<endl;
}
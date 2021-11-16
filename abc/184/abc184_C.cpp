#include<bits/stdc++.h>
using namespace std;

int solve(int a,int b,int c,int d){
  if(a==c&&b==d) return 0;

  if(a+b==c+d||a-b==c-d||abs(a-c)+abs(b-d)<=3){
    return 1;
  }

  if(abs(a-c)+abs(b-d)<=6) return 2;
  if((a+b+c+d)%2==0) return 2;
  if(abs((a+b)-(c+d))<=3||abs((a-b)-(c-d))<=3) return 2;

  return 3;
}

int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<solve(a,b,c,d)<<endl;
}
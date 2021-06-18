#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct zahyo{
  ld x,y;
};

int main() {
  zahyo a,b;
  cin>>a.x>>a.y>>b.x>>b.y;
  b.y*=-1.0;
  cout<<fixed<<setprecision(10);
  if(a.x==b.x){
    cout<<a.x-a.y<<endl;
    return 0;
  }
  ld t=(b.y-a.y)/(b.x-a.x);
  cout<<(t*a.x-a.y)/t<<endl;
  return 0;
}
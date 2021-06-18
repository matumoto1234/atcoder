#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int a,b,x,y;
  cin>>a>>b>>x>>y;
  
  int v1,v2;
  v1=v2=0;
  if(a>b){
    for(int i=a;i>b+1;i--){
      v1+=y;
      v2+=2*x;
    }
    v1+=x;
    v2+=x;
  }else{
    for(int i=a;i<b;i++){
      v1+=y;
      v2+=2*x;
    }
    v1+=x;
    v2+=x;
  }
  cerr<<v1<<' '<<v2<<endl;
  cout<<min(v1,v2)<<endl;
  return 0;
}
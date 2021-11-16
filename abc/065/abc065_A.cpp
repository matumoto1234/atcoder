#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,a,b;
  cin>>x>>a>>b;
  if(a-b>=0){
    cout << "delicious"<<endl;
    return 0;
  }
  if(abs(a-b)<=x){
    cout<<"safe"<<endl;
  }else{
    cout<<"dangerous"<<endl;
  }
  return 0;
}
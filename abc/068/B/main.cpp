#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  int k=1;
  cin>>n;
  while(1){
    if(k>n){
      break;
    }
    k*=2;
  }
  cout<<k/2<<endl;
  return 0;
}
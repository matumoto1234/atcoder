#include<iostream>
using namespace std;
int main(){
  int n,ans;
  cin>>n;
  n*=100;
  ans=n/108;
  if(n%108!=0){
    ans++;
  }
  if((int)(ans*1.08)==n/100){
    cout << ans << endl;
  }else{
    cout<<":("<<endl;
  }
  return 0;
}
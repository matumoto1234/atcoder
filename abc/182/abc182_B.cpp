#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int ans=2;
  int max=0;
  for(int i=2;i<=1000;i++){
    int counter=0;
    for(int j=0;j<n;j++){
      if(a[j]%i==0){
        counter++;
      }
    }
    if(max<counter){
      max=counter;
      ans=i;
    }
  }
  cout<<ans<<endl;
  return 0;
}
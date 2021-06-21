#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a.rbegin(),a.rend());
  pair<int,int> p;
  p.first=0;
  p.second=0;
  for(int i=0;i<n;i++){
    if(i%2==0){
      p.first+=a[i];
    }else{
      p.second+=a[i];
    }
  }
  cout<<p.first-p.second<<endl;
  return 0;
}
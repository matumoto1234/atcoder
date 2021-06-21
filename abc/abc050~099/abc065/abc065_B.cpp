#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    a[i]--;
  }
  vector<bool> arrived(n,false);
  arrived[0]=true;
  int i=a[0];
  bool flg;
  int counter=1;
  while(1){
    if(i==1){
      flg=true;
      break;
    }
    if(arrived[i]){
      flg=false;
      break;
    }
    arrived[i]=true;
    i=a[i];
    counter++;
  }
  cout<<(flg?counter:-1)<<endl;
  return 0;
}
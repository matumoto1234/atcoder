#include<bits/stdc++.h>
using namespace std;
int main(){
  int a[3];
  cin>>a[0]>>a[1]>>a[2];
  sort(a,&a[3]);
  int maxl=a[0]+a[1]+a[2];
  int minl;
  if(a[0]+a[1]>a[2]){
    minl=0;
  }else{
    minl=a[2]-(a[0]+a[1]);
  }
  double maxs=maxl*maxl*M_PI;
  double mins=minl*minl*M_PI;
  cout<<fixed<<setprecision(7);
  cout<<maxs-mins<<endl;
  return 0;
}
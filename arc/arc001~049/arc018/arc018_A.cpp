#include<iostream>
#include<iomanip>
using namespace std;
int main(){
  double h,b;
  cin>>h>>b;
  h/=100.0;
  cout<<fixed<<setprecision(10);
  cout<<h*h*b<<endl;
  return 0;
}
#include<iostream>
#include<string>
using namespace std;
int main(){
  string a,b;
  cin>>a>>b;
  a+=b;
  cout<<stoi(a)*2<<endl;
  return 0;
}
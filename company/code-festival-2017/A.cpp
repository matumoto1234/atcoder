#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  string y={"YAKI"};
  bool flg=s.substr(0,4)==y;
  cout<<(flg?"Yes":"No")<<endl;
  return 0;
}
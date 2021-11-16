#include<bits/stdc++.h>
using namespace std;
int main(){
  long long a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<max(a*c,max(a*d,max(b*c,b*d)))<<endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin>>n;
  long long a=0,c=0;
  long long b=0;
  for(int i=0;i<n;i++){
    long long x;
    cin>>x;
    a+=abs(x);
    c=max(c,abs(x));
    b+=x*x;
  }
  cout<<fixed<<setprecision(10);
  cout<<a<<endl;
  cout<<sqrtl((long double)b)<<endl;
  cout<<c<<endl;
  return 0;
}
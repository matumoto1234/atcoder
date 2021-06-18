#include<iostream>
#include<vector>
#include<string>
#include<cstdint>
#include<algorithm>
using namespace std;
using ll = long long;

void Yes(){cout<<"Yes\n";}
void No(){cout<<"No\n";}

int main(){
  ll n;

  cin>>n;
  if(n>=0){
    cout<<n<<endl;
  }else{
    cout<<0<<endl;
  }
  return 0;
}
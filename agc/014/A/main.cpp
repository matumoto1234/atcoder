#include<iostream>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int ans=0;
  if(a==b&&a==c){
    if(a%2||b%2||c%2){
      cout<<0<<endl;
      return 0;
    }

    cout<<-1<<endl;
    return 0;
  }
  while(1){
    if(a%2||b%2||c%2){
      break;
    }
    int temp=a;
    int temp2=b;
    int temp3=c;
    a=temp2/2+temp3/2;
    b=temp/2+temp3/2;
    c=temp/2+temp2/2;
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}
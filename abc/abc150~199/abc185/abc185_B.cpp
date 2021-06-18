#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n,m,t;
  cin>>n>>m>>t;
  vector<int> l(m+2),r(m+2);
  for(int i=1;i<=m;i++){
    cin>>l[i]>>r[i];
  }
  l[0]=0;
  r[0]=0;
  l[m+1]=t;
  r[m+1]=t;
  int bat=n;
  bool flg=true;
  for(int i=1;i<m+2;i++){
    bat-=l[i]-r[i-1];
    if(bat<=0){
      flg=false;
      break;
    }
    bat+=r[i]-l[i];
    if(bat>n) bat=n;
  }
  cout<<(flg?"Yes":"No")<<endl;
  return 0;
}
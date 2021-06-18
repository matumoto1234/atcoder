#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
  int n,q;
  string s;
  cin>>n>>q>>s;

  vector<int> ru(n+1,0);
  for(int i=0;i<n;i++){
    if(s[i-1]=='A'&&s[i]=='C'){
      ru[i+1]++;
    }
    ru[i+1]+=ru[i];
  }

  for(int x:ru){
    cerr<<x<<' ';
  }
  cerr<<endl;

  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    l--;
    r--;
    r++;
    cout<<ru[r]-ru[l]<<'\n';
  }
  return 0;
}
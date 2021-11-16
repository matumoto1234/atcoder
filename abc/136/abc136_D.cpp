#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin>>s;
  vector<int> ans(s.size(),0);
  char last=s[0];
  int cnt=1;
  int index;
  for(int i=1;i<s.size();i++){
    if(s[i]=='R'){
      cnt++;
      last='R';
    }else if(s[i]!=last&&last=='R'){
      cnt--;
      ans[i-1]=cnt/2+1;
      ans[i]=cnt/2+1;
      if(cnt%2==1){
        ans[i]++;
        //printf("yooo\n");
      }
      index=i;
      last='L';
      cnt=0;
    }else if(s[i]==last&&last=='L'){
      if((i-index)%2){
        ans[index-1]++;
      }else{
        ans[index]++;
      }
    }
  }
  for(int i=0;i<s.size();i++){
    if(i>0){
      cout<<" "<<flush;
    }
    cout<<ans[i];
  }
  return 0;
}
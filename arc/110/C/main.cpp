#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void output(vector<int>& v){
  int n=v.size();
  for(int i=0;i<n;i++){
    cout<<v[i]<<' ';
  }
  cout<<endl;
}

int main(){
  int n;
  cin>>n;
  vector<int> a(n),sorted(n);
  vector<int> id(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    a[i]--;
    sorted[i]=a[i];
    id[a[i]]=i;
  }
  sort(sorted.begin(),sorted.end());
  vector<bool> done(n,false);
  vector<int> ans;
  for(int i=0;i<n;i++){
    if(a[i]==i){
      continue;
    }
    for(int j=id[i];jjj>i;j--){
      if(done[j-1]){
        goto END;
      }
      done[j-1]=true;
      ans.push_back(j-1);
      id[a[j-1]]++;
      id[a[j]]--;
      swap(a[j-1],a[j]);
    }
  }
  //output(a);
END:
  bool flg=true;
  for(int i=0;i<n;i++){
    if(sorted[i]!=a[i]){
      flg=false;
      break;
    }
  }
  if(flg){
    for(int x:ans){
      cout<<x+1<<'\n';
    }
  }else{
    cout<<-1<<endl;
  }
  return 0;
}
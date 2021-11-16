#include<iostream>
#include<vector>
using namespace std;

void output(const vector<int>& v){
  int n=(int)v.size();
  for(int i=0;i<n;i++){
    if(i){
      cout<<' ';
    }
    cout<<v[i];
  }
  cout<<'\n';
}

void permutation(vector<int>& v,vector<bool> used,vector<int> work){
  // END 
  int n=(int)v.size();
  bool flg=true;
  for(int i=0;i<n;i++){
    if(!used[i]){
      flg=false;
      break;
    }
  }
  if(flg){
    output(work);
  }

  for(int i=0;i<n;i++){
    if(!used[i]){
      work.push_back(v[i]);
      used[i]=true;
      permutation(v,used,work);
      continue;
    }
  }
}

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    a[i]=i;
  }
  vector<bool> used(n,false);
  vector<int> work;
  permutation(a,used,work);
  return 0;
}
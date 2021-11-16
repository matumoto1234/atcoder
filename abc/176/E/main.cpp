#include<bits/stdc++.h>
using namespace std;

struct zahyo{
  int y,x;
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int H,W,M;
  cin>>H>>W>>M;
  vector<int> h(M),w(M);
  vector<int> gyo(H,0),retsu(W,0);
  for(int i=0;i<M;i++){
    cin>>h[i]>>w[i];
    h[i]--;
    w[i]--;
    zahyo temp;
    temp.y=h[i];
    temp.x=w[i];
    gyo[h[i]]++;
    retsu[w[i]]++;
  }
  int maxg=0,maxr=0;
  for(int i=0;i<H;i++){
    if(maxg<gyo[i]){
      maxg=gyo[i];
    }
  }
  for(int i=0;i<W;i++){
    if(maxr<retsu[i]){
      maxr=retsu[i];
    }
  }
  int count_g=0,count_r=0;
  for(int i=0;i<H;i++){
    if(maxg==gyo[i]){
      count_g++;
    }
  }
  for(int i=0;i<W;i++){
    if(maxr==retsu[i]){
      count_r++;
    }
  }
  for(int i=0;i<M;i++){
    if(gyo[h[i]]==maxg){
      count_g--;
    }
    if(retsu[w[i]]==maxr){
      count_r--;
    }
  }
  if(count_g>0||count_r>0){
    cout<<maxg+maxr<<endl;
  }else{
    cout<<maxg+maxr-1<<endl;
  }
  return 0;
}
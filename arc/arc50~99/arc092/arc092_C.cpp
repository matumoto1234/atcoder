#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

struct zahyo{
  int x,y;
};

bool x_cmp(const zahyo& left,const zahyo& right){
  return left.x==right.x?left.y<right.y:left.x<right.x;
}

int main(){
  int n,ans=0;
  cin>>n;
  vector<zahyo> r(n),b(n);
  for(int i=0;i<n;i++){
    cin>>r[i].x>>r[i].y;
  }
  for(int i=0;i<n;i++){
    cin>>b[i].x>>b[i].y;
  }
  sort(b.begin(),b.end(),x_cmp);
  sort(r.begin(),r.end(),x_cmp);
  vector<int> list(100,0);
  int ymax=-1,rj=-1;
  for(int i=0;i<n;i++){
    rj=-1,ymax=-1;
    for(int j=0;j<n;j++){
      if(list[j]){
        continue;
      }
      if(b[i].x<=r[j].x||b[i].y<=r[j].y){
        continue;
      }
      if(r[j].y>ymax){
        ymax=r[j].y;
        rj=j;
      }
    }
    if(rj!=-1){
      list[rj]=1;
      //printf("i=%d r %d %d, b %d %d\n",i,r[i].x,r[i].y,b[i].x,b[i].y);
    }
  }
  for(int i=0;i<n;i++){
    if(list[i]==1){
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
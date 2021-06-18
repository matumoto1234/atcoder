#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<string> p(n);
  for(int i=0;i<n;i++){
    cin>>p[i];
  }
  sort(p.begin(),p.end());
  vector<int> counter(26,0);
  for(int i=0;i<n;i++){
    counter[p[i][0]-'A']++;
  }
  sort(counter.rbegin(),counter.rend());
  int ans=0;
  for(int j=0;j<n/k;j++){
    for (int i = 0; i < k; i++) {
      if(counter[i]==0){
        goto END;
      }
      counter[i]--;
    }
    sort(counter.rbegin(),counter.rend());
    ans++;
  }
  END:
  cout<<ans<<endl;
  return 0;
}
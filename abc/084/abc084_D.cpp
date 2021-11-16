#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
const ll N = 100000LL;

int main(){
  int q;
  cin>>q;

  vector<ll> prime(N+1,0);
  for(ll i=2;i<=N;i++){
    if(prime[i]!=0) continue;
    prime[i]=i;
    for(ll j=i*i;j<N;j+=i){
      if(prime[j]!=0) continue;
      prime[j]=i;
    }
  }

  vector<int> cs(N+2,0);
  for(int i=2;i<=N;i++){
    int idx=(i+1)/2;
    if(prime[i]==i&&prime[idx]==idx){
      cs[i]++;
    }
    cs[i+1]+=cs[i];
  }

  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    l--;
    cout<<cs[r]-cs[l]<<endl;
  }
  return 0;
}
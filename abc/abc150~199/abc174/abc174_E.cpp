#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ld = long double;
int main() {
  int n,k;
  cin>>n>>k;
  priority_queue<ld> que;
  for(int i=0;i<n;i++){
    ld temp;
    cin>>temp;
    que.push(temp);
  }
  for(int i=0;i<k;i++){
    ld temp=que.top();
    que.pop();
    temp/=2.0;
    que.push(temp);
    que.push(temp);
    cout<<(long long)temp<<endl;
  }
  cout<<(long long)que.top()<<endl;
  return 0;
}
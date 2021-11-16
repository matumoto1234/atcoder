#include<bits/stdc++.h>
using namespace std;

typedef struct{
    int d;
    int i;
}ddd;



int main(int argc,char* argv[]){
    int n,m,q;
    int maax=0;
    int temp;

    cin>>n>>m>>q;
    vector<int> ans(10,0);
    vector<int> a(n),b(n),c(n);
    vector<int> d(n);

    for(int i=0;i<q;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    sort(d.begin(),d.end());

    do {
        temp=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ans[b[i]]-ans[a[j]]==c[i]){
                    temp+=d[i];
                    cout<<"hello"<<endl;
                }
            }
        }
        if(maax<temp){
            maax=temp;
        }
            //for(auto x : ans) cout << x << " "; cout << "\n";    // ans の要素を表示
    } while( next_permutation(ans.begin(), ans.end()) );
    
    cout<<maax<<endl;
    return 0;
}
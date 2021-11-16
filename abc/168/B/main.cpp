#include <bits/stdc++.h>
#define loop(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(void){
    int k;
    string s;

    cin >> k >> s;

    if(k>s.size()){
        k=s.size();
    }

    for(int i=0;i<k;i++){
        cout << s[i] << flush;
    }
    if(k < s.size()){
        cout << "..." << flush;
    }
    cout << endl;
    return 0;
}
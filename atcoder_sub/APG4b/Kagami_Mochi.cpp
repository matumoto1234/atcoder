#include<bits/stdc++.h>
#define loop(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(int argc, char* argv[]){
    int n, ans = 0;
    cin >> n;

    vector<int> d(n);

    loop(i, n){
        cin >> d[i];
    }
    sort(d.begin(), d.end(), greater<int>());
    for(int i = 1; i < n; i++){
        if(d[i] < d[i-1]){
            ans++;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
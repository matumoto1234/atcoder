#include <bits/stdc++.h>
#define loop(i, n) for(int i = 0;i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, x, sum = 0;

    cin >> n >> x;

    vector<int> a(n);

    loop(i, n){
        cin >> a[i];
    }
    loop(i, n){
        if(x>>i & 1){
            sum += a[i];
        }
    }
    cout << sum << endl;
    return 0;
}
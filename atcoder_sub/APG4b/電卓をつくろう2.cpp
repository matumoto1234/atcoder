#include <bits/stdc++.h>
#define loop(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(void){
    int n,a;
    cin >> n >> a;

    vector<char> op(n);
    vector<int> b(n);

    loop(i, n){
        cin >> op[i] >> b[i];
        switch(op[i]){
            case '+':
                cout << i + 1<< ":" << a + b[i] << endl;
                a = a + b[i];
                break;
            case '-':
                cout << i + 1<< ":" << a - b[i] << endl;
                a = a - b[i];
                break;
            case '*':
                cout << i + 1<< ":" << a * b[i] << endl;
                a = a * b[i];
                break;
            case '/':
                if(b[i] == 0){
                    cout << "error" << endl;
                    return 0;
                }else{
                    cout << i + 1<< ":" << a / b[i] << endl;
                    a = a / b[i];
                }
                break;
        }
    }
    return 0;
}
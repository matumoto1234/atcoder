#include <bits/stdc++.h>
using namespace std;

typedef struct {
  int a, b;
} task;

bool b_cmp(const task& left, const task& right) {
  return left.b == right.b ? left.a < right.a : left.b < right.b;
}

int main() {
  int n;
  bool flg = true;
  cin >> n;
  vector<task> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i].a >> t[i].b;
  }
  sort(t.begin(), t.end(), b_cmp);
  int sum_time = 0;
  for (int i = 0; i < n; i++) {
    sum_time += t[i].a;
    if (sum_time > t[i].b) {
      flg = false;
      break;
    }
  }
  if (flg) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
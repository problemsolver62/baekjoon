#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;
    int nn;
    if (n >= m - n)
      nn = n;
    else
      nn = m - n;
    long long res = 1;
    for (int j = 1; j <= m - nn; j++)
      res = int(res * (m + 1 - j) / j);
    cout << res << '\n';
  }
}

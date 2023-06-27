#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int cnt = 0;
    int x1, y1, x2, y2, n;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    vector<int> cx(n);
    vector<int> cy(n);
    vector<int> cr(n);
    for (int j = 0; j < n; j++)
      cin >> cx[j] >> cy[j] >> cr[j];
    for (int j = 0; j < n; j++) {
      double sdis = pow(pow(x1 - cx[j], 2) + pow(y1 - cy[j], 2), 0.5);
      double edis = pow(pow(x2 - cx[j], 2) + pow(y2 - cy[j], 2), 0.5);
      double r = cr[j];
      if (sdis < r) {
        if (r < edis)
          cnt++;
      } else if (r > edis)
        cnt++;
    }
    cout << cnt << '\n';
  }
}

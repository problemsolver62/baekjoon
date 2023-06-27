#include <iostream>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int h, w, n;
    cin >> h >> w >> n;
    int a = n % h;
    int b = n / h + 1;
    if (a == 0) {
      a = h;
      b--;
    }
    if (b >= 10)
      cout << a << b << '\n';
    else
      cout << a << "0" << b << '\n';
  }
}

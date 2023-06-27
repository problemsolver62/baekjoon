#include <iostream>
using namespace std;
string board[51];
string wb[8] = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW",
                "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};
string bw[8] = {"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB",
                "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};
int wbf(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[x + i][y + j] != wb[i][j])
        cnt++;
    }
  }
  return cnt;
}
int bwf(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[x + i][y + j] != bw[i][j])
        cnt++;
    }
  }
  return cnt;
}
int main() {
  int n, m, res = 99999;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> board[i];
  }
  for (int i = 0; i + 8 <= n; i++) {
    for (int j = 0; j + 8 <= m; j++) {
      int tmp = min(wbf(i, j), bwf(i, j));
      if (tmp < res)
        res = tmp;
    }
  }
  cout << res;
}
